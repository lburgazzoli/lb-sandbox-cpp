project (lb-sandbox-cpp)

cmake_minimum_required (VERSION 2.8 FATAL_ERROR)


if(UNIX)
    add_definitions(-DOS_UNIX)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fexceptions -pthread -g")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-Os")
endif()

if(APPLE)
    add_definitions(-DOS_DARWIN)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fexceptions -pthread -g")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-Os")
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_definitions(-DOS_LINUX)
    add_definitions(-D_GNU_SOURCE)
endif()

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_SOURCE_DIR}/cmake/Modules/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/cmake-build/binaries")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/cmake-build/lib")

################################################################################
# POCO
################################################################################

find_package(Poco)
if(Poco_FOUND)
    INCLUDE_DIRECTORIES(${Poco_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Poco_LIBRARY_DIRS})

    MESSAGE(STATUS "Poco INCLUDE_DIRS: ${Poco_INCLUDE_DIRS}")
    MESSAGE(STATUS "Poco LIBRARY_DIRS: ${Poco_LIBRARY_DIRS}")
endif()

################################################################################
# BOOST
################################################################################

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS system REQUIRED)
find_package(Boost COMPONENTS date_time REQUIRED)
find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(Boost COMPONENTS serialization REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    #add_executable(foo foo.cc)
    #target_link_libraries(foo ${Boost_LIBRARIES})
endif()

################################################################################
# SUBPROJECTS
################################################################################

set(COMMON_PATH  "${CMAKE_SOURCE_DIR}/sbox-common" )
set(OPENHFT_PATH "${CMAKE_SOURCE_DIR}/sbox-openhft")

include_directories(${COMMON_PATH}/src)
include_directories(${OPENHFT_PATH}/src)

add_subdirectory (sbox-common)
add_subdirectory (sbox-openhft)
add_subdirectory (sbox-openhft-examples)
