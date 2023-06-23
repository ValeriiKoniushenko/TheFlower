add_library(
	Snake STATIC
	headers/Snake.h
	sources/Snake.cpp
)

target_include_directories(
	Snake PUBLIC
	headers/
)

target_link_libraries(Snake PUBLIC Utils)