cmake_minimum_required(VERSION 3.5)
enable_testing()

FILE(GLOB TEST_SOURCE_FILES *)

add_library(sphere_lebedev_rule STATIC
        sphere_lebedev_rule/sphere_lebedev_rule.h
        sphere_lebedev_rule/sphere_lebedev_rule.cpp
        )

add_executable("${PROJECT_NAME}Tests" ${TEST_SOURCE_FILES} main.cpp)

include_directories(
        sphere_lebedev_rule
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
)

target_link_libraries("${PROJECT_NAME}Tests"
        ${PROJECT_NAME}
        sphere_lebedev_rule
        gtest
        pthread
        )
