#!/bin/bash
cxxtest-4.3/bin/cxxtestgen --error-printer -o cxxtest-4.3/test.cpp tests/Test.h
rm ./test -f
g++ cxxtest-4.3/test.cpp src/ReadStreamFactory.cpp src/IReadStream.cpp -o test -I cxxtest-4.3/ -lpthread -lboost_system
./test