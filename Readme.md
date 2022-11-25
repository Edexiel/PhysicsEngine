# Physics Engine - Guillaume Nisi

## Description

2D physics engine using Sweep and prune broadphase.

Broadphase algorithm and AABB collision

Polygons in purple are detected as potential collision
Polygons in black not
AABB in green means there is no collisions with another AABB
AABB in red means there is a collision with another AABB


Sweep and prune algorithm :
```cpp
// /src/Scene/World.cpp
// /include/PhysicsEngine/Scene/World.hpp

void GetCollidingPairsToCheck(std::vector<std::tuple<Object &, Object &>> &pairsToCheck);
bool CheckCollisionAABB(const Rectangle& a, const Rectangle&b) const;
```

main program and scene config : 
```cpp
// src/main.cpp
Vector2 screenSize{.x=1280, .y=720};

RandomPolyParams params
{
.minPoints = 3,
.maxPoints = 8,
.minRadius = 10.0f,
.maxRadius = 35.0f,
.minBounds = Vector2{.x=50, .y= 50},
.maxBounds = Vector2{.x=screenSize.x - 50, .y=screenSize.y - 50},
.minSpeed = 1.0f,
.maxSpeed = 3.0f
};


SceneManager sceneManager{world};
sceneManager.AddScene<SceneBouncingPoly>(world, 50, params);
```
## Builds

### Linux

`/build/linux/Release/PhysicsEngine`

### Windows

`/build/Windows/Release/PhysicsEngine.exe`

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

[//]: # (## State)

[//]: # ()
[//]: # (### What works :)

[//]: # ()
[//]: # (- AABB)

[//]: # ()
[//]: # (### What doesn't)

[//]: # ()
[//]: # (- other stuff )