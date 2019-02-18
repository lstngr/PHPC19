CXX = g++
CXXFLAGS = -g

TARGET = Poisson
SOURCES = Poisson.cpp PoissonSolver.cpp
OBJECTS = Poisson.o PoissonSolver.o

all: Poisson

$(TARGET): Poisson.o PoissonSolver.o
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

Poisson.o: Poisson.cpp PoissonSolver.hpp
	
PoissonSolver.o: PoissonSolver.cpp PoissonSolver.hpp

clean:
	rm $(OBJECTS) $(TARGET)
