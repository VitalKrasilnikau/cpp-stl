#!/bin/bash
cxxtest-4.3/bin/cxxtestgen --error-printer -o test.cpp tests/Test.h
rm ./test -f
g++ test.cpp -o test -lpthread -lboost_system
./test