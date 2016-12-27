cmake_minimum_required(VERSION 3.6)
project(newHope)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
#include_directories(googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp BFSPoint.cpp BFSPoint.h Bfs.cpp Bfs.h Cab.cpp Cab.h Driver.cpp Driver.h GameFlow.cpp GameFlow.h Grid.cpp Grid.h LuxuryCab.cpp LuxuryCab.h Node.cpp Node.h Passenger.cpp Passenger.h Point.cpp Point.h StandartCab.cpp StandartCab.h TaxiCentre.cpp TaxiCentre.h TripInfo.cpp TripInfo.h Test/PointTest.cpp Test/GridTest.cpp Test/BfsTest.cpp Test/StandartCabTest.cpp Test/TripInfoTest.cpp Test/LuxuryCabTest.cpp Test/DriverTest.cpp Test/BFSPointTest.cpp Test/PassengerTest.cpp Test/GameFlowTest.cpp Test/TaxiCentreTest.cpp)
add_executable(newHope ${SOURCE_FILES})
target_link_libraries(newHope gtest gtest_main)
