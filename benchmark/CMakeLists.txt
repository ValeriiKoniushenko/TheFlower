add_executable(Benchmark
    Serializer.cpp
)

target_link_libraries(Benchmark PUBLIC
    Utils benchmark::benchmark
)

add_custom_command(TARGET Benchmark PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/dependencies/google-benchmark/src/benchmark.dll ${PROJECT_BINARY_DIR}/benchmark/
        )
message(STATUS "openal32.dll was copied to: " ${PROJECT_BINARY_DIR}/flower/program)
