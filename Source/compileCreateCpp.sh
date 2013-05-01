#! /bin/bash
g++ -c -o Error.o Error.cpp; 
g++ -c -o UtilsString.o UtilsString.cpp; 
g++ -c -o FileReader.o FileReader.cpp; 
g++ -c -o FileWriter.o FileWriter.cpp; 
g++ -o createCpp Error.o UtilsString.o FileReader.o FileWriter.o createCpp.cpp
