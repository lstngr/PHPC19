CXX = g++
CXXFLAGS = -g -Wall -W -pedantic

TARGET = Poisson
SOURCES = Poisson.cpp PoissonSolver.cpp
OBJECTS = Poisson.o PoissonSolver.o

all: Poisson

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

Poisson.o: Poisson.cpp PoissonSolver.hpp
	$(CXX) $(CXXFLAGS) -c Poisson.cpp -o Poisson.o
	
PoissonSolver.o: PoissonSolver.cpp PoissonSolver.hpp
	$(CXX) $(CXXFLAGS) -c PoissonSolver.cpp -o PoissonSolver.o

clean:
	rm $(OBJECTS) $(TARGET)
