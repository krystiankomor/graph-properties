cmake_minimum_required(VERSION 3.20)
project(project1)

set(CMAKE_CXX_STANDARD 17)

#add_executable(project1 main.cpp)

set(SOURCE_FILES main.cpp)

add_executable(DateConverter_run ${SOURCE_FILES})
include_directories(DateConverter_lib)
add_subdirectory(DateConverter_lib)

target_link_libraries(DateConverter_run DateConverter_lib)

add_executable(GraphProperties_run GraphProperties/main.cpp)
include_directories(GraphProperties)
add_subdirectory(GraphProperties)

target_link_libraries(GraphProperties_run GraphProperties)

add_subdirectory(Google_tests)
