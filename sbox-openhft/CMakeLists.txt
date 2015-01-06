project(sbox-openhft)

INCLUDE_DIRECTORIES(src)
ADD_LIBRARY(
  sbox-openhft
  src/openhft/exceptions.cpp
  src/openhft/affinity.cpp
)

