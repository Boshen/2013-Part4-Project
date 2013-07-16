CC = g++
CFLAGS = -Wall -O3 #-O3  #-g -pg

BOOST_DIR = /usr/include/boost_1_53_0

SOURCES = ShPathFactory.cpp

OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(SOURCES:.cpp=.h)  ShPathInterface.h ShPathDijkstra.h ShPathDijkstraSTL.h ShPathAstar.h ShPathAstarSTL.h ShPathDijkstraBidirectSTL.h  ShPathAstarBidirect.h ShPathDijkstraSet.h

all: $(OBJECTS)

%.o: %.cpp %.h $(HEADERS)
	$(CC) $(CFLAGS) -I $(BOOST_DIR) -I .. -c -o $@ $<
	touch ../main.cpp

.PHONY: clean
clean : 
	rm -f core $(OBJECTS)
