#!/bin/bash
#SBATCH -c 2 
#SBATCH -A phpc2019 
#SBATCH --reservation=phpc2019
#SBATCH --ntasks=1 

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
./pi
