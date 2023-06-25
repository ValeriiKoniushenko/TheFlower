add_library(
    Core STATIC
    headers/DefeatGameState.h
    headers/GameStateBase.h
    headers/MainMenuGameState.h
    headers/SceneObject.h
    headers/GameProcessGameState.h

    sources/DefeatGameState.cpp
    sources/GameStateBase.cpp
    sources/MainMenuGameState.cpp
    sources/SceneObject.cpp
    sources/GameProcessGameState.cpp
)

target_include_directories(
    Core PUBLIC
    headers/
)

target_link_libraries(Core PUBLIC
    Utils sfml-graphics Player Map Flower Snake Ui
)