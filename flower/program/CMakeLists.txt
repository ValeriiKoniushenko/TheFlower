add_executable(TheFlower
    sources/Program.cpp
    headers/Program.h
    sources/main.cpp
)

target_include_directories(TheFlower PUBLIC
    headers/
)

target_link_libraries(TheFlower PUBLIC
    sfml-graphics
)