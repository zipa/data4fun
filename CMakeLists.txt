cmake_minimum_required(VERSION 2.8)

project(logan_v2)
add_definitions(-std=c++17)
enable_testing()

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

LINK_DIRECTORIES(
    /usr/local/lib
)

set(LIBRARIES
    boost_chrono
    boost_system
    boost_filesystem
    boost_thread
    pthread
)

set(SOURCES
    
)

set(HEADERS

)

add_executable(data4fun src/main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(data4fun ${LIBRARIES})

set(TESTSOURCES
    test/data4funtest.cpp
)

add_executable(d4ftest test/main.cpp ${TESTSOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(d4ftest gtest gmock ${LIBRARIES})