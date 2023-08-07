cmake_minimum_required(VERSION 3.7...3.27)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(DogFacts VERSION 0.1
	DESCRIPTION "Get a random dog fact from the command line."
	LANGUAGES CXX)

add_executable(dogfacts src/main.cpp)
target_include_directories(dogfacts PRIVATE external)
target_link_libraries(dogfacts PRIVATE cpp-httplib)
