#!/bin/sh

g++ -c hello.cc
g++ -c greetings.cc
g++ -o hello hello.o greetings.o
