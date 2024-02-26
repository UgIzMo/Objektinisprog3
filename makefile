# Kompiliatoriaus nustatymas
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Programos pavadinimas
TARGET = programa

# Objekto failų sąrašas
OBJS = main.o studentas.o functions.o

# Pagrindinė taisyklė programos sukompiliavimui
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Atskirų failų kompiliavimo taisyklės
main.o: main.cpp studentas.h functions.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Studentas.o: studentas.cpp studentas.h
	$(CXX) $(CXXFLAGS) -c Studentas.cpp

PagalbinesFunkcijos.o: functions.cpp functions.h studentas.h
	$(CXX) $(CXXFLAGS) -c functions.cpp

# Valymo taisyklė
clean:
	rm -f $(TARGET) $(OBJS)
