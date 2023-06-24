add_library(
	Snake STATIC
	headers/Snake.h
	headers/SnakeConfig.h
	headers/SnakePool.h

	sources/Snake.cpp
	sources/SnakeConfig.cpp
	sources/SnakePool.cpp
)

target_include_directories(
	Snake PUBLIC
	headers/
)

target_link_libraries(Snake PUBLIC Utils Core sfml-graphics)