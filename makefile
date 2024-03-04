CC = g++
CFLAGS = -std=c++11 -Wall

# List of source files
SRCS = main.cpp functions.cpp studentas.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Name of the executable
EXEC = main

# Makefile targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Rules to generate object files from source files
main.o: main.cpp functions.h studentas.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

functions.o: functions.cpp functions.h studentas.h
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o

studentas.o: studentas.cpp studentas.h
	$(CC) $(CFLAGS) -c studentas.cpp -o studentas.o

clean:
	rm -f $(OBJS) $(EXEC)
