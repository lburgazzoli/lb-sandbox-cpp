#!/bin/bash

BASEDIR=$(dirname $0)

rm -rf ${BASEDIR}/build
mkdir ${BASEDIR}/build
cd ${BASEDIR}/build

cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang ..
