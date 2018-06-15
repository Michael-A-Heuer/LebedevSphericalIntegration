cmake_minimum_required(VERSION 3.5)

project(LebedevSphericalIntegration CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} INTERFACE)

if (DEFINED BUILD_EIGEN AND (${BUILD_EIGEN}))
    message("BUILD_EIGEN build eigen is ON.")
    if(NOT TARGET eigen)
        message("Start building eigen...")
        include(cmake/DownloadEigen.cmake)
    endif()
    target_link_libraries(${PROJECT_NAME} INTERFACE eigen)
else()
    message("BUILD_EIGEN build eigen is undefined or OFF. Trying to find Eigen3...")
    find_package(Eigen3 REQUIRED)
    include_directories(${EIGEN3_INCLUDE_DIR})
endif()

if(NOT TARGET gtest)
    include(cmake/DownloadGoogleTest.cmake)
endif()

target_include_directories(${PROJECT_NAME} INTERFACE include/)

add_subdirectory(tests)
