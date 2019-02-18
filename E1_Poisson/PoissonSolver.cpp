#include "PoissonSolver.hpp"
#include <cmath>

using namespace PHPC19;

PoissonSolver::PoissonSolver()
    :gsize_(100),
    precision_(1e-7),
    output_file_("output.out"),
    u_grid_(std::vector<std::vector<double>>(gsize_,std::vector<double>(gsize_,0.0)))
{
    // Nothing to see yet!
}

void PoissonSolver::Run(){
    // Define 'physical' grid spacing
    double gspace(1./gsize_);
    // Define 'old' storage to avoid allocating memory at each iteration
    std::vector<std::vector<double>> u_grid_old_(u_grid_);
    // Define convergence test frequency
    int conv_freq_test(20);
    // Avoid CPU cost by computing all U/F_function possible beforehand
    std::vector<std::vector<double>> U_values;
    std::vector<std::vector<double>> F_values;
    for( unsigned int ix=0; ix<gsize_; ix++ ){
        for( unsigned int iy=0; iy<gsize_; iy++ ){
            U_values[ix][iy] = U_function(ix,iy);
            F_values[ix][iy] = F_function(ix,iy);
        }
    }
}

double PoissonSolver::F_function(unsigned int ix, unsigned int iy) const{
    return -200.*pow(M_PI,2)*U_function(ix,iy);
}

double PoissonSolver::U_function(unsigned int ix, unsigned int iy) const{
    return sin(10*M_PI*ix/gsize_) * sin(10*M_PI*iy/gsize_);
}
