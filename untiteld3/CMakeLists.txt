cmake_minimum_required(VERSION 3.3)

project(untitled3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(BOOST_ROOT CACHE PATH "boost_1_62_0")
FIND_PACKAGE(Boost COMPONENTS serialization system)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_executable(untitled3 main.cpp src/sockets/Socket.cpp src/sockets/Socket.h src/sockets/Udp.cpp src/sockets/Udp.h)

target_link_libraries(untitled3 ${Boost_LIBRARIES})







