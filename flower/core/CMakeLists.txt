add_library(
        Core STATIC
        headers/Button.h
        headers/Canvas.h
        headers/Widget.h
        headers/GameStateBase.h
        headers/MainMenuGameState.h
        headers/GameProcessGameState.h

        sources/Button.cpp
        sources/Canvas.cpp
        sources/Widget.cpp
        sources/GameStateBase.cpp
        sources/MainMenuGameState.cpp
        sources/GameProcessGameState.cpp
)

target_include_directories(
        Core PUBLIC
        headers/
)

target_link_libraries(Core PUBLIC
        Utils sfml-graphics
        )