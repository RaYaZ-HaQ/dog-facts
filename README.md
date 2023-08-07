# DogFacts

Get random dog facts in your command line

## How to build

This project depends on `libcpp-httplib`. Install the library using your system's package manager.

For Debian/Ubuntu:

```[bash]
    sudo apt install libcpp-httplib-dev
```

### Compilation Instructions

It is recommended to use `clang++` instead of `g++`.

#### Configure

```
cmake -DCMAKE_CXX_COMPILER=clang++ -S . -B build
```

#### Build

```
cmake --build build
```
