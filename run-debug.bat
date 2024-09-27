cmake -G "Visual Studio 17 2022" -A x64 -B build -S src
cmake --build build --config Debug

cd build/Debug
gengine.exe

cd ../..