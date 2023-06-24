add_library(
	Flower STATIC
	headers/Flower.h
	headers/FlowerConfig.h

	sources/Flower.cpp
	sources/FlowerConfig.cpp
)

target_include_directories(
	Flower PUBLIC
	headers/
)

target_link_libraries(Flower PUBLIC Utils Core sfml-graphics)