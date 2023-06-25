add_library(
	Utils STATIC
	headers/UMath.h
	headers/Serializer.h

	sources/UMath.cpp
	sources/Serializer.cpp
)

target_include_directories(
	Utils PUBLIC
	headers/
	${PROJECT_SOURCE_DIR}/dependencies/boost_1_80_0
)

target_link_libraries(Utils PUBLIC sfml-system)