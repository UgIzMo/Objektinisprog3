# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall # Updated to C++17

# Program name
TARGET = programa

# Object files list
OBJS = main.o functions.o functions_vector.o studentas.o functions_old.o 

# Main rule for program compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Individual file compilation rules
main.o: main.cpp functions.h studentas.h
	$(CXX) $(CXXFLAGS) -c main.cpp

functions.o: functions.cpp functions.h functions_vector.h studentas.h functions_old.h 
	$(CXX) $(CXXFLAGS) -c functions.cpp

functions_vector.o: functions_vector.cpp functions_vector.h studentas.h
	$(CXX) $(CXXFLAGS) -c functions_vector.cpp


studentas.o: studentas.cpp studentas.h
	$(CXX) $(CXXFLAGS) -c studentas.cpp

functions_old.o: functions_old.cpp functions_old.h studentas.h 
	$(CXX) $(CXXFLAGS) -c functions_old.cpp

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
