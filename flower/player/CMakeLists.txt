add_library(
	Player STATIC
	headers/Player.h
	sources/Player.cpp
)

target_include_directories(
	Player PUBLIC
	headers/
)

target_link_libraries(Player PUBLIC Utils)