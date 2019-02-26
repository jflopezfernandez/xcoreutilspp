
# xcoreutils

This is a top-to-bottom rewrite of the GNU coreutils library of Unix utilities. The purpose of this rewrite is to clean up the code base and simplify cross-compatibility of the scripts by adhering to the C++ standard library as much as possible. When the C++ standard library is not enough, the Boost libraries are used. The Boost program options module is also extensively used to parse command-line arguments in a clean, cross-compatible way.

# Building

Instructions for building the packages. Note that the instructions for building on Windows presuppose vcpkg. Vcpkg is not required in and of itself, but configuration is much less straightforward and is not covered here.

## Windows

Note that I'm specifying the `host=x64` option; without it, Visual Studio defaults to using the x86 host toolchain.

```
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -Thost=x64 . --target ../xcoreutils
cmake --build .
```

## Linux

I'm using Manjaro Linux, in which the default C++ compiler is GCC 8.2.1, which supports the C++17 standard.

```
cmake ../xcoreutils
cmake --build .
```
