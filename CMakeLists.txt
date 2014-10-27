project (lb-sandbox-cpp)

cmake_minimum_required (VERSION 2.8.12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS system REQUIRED)
find_package(Boost COMPONENTS date_time REQUIRED)


if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    #add_executable(foo foo.cc)
    #target_link_libraries(foo ${Boost_LIBRARIES})
endif()


add_subdirectory (sbox-common)
add_subdirectory (sbox-chronicle)
