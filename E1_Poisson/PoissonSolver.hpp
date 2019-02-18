#ifndef PHPC19_POISSONSOLVER_
#define PHPC19_POISSONSOLVER_

#include <vector>
#include <string>

namespace PHPC19{

    class PoissonSolver{
        public:
            PoissonSolver();
            virtual ~PoissonSolver(){}
            void SetICs();
            void SetParameters();
            void Run();
            double F_function(unsigned int ix, unsigned int iy) const;
            double U_function(unsigned int ix, unsigned int iy) const;
        private:
            unsigned int gsize_;
            double precision_;
            std::string output_file_;
            std::vector<std::vector<double>> u_grid_;
    };

}

#endif // PHPC19_POISSONSOLVER_
