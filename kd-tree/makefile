CC = g++
CFLAGS = -w -std=c++17
TARGETS = tests

all: $(TARGETS)

tests: KdTree.o tests.o exceptions.o
	$(CC) $(CFLAGS) KdTree.o exceptions.o tests.o -o tests

KdTree.o: KdTree.cpp KdTree.h
	$(CC) $(CFLAGS) -c KdTree.cpp

exceptions.o: exceptions.cpp
	$(CC) $(CFLAGS) -c exceptions.cpp

tests.o: tests.cpp
	$(CC) $(CFLAGS) -c tests.cpp