add_library(
	Snake STATIC
	headers/Snake.h
	headers/SnakeConfig.h

	sources/Snake.cpp
	sources/SnakeConfig.cpp
)

target_include_directories(
	Snake PUBLIC
	headers/
)

target_link_libraries(Snake PUBLIC Utils Core sfml-graphics)