sum: SumSumDivisor.c
	gcc -std=gnu99 -O3 -lgmp -fopenmp -o sum SumSumDivisor.c

run: sum
	OMP_NUM_THREADS=4 ./sum
