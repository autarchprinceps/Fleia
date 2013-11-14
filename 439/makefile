CC = gcc
CXX = g++

run: sum
	OMP_NUM_THREADS=4 ./sum

sum: S.cxx d.cxx test.cxx ../GMPxx/BigInt.cxx 
	$(CXX) -O3 -lgmp -lecm -fopenmp -o $@ $+

sumc: SumSumDivisor.c
	$(CC) -std=gnu99 -O3 -lgmp -fopenmp -o $@ $+

runc: sumc
	OMP_NUM_THREADS=4 ./sumc

clean:
	rm sumc sum
