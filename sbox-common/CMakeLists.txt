project(sbox-common)

INCLUDE_DIRECTORIES(src)
ADD_LIBRARY(
  sbox-common
  src/lb/common/common.cpp
)

