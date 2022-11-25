# Physics Engine - Guillaume Nisi

## Description

2D physics engine using Sweep and prune broadphase.

Broadphase algorithm and AABB collision

`/src/Scene/World.cpp`

```cpp
// /src/Scene/World.cpp
// /include/PhysicsEngine/Scene/World.hpp

void GetCollidingPairsToCheck(std::vector<std::tuple<Object &, Object &>> &pairsToCheck);
bool CheckCollisionAABB(const Rectangle& a, const Rectangle&b) const;
```

## Builds

### Linux

`/build/linux/PhysicsEngine`

### Windows

`/build/linux/PhysicsEngine.exe`

## How to compile

Compiled and tested on GCC

### Dependencies

- CMake
- (optional) Ninja
- (optional) GCC
- (optional) Clang

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