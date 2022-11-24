# Physics Engine - Guillaume Nisi

## Dependencies

- CMake
- (optional) Ninja
- (optional) GCC
- (optional) Clang

## How to compile

Compiled and tested on GCC

### Use CLion

There are two profiles shared with the project:

- debug
- release

You can compile the project with both inside Clion

### Manual build

#### 1 - Make build directory

##### Debug

```shell
mkdir cmake-build-debug
```

##### Release

```shell
mkdir cmake-build-release
```

### 2 - Configure project

#### Debug

```shell
cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
```

##### Release

```shell
cmake -S . -B cmake-build-release  -DCMAKE_BUILD_TYPE=Release
```

### 3 - Build

#### Debug

```shell
mkdir build/Debug
cmake --build cmake-build-debug -j12
```
##### Release

```shell
mkdir build/Release
cmake --build cmake-build-release -j12
```

## State

### What works :

- Stuff

### What doesn't

- other stuff 