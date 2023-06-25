add_executable(TheFlower
    sources/Program.cpp
    sources/main.cpp
    headers/Program.h
)

target_include_directories(TheFlower PUBLIC
    headers/
)

target_link_libraries(TheFlower PUBLIC
    sfml-graphics sfml-system sfml-audio sfml-window sfml-main Utils Core
)

file(GLOB dlls "${PROJECT_BINARY_DIR}/dependencies/SFML-2.6.0/lib/*.dll")
foreach(num IN LISTS dlls)
    add_custom_command(TARGET TheFlower PRE_LINK
        COMMAND ${CMAKE_COMMAND} -E copy ${num} ${PROJECT_BINARY_DIR}/flower/program
    )
    message(STATUS ${num} " was copied to: " ${PROJECT_BINARY_DIR}/flower/program)
endforeach()

add_custom_command(TARGET TheFlower PRE_BUILD
   COMMAND ${CMAKE_COMMAND} -E make_directory  ${PROJECT_BINARY_DIR}/flower/program/assets
   COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/assets ${PROJECT_BINARY_DIR}/flower/program/assets
)
message(STATUS "Assets directory was copied to: " ${PROJECT_BINARY_DIR}/flower/program/assets)

add_custom_command(TARGET TheFlower PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${PROJECT_BINARY_DIR}/flower/program/save
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/save ${PROJECT_BINARY_DIR}/flower/program/save
)
message(STATUS "Save directory was copied to: " ${PROJECT_BINARY_DIR}/flower/program/save)

add_custom_command(TARGET TheFlower PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/dependencies/SFML-2.6.0/extlibs/bin/x86/openal32.dll ${PROJECT_BINARY_DIR}/flower/program
)
message(STATUS "openal32.dll was copied to: " ${PROJECT_BINARY_DIR}/flower/program)
