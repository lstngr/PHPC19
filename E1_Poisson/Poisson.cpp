#include <cmath>
#include <iostream>
#include "PoissonSolver.hpp"

using namespace std;

int main(){
    PHPC19::PoissonSolver kiki;
    kiki.Run();
    kiki.ExportU("output.out");
	return 0;
}
