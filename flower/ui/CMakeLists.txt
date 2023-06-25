add_library(
    Ui STATIC
    headers/Animation.h
    headers/Button.h
    headers/Canvas.h
    headers/Widget.h

    sources/Animation.cpp
    sources/Button.cpp
    sources/Canvas.cpp
    sources/Widget.cpp
)

target_include_directories(
    Ui PUBLIC
    headers/
)

target_link_libraries(Ui PUBLIC
    Utils sfml-graphics Player Map Flower Snake
)