
mkdir build
cd build

cmake .. -G "Unix Makefiles"
cmake --build .

ctest
