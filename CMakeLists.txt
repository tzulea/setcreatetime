cmake_minimum_required(VERSION 3.15)

project(setcreatetime LANGUAGES C CXX VERSION 1.0.0) 
find_library(COREFOUNDATION_FRAMEWORK NAMES CoreFoundation)
message( "framework: ${COREFOUNDATION_FRAMEWORK}" )

add_executable(setcreatetime main.cpp)
target_link_libraries(${PROJECT_NAME} ${COREFOUNDATION_FRAMEWORK})
