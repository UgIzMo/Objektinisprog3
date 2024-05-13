# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O3 

# Program name
TARGET = programa

# Source files list
SRCS = main.cpp functions.cpp functions_vector.cpp studentas.cpp functions_old.cpp

# Object files list (generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Main rule for program compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Individual file compilation rules
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule to remove executable and object files
clean:
	rm -f $(TARGET) $(OBJS)

