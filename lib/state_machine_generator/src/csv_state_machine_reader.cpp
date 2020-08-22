#include "csv_state_machine_reader.h"
#include <fstream>
#include <map>
#include <sstream>

namespace state_machine
{
namespace
{
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
    
}
CsvStateMachineReader::CsvStateMachineReader() noexcept
{
}

CsvStateMachineReader::~CsvStateMachineReader()
{
}

const std::vector<std::string> CsvStateMachineReader::GetTokens(const std::string& state_line, const char& delim) noexcept
{
    std::vector<std::string> tokens;
    std::stringstream state_line_stream(state_line); 
    std::string token; 
    while(getline(state_line_stream, token, delim)) 
    {
        trim(token);
        tokens.push_back(token); 
    }
    return tokens;
}

bool CsvStateMachineReader::OpenFile(const std::string& file_name) noexcept
{
    if(file_name.empty())
    {
        return false;
    }
    std::ifstream csv_state_file{file_name};
    
    state_manager_ = std::make_shared<StateManager>();
    using StateMap = std::map<std::string,std::vector<std::string>>;
    StateMap intermediate_state_map;
    StateMap final_state_map;
    
    std::string state_line;
    while( std::getline( csv_state_file, state_line) )
    {
        if ( state_line.size())
        {
            if ( state_line.find(">") != std::string::npos)
            {
                auto tokens = GetTokens(state_line, '>');
                if ( tokens.size())
                {
                    auto main_state{tokens[0]};
                    state_manager_->AddState(main_state,true);
                    tokens.erase(tokens.begin());
                    final_state_map[main_state] = tokens;
                } 
            }
            else
            {
                auto tokens = GetTokens(state_line, ',');
                if ( tokens.size())
                {
                    auto main_state{tokens[0]};
                    state_manager_->AddState(main_state,false);
                    tokens.erase(tokens.begin());
                    intermediate_state_map[main_state] = tokens;
                } 
            }
        }
    }

    for(const auto& value_pair: intermediate_state_map)
    {
        auto main_state_ptr = state_manager_->GetState(value_pair.first);
        if (main_state_ptr)
        {
            for(const auto& state: value_pair.second )
            {
                auto state_ptr = state_manager_->GetState(state);
                if (state_ptr)
                {
                    main_state_ptr->AddNextState(state_ptr);
                }
            }
        }
    }

    for(const auto& value_pair: final_state_map)
    {
        if ( value_pair.second.size() == 1 )
        {
            auto state_ptr = state_manager_->GetState(value_pair.first);
            if (state_ptr)
            {
                auto final_state_ptr = std::dynamic_pointer_cast<FinalState>(state_ptr);
                if ( final_state_ptr)
                {
                    final_state_ptr->SetFinalIntent(value_pair.second[0]);
                }
            }
        }
    }
    csv_state_file.close();
    return true;
}

StateManager::Ptr CsvStateMachineReader::GetStateManager() const noexcept
{
    return state_manager_;
}
} // state_machine
