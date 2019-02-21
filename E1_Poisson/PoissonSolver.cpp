#include "PoissonSolver.hpp"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace PHPC19;

PoissonSolver::PoissonSolver()
    :gsize_(100),
    precision_(1e-3),
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
    std::vector<std::vector<double>> u_values(u_grid_);
    std::vector<std::vector<double>> f_values(u_grid_);
    for( unsigned int ix=0; ix<gsize_; ix++ ){
        for( unsigned int iy=0; iy<gsize_; iy++ ){
            u_values[ix][iy] = UFunction(ix,iy);
            f_values[ix][iy] = FFunction(ix,iy);
        }
    }

    // Run Jacobi Iterative Solver
    bool converged(false);
    unsigned int iter_num(0);
    do{
        for( unsigned int ix(1); ix < u_grid_.size()-1; ix++)
            for( unsigned int iy(1); iy < u_grid_[ix].size()-1; iy++)
                u_grid_[ix][iy] = .25 * ( u_grid_old_[ix-1][iy] + u_grid_old_[ix+1][iy] + u_grid_old_[ix][iy-1] + u_grid_old_[ix][iy+1] - f_values[ix][iy] * pow(gspace,2) );
        u_grid_old_ = u_grid_;
        // Check wether the algorithm converges
        if(iter_num % conv_freq_test == 0)
            if(GetDistance(u_grid_,u_values) < (pow(gsize_,2) * precision_))
                converged = true;
        iter_num++;
    }while(not converged);
}

void PoissonSolver::ExportU(const std::string& filename) const{
    std::ofstream output;
    output.open(filename);
    for(unsigned int ix=0; ix<gsize_; ix++){
        for(unsigned int iy=0; iy<gsize_; iy++){
            output << u_grid_[ix][iy] << " ";
        }
        output << std::endl;
    }
    output << std::endl << std::endl;
    output.close();
}

double PoissonSolver::FFunction(unsigned int ix, unsigned int iy) const{
    return -200.*pow(M_PI,2)*UFunction(ix,iy);
}

double PoissonSolver::UFunction(unsigned int ix, unsigned int iy) const{
    return sin(10*M_PI*ix/gsize_) * sin(10*M_PI*iy/gsize_);
}

double PoissonSolver::GetDistance(const std::vector<std::vector<double>> &v1,
        const std::vector<std::vector<double>> &v2) const{
    double dist(0.);
    for( unsigned int ix(0); ix < v1.size(); ix++ )
        for( unsigned int iy(0); iy < v1[ix].size(); iy++ )
            dist += pow(v1[ix][iy]-v2[ix][iy],2);
    return sqrt(dist);
}
