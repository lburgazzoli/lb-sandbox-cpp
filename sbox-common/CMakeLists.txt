project(sbox-common)

INCLUDE_DIRECTORIES(include)
ADD_LIBRARY(
  sbox-common
  src/lb/common/lb_common.cpp
)

