add_library(
	Core STATIC
	headers/GameStateBase.h
	headers/MainMenuGameState.h
	sources/GameStateBase.cpp
	sources/MainMenuGameState.cpp
)

target_include_directories(
	Core PUBLIC
	headers/
)

target_link_libraries(Core PUBLIC Utils)