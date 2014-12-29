project(sbox-chronicle)

INCLUDE_DIRECTORIES(src)
ADD_LIBRARY(
  sbox-chronicle
  src/lb/chronicle/queue/chronicle_queue.cpp
  src/lb/chronicle/queue/indexed_chronicle_queue.cpp
)

