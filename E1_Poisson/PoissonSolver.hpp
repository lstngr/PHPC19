#ifndef PHPC19_POISSONSOLVER_
#define PHPC19_POISSONSOLVER_

#include <vector>
#include <string>

namespace PHPC19{

    struct PoissonParameters{
        PoissonParameters(unsigned int gsize=100, double precision=1e-4, std::string output_file="output.out");
        unsigned int gsize;
        double precision;
        std::string output_file;
    };

    class PoissonSolver{
        public:
            PoissonSolver( const PoissonParameters& params = PoissonParameters());
            virtual ~PoissonSolver(){}
            //void SetICs();
            //void SetParameters();
            void Run();
            void ExportU() const;
            void ExportU(const std::string& filename) const;
            double FFunction(unsigned int ix, unsigned int iy) const;
            double UFunction(unsigned int ix, unsigned int iy) const;
        private:
            double GetDistance(const std::vector<std::vector<double>>&,
                    const std::vector<std::vector<double>>&) const;
            unsigned int gsize_;
            double precision_;
            std::string output_file_;
            std::vector<std::vector<double>> u_grid_;
    };

}

#endif // PHPC19_POISSONSOLVER_
