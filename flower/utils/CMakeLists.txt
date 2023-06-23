add_library(
	Utils STATIC
	headers/Serializer.h
	sources/Serializer.cpp
)

target_include_directories(
	Utils PUBLIC
	headers/
)