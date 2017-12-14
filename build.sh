#!/bin/bash
rm ./main -f
g++ src/*.cpp -o main -lpthread -lboost_system
./main