add_library(
	Flower STATIC
	headers/Flower.h
	headers/FlowerConfig.h
	headers/FlowerPool.h

	sources/Flower.cpp
	sources/FlowerConfig.cpp
	sources/FlowerPool.cpp
)

target_include_directories(
	Flower PUBLIC
	headers/
)

target_link_libraries(Flower PUBLIC Utils Core sfml-graphics)