add_library(
	Map STATIC
	headers/Map.h
	sources/Map.cpp
)

target_include_directories(
	Map PUBLIC
	headers/
)

target_link_libraries(Map PUBLIC Utils)