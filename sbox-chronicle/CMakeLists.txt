project(sbox-chronicle)

INCLUDE_DIRECTORIES(include)
ADD_LIBRARY(
  sbox-chronicle
  src/lb/chronicle/chronicle.cpp
  src/lb/chronicle/indexed_chronicle.cpp
)

