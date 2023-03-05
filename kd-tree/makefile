CC = g++
CFLAGS = -w -std=c++17

output: KdTree.o exceptions.o
	$(CC) $(CFLAGS) KdTree.o exceptions.o -o output

KdTree.o: KdTree.cpp KdTree.h
	$(CC) $(CFLAGS) -c KdTree.cpp

exceptions.o: exceptions.cpp
	$(CC) $(CFLAGS) -c exceptions.cpp