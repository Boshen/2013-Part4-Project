#! /bin/bash
g++ -c -o Error.o Error.cpp; 
g++ -c -o FileReader.o FileReader.cpp; 
g++ -c -o FileWriter.o FileWriter.cpp; 
g++ -c -o UtilsString.o UtilsString.cpp; 
g++ -o readIntervals Error.o FileReader.o FileWriter.o UtilsString.o readIntervals.cpp -std=c++11
