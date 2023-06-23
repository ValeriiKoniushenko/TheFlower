add_executable(Tests
    Serializer.cpp
    main.cpp
    ${PROJECT_SOURCE_DIR}/dependencies/googletest/src/gtest-all.cc
)

target_include_directories(Tests PRIVATE
    ${PROJECT_SOURCE_DIR}/dependencies/googletest/
    ${PROJECT_SOURCE_DIR}/dependencies/googletest/include/
    ${PROJECT_SOURCE_DIR}/dependencies/googletest/src/
)