#!/bin/sh
#SBATCH -A phpc2019 
#SBATCH -u stenger 
#SBATCH --partition=debug
#SBATCH --ntasks 1 
#SBATCH --nnodes 1 
#SBATCH --cpus-per-task 1

if [ -n "$SLURM_CPUS_PER_TASK" ]; then
omp_threads=$SLURM_CPUS_PER_TASK
else
omp_threads=1
fi
export OMP_NUM_THREADS=$omp_threads

srun ./pi
