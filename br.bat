
rmdir /s/q build
mkdir build
cd build
where cmake
cmake -G"MinGW Makefiles" ..
mingw32-make.exe
cd src
win_bash.exe
cd ..