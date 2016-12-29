cmake_minimum_required(VERSION 3.6)
project(newHope)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
set(BOOST_ROOT CACHE PATH "boost_1_62_0")
FIND_PACKAGE(Boost COMPONENTS serialization system)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()
#include_directories(googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES BFSPoint.cpp BFSPoint.h Bfs.cpp Bfs.h Cab.cpp Cab.h Driver.cpp Driver.h GameFlow.cpp GameFlow.h Grid.cpp Grid.h LuxuryCab.cpp LuxuryCab.h Node.cpp Node.h Passenger.cpp Passenger.h Point.cpp Point.h StandartCab.cpp StandartCab.h TaxiCentre.cpp TaxiCentre.h TripInfo.cpp TripInfo.h Test/PointTest.cpp Test/GridTest.cpp Test/BfsTest.cpp Test/StandartCabTest.cpp Test/TripInfoTest.cpp Test/LuxuryCabTest.cpp Test/DriverTest.cpp Test/BFSPointTest.cpp Test/PassengerTest.cpp Test/GameFlowTest.cpp Test/TaxiCentreTest.cpp Udp.cpp Udp.h Socket.cpp Socket.h untiteld3/main.cpp)
add_executable(newHope ${SOURCE_FILES})
target_link_libraries(newHope gtest gtest_main ${Boost_LIBRARIES})






