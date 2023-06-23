add_library(
	Utils STATIC
	headers/Serializer.h
	sources/Serializer.cpp
)

target_include_directories(
	Utils PUBLIC
	headers/
	${PROJECT_SOURCE_DIR}/dependencies/boost_1_80_0
)