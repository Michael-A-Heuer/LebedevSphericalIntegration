cmake_minimum_required(VERSION 3.5)

project(LebedevSphericalIntegration CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} INTERFACE)

if(NOT TARGET eigen)
    include(cmake/DownloadEigen.cmake)
endif()

if(NOT TARGET gtest)
    include(cmake/DownloadGoogleTest.cmake)
endif()

target_link_libraries(${PROJECT_NAME} INTERFACE eigen)

target_include_directories(${PROJECT_NAME} INTERFACE include/)

add_subdirectory(tests)
