add_executable(TheFlower
    sources/Program.cpp
    sources/main.cpp
    headers/Program.h
)

target_include_directories(TheFlower PUBLIC
    headers/
)

target_link_libraries(TheFlower PUBLIC
    sfml-graphics sfml-system sfml-audio sfml-window sfml-main Utils
)

file(GLOB dlls "${PROJECT_BINARY_DIR}/dependencies/SFML-2.6.0/lib/*.dll")

foreach(num IN LISTS dlls)
    add_custom_command(TARGET TheFlower PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${num} ${PROJECT_BINARY_DIR}/flower/program
            )
endforeach()