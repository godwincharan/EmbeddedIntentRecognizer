#include <gtest/gtest.h>
#include <string_utils.h>

TEST(StringUtilsTest, LeftTrim)
{
    using namespace utils;
    std::string str{"  state"};
    ltrim(str);
    EXPECT_EQ(str, "state");
}

TEST(StringUtilsTest, LeftTrimEmpty)
{
    using namespace utils;
    std::string str{"  "};
    ltrim(str);
    EXPECT_EQ(str, "");
}

TEST(StringUtilsTest, RightTrim)
{
    using namespace utils;
    std::string str{"state  "};
    rtrim(str);
    EXPECT_EQ(str, "state");
}

TEST(StringUtilsTest, RightTrimEmpty)
{
    using namespace utils;
    std::string str{"  "};
    rtrim(str);
    EXPECT_EQ(str, "");
}


TEST(StringUtilsTest, Trim)
{
    using namespace utils;
    std::string str{"state  "};
    trim(str);
    EXPECT_EQ(str, "state");
}

TEST(StringUtilsTest, TrimEmpty)
{
    using namespace utils;
    std::string str{"  "};
    trim(str);
    EXPECT_EQ(str, "");
}
