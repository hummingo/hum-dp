cmake_minimum_required(VERSION 3.10)

project(hum-dp)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "open compile_command.json for clangd")
# option(CMAKE_EXPORT_COMPILE_COMMANDS "open compile_command.json for clangd" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_compile_definitions(DEBUG)

include(utils)

link_directories(${CMAKE_BINARY_DIR})

# add all subdirectory as shared library
set(PATTERN_SHARED_LIBRARY "")
set(SRC_PATH "${CMAKE_SOURCE_DIR}/src")
GET_PATTREN_PATH(${SRC_PATH} PATTERNS)
foreach(ITEM ${PATTERNS})
    string(REGEX REPLACE ".+/(.+)" "\\1" PATTERN_NAME ${ITEM})
    file(GLOB ${PATTERN_NAME}_SRC_LISTS "${SRC_PATH}/${ITEM}/*.cpp")
    list(LENGTH ${PATTERN_NAME}_SRC_LISTS LEN)
    if (${LEN} GREATER "0")
        include_directories("${SRC_PATH}/${ITEM}")
        add_library(${PATTERN_NAME} SHARED ${${PATTERN_NAME}_SRC_LISTS})
        list(APPEND PATTERN_SHARED_LIBRARY ${PATTERN_NAME})
    endif()
endforeach()

add_executable("${PROJECT_NAME}" "${CMAKE_SOURCE_DIR}/main.cpp")

target_link_libraries("${PROJECT_NAME}"
    ${PATTERN_SHARED_LIBRARY})
