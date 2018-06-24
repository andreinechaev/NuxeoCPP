cmake_minimum_required(VERSION 3.10)
project(nuxeo_cpp_client)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "src/**/*.cpp")
file(GLOB HEADERS "src/**/*.h")
add_executable(nuxeo_cpp_client main.cpp ${SOURCES} ${HEADERS})

target_link_libraries(nuxeo_cpp_client ${CONAN_LIBS})