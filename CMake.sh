#!/bin/bash

BASEDIR=$(dirname $0)

rm -rf ${BASEDIR}/cmake-build
mkdir ${BASEDIR}/cmake-build
cd ${BASEDIR}/cmake-build

cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang ..
