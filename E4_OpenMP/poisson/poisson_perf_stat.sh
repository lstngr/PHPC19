#!/bin/sh
#SBATCH -A phpc2019 -u stenger --partition=debug
#SBATCH -N 1 -c 1
perf stat ./poisson_ij
perf stat ./poisson_ji
