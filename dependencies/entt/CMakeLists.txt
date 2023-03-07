# flecs ECS library
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.11.1
)
FetchContent_MakeAvailable(entt)

set_property(TARGET flecs PROPERTY C_STANDARD 99)
set_property(TARGET flecs_static PROPERTY C_STANDARD 99)

target_compile_features(flecs PUBLIC c_std_99)
target_compile_features(flecs_static PUBLIC c_std_99)