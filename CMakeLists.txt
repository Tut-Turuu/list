cmake_minimum_required(VERSION 3.16.3)


set(PROJECT_NAME list)


project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS off) 
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/" "src/")

set(
    SOURCES
    main.cpp
    src/list.cpp
)

set(
    HEADER
    inc/list.hpp
)


add_executable(use_list ${SOURCES} ${HEADER})