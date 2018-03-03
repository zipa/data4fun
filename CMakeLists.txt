cmake_minimum_required(VERSION 2.8)

project(logan_v2)
add_definitions(-std=c++17)
enable_testing()

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory (subprojects)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    /home/boris/other/spdlog/include/
	${PROJECT_SOURCE_DIR}/external/glfw-3.1.2/include/
	${PROJECT_SOURCE_DIR}/external/glm-0.9.7.1/
	${PROJECT_SOURCE_DIR}/external/glew-1.13.0/include/
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
    ${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

set(SOURCES
    src/spdlogwrap.cpp
    src/GLhelper.cpp
)

set(HEADERS
    include/spdlogwrap.h
    include/GLhelper.h
)

add_executable(data4fun src/main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(data4fun ${LIBRARIES})

set(TESTSOURCES
    test/data4funtest.cpp
)

add_executable(d4ftest test/main.cpp ${TESTSOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(d4ftest gtest gmock ${LIBRARIES})

add_test(NAME Test_dataa4fun COMMAND ${EXECUTABLE_OUTPUT_PATH}/d4ftest)