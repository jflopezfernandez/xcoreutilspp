@ECHO OFF

mkdir xcoreutils-build
cd xcoreutils-build
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -Thost=x64 . --target ../xcoreutils
cmake --build .
