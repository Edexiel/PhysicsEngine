cmake_minimum_required(VERSION 3.24)
project(PhysicsEngine LANGUAGES CXX C)


set(CMAKE_CXX_STANDARD 20)

add_subdirectory(dependencies)

add_executable(${PROJECT_NAME} src/main.cpp include/PhysicsEngine/Scene/SceneManager.hpp include/PhysicsEngine/Scene/SceneBase.hpp src/Scene/SceneManager.cpp include/PhysicsEngine/Debug/Assert.hpp src/Object/Object.cpp include/PhysicsEngine/Object/Object.hpp src/Time/Timer.cpp include/PhysicsEngine/Time/Timer.hpp src/Scene/World.cpp include/PhysicsEngine/Scene/World.hpp src/System/System.cpp include/PhysicsEngine/System/System.hpp src/Scene/SceneBase.cpp src/Scene/SceneBouncingPoly.cpp include/PhysicsEngine/Scene/SceneBouncingPoly.hpp include/PhysicsEngine/Utils.hpp)

target_include_directories(${PROJECT_NAME} PRIVATE include/PhysicsEngine)
target_link_libraries(${PROJECT_NAME} raylib squirrelNoise fmt thread-pool)

include(CheckIPOSupported)
check_ipo_supported(RESULT supported OUTPUT error)

if (supported)
    message(STATUS "IPO / LTO enabled")
    set_property(TARGET PhysicsEngine PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else ()
    message(STATUS "IPO / LTO not supported: <${error}>")
endif ()