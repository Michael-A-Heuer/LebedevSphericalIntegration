cmake_minimum_required(VERSION 3.5)
enable_testing()

FILE(GLOB TEST_SOURCE_FILES *)

include_directories(
        sphere_lebedev_rule
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        )

add_library(JBurkardtReference STATIC
        sphere_lebedev_rule/sphere_lebedev_rule.h
        sphere_lebedev_rule/sphere_lebedev_rule.cpp
        )

add_executable("${PROJECT_NAME}Tests" ${TEST_SOURCE_FILES})

target_link_libraries("${PROJECT_NAME}Tests"
        ${PROJECT_NAME}
        JBurkardtReference
        gtest gtest_main
        pthread
        )