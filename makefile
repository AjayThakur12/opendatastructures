CFLAGS=-Wall -Wextra -std=c++11

all:
	g++ $(CFLAGS) bigfile.cpp -o build.app
