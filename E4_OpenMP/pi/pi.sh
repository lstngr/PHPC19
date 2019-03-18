#!/bin/bash
#SBATCH -A phpc2019 
#SBATCH -u stenger 
#SBATCH --reservation=phpc2019
#SBATCH --ntasks=1 
#SBATCH --nnodes=1 
#SBATCH -c 2

export OMP_NUM_THREADS=2
./pi
