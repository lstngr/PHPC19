#!/bin/sh
#SBATCH -A phpc2019
#SBATCH --reservation=phpc2019
#SBATCH -n 4

module purge
module load gcc mvapich2

srun ./pi





