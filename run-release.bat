cmake -G "Visual Studio 17 2022" -A x64 -B build -S .
cmake --build build --config Release

cd build/Release
gengine.exe

cd ../..