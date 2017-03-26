
# Installing header-only::example-dependency
example-dependency can be installed in three ways :

* [Copy paste in your project](#copy-paste-in-your-project)
* [Install](#install)
* [Install without dependencies](#install-without-dependencies)

## Copy paste in your project
1. Copy this folder in your project
2. Add the following to your include path :

### GCC / Clang / MSVC
```
-I example-dependency/ \
-I example-dependency/deps/boostorg/assert/include/ \
-I example-dependency/deps/boostorg/config/include/ \
-I example-dependency/deps/boostorg/core/include/ \
-I example-dependency/deps/boostorg/detail/include/ \
-I example-dependency/deps/boostorg/exception/include/ \
-I example-dependency/deps/boostorg/function/include/ \
-I example-dependency/deps/boostorg/function_types/include/ \
-I example-dependency/deps/boostorg/functional/include/ \
-I example-dependency/deps/boostorg/fusion/include/ \
-I example-dependency/deps/boostorg/integer/include/ \
-I example-dependency/deps/boostorg/move/include/ \
-I example-dependency/deps/boostorg/mpl/include/ \
-I example-dependency/deps/boostorg/predef/include/ \
-I example-dependency/deps/boostorg/preprocessor/include/ \
-I example-dependency/deps/boostorg/static_assert/include/ \
-I example-dependency/deps/boostorg/throw_exception/include/ \
-I example-dependency/deps/boostorg/tuple/include/ \
-I example-dependency/deps/boostorg/type_index/include/ \
-I example-dependency/deps/boostorg/type_traits/include/ \
-I example-dependency/deps/boostorg/typeof/include/ \
-I example-dependency/deps/boostorg/utility/include/ \
-I example-dependency/deps/nlohmann/json/src/ \
```

## Install
Install the library
```sh
mkdir build/ && cd build/
cmake ..
make install
```

You can tweak destination with `-DCMAKE_INSTALL_PREFIX=/install/path` to change the default `/usr/local`.

## If you use CMake :
```cmake
find_package(example-dependency REQUIRED)
add_executable(app your_code.cpp)
target_link_libraries(app header-only::example-dependency)
```

## If you don't use CMake : 
Add to your include path : 
```
INSTALL_PREFIX/include/example-dependency/deps/
INSTALL_PREFIX/include/
```

## Install without dependencies
Install the library
```sh
mkdir build/ && cd build/
cmake .. -DINGLUED=OFF
make install
```

This library was built with [`#inglued <>`](https://github.com/header-only/inglued) therefore it forwards dependencies with it, but you might prefer the use of your own deps, therefore simply disable them via `INGLUED=OFF`.
