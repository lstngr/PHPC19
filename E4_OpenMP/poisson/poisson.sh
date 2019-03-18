#!/bin/sh
#SBATCH -A phpc2019 -u stenger --reservation=phpc2019
#SBATCH -N 1 -c 1
./poisson
