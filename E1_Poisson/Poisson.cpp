#include <cmath>
#include <iostream>
#include <unistd.h>
#include "PoissonSolver.hpp"

int main( int argc, char *argv[] ){
    PHPC19::PoissonSolver kiki;
    kiki.Run();
    kiki.ExportU();
	return 0;
}
