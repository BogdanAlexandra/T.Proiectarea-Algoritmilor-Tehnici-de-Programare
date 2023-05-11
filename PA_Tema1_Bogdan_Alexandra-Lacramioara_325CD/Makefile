CC = g++
CFLAGS = -Wall -Wextra -std=c++11

build: p1 p2 p3 p4 

p1: p1.cpp
	$(CC) $(CFLAGS) -o p1 p1.cpp

p2: p2.cpp
	$(CC) $(CFLAGS) -o p2 p2.cpp

p3: p3.cpp
	$(CC) $(CFLAGS) -o p3 p3.cpp

p4: p4.cpp
	$(CC) $(CFLAGS) -o p4 p4.cpp

run-p1:
	$(CC) $(CFLAGS) -o p1 p1.cpp
	./p1

run-p2:
	$(CC) $(CFLAGS) -o p2 p2.cpp
	./p2

run-p3:
	$(CC) $(CFLAGS) -o p3 p3.cpp
	./p3

run-p4:
	$(CC) $(CFLAGS) -o p4 p4.cpp
	./p4

clean:
	rm -f p1 p2 p3 p4
