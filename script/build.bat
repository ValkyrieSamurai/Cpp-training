@echo off
pushd .

if not exist build (
     md build
)

cd build
cmake -G"MinGW Makefiles" C:/Users/86137/Desktop/c++/cpp-training
mingw32-make.exe

popd