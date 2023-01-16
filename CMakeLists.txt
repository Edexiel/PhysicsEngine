cmake_minimum_required(VERSION 3.24)
project(PhysicsEngine LANGUAGES CXX C)


set(CMAKE_CXX_STANDARD 20)

add_subdirectory(dependencies)

add_executable(${PROJECT_NAME}
        src/main.cpp

        #Core
#        src/World.cpp include/PhysicsEngine/World.hpp
        src/Object/Object.cpp include/PhysicsEngine/Object/Object.hpp

        # Scenes
        src/Scene/Scene.cpp include/PhysicsEngine/Scene/Scene.hpp
        src/Scene/SceneManager.cpp include/PhysicsEngine/Scene/SceneManager.hpp
        src/Scene/SceneBouncingPoly.cpp include/PhysicsEngine/Scene/SceneBouncingPoly.hpp
        src/Scene/SceneDebug.cpp include/PhysicsEngine/Scene/SceneDebug.hpp

        #Tools
        include/PhysicsEngine/Tools/RandomUtils.hpp
        src/Tools/Maths.cpp include/PhysicsEngine/Tools/Maths.hpp
        src/Time/Timer.cpp include/PhysicsEngine/Time/Timer.hpp
        include/PhysicsEngine/Debug/Assert.hpp

        #Components
        src/Components/Transform.cpp include/PhysicsEngine/Components/Transform.hpp
        src/Components/RigidBody.cpp include/PhysicsEngine/Components/RigidBody.hpp
        src/Components/Shape.cpp include/PhysicsEngine/Components/Shape.hpp

        #Systems
        src/System/System.cpp include/PhysicsEngine/System/System.hpp
        src/System/InputSystem.cpp include/PhysicsEngine/System/InputSystem.hpp
        src/System/DrawSystem.cpp include/PhysicsEngine/System/DrawSystem.hpp
        src/System/AABBGenerationSystem.cpp include/PhysicsEngine/System/AABBGenerationSystem.hpp
        src/System/TransformSystem.cpp include/PhysicsEngine/System/TransformSystem.hpp
        src/System/BroadPhaseSystem.cpp include/PhysicsEngine/System/BroadPhaseSystem.hpp include/PhysicsEngine/System/NarrowPhaseSystem.hpp src/System/NarrowPhaseSystem.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include/PhysicsEngine)
target_link_libraries(${PROJECT_NAME} raylib fmt flecs)


# Optimizations
#include(CheckIPOSupported)
#check_ipo_supported(RESULT supported OUTPUT error)
#
#if (supported)
#    message(STATUS "IPO / LTO enabled")
#    set_property(TARGET PhysicsEngine PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
#else ()
#    message(STATUS "IPO / LTO not supported: <${error}>")
#endif ()