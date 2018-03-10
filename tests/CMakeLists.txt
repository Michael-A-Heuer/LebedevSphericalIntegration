cmake_minimum_required(VERSION 3.5)
enable_testing()

FILE(GLOB TEST_SOURCE_FILES *)

include_directories(
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        )

add_executable("${PROJECT_NAME}Tests" ${TEST_SOURCE_FILES})

target_link_libraries("${PROJECT_NAME}Tests"
        ${PROJECT_NAME}
        #gmock gmock_main
        gtest gtest_main
        pthread
        )
