project(sbox-openhft-examples)

INCLUDE_DIRECTORIES(src)

ADD_EXECUTABLE(
    openhft_ex_affinity
    src/openhft/AffinityExample.cpp)

target_link_libraries(
    openhft_ex_affinity
    sbox-openhft)