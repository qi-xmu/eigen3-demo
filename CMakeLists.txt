cmake_minimum_required(VERSION 3.7)
project(eigen3_demo)


find_package(Eigen3 REQUIRED)
find_package(g2o REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(${PROJECT_NAME} src/main.cc)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    Eigen3::Eigen
)