#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "PoissonSolver.hpp"

int main( int argc, char *const argv[] ){
    // Read command line arguments
    int optchar; // Option character
    PHPC19::PoissonParameters params; // Default Parameters

    while( (optchar = getopt(argc,argv,"s:p:o:")) != -1 ) {
        switch(optchar) {
            case 's':
                // Set domain size
                params.gsize = std::atoi(optarg);
                break;
            case 'p':
                // Set precision
                params.precision = std::atof(optarg);
                break;
            case 'o':
                // Set output file
                params.output_file = optarg;
                break;
            case ':':
                /* missing option argument */
                fprintf(stderr, "%s: option '-%c' requires an argument\n",
                        argv[0], optopt);
                break;
            case '?':
            default:
                /* invalid option */
                fprintf(stderr, "%s: option '-%c' is invalid: ignored\n",
                        argv[0], optopt);
                break;
        }
    }


    PHPC19::PoissonSolver kiki(params);
    kiki.Run();
    kiki.ExportU();
	return 0;
}
