cmake_minimum_required(VERSION 3.5)

project(LebedevSphericalIntegration CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} INTERFACE)

if(NOT TARGET eigen AND NOT ${EIGEN3_FOUND})
    include(cmake/DownloadEigen.cmake)
endif()
if(TARGET eigen)
    target_link_libraries(${PROJECT_NAME} eigen)
endif()

if(NOT TARGET gtest)
    include(cmake/DownloadGoogleTest.cmake)
endif()

target_include_directories(${PROJECT_NAME} INTERFACE include/)

add_subdirectory(tests)
