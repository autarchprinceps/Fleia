CC = clang
CXX = clang++

run: sum
	./sum

sum: ../GMPxx/BigInt.cxx S.cxx d.cxx test.cxx ../GMPxx/BigInt.h S.h d.h
	$(CXX) -O3 -lgmp ../GMPxx/BigInt.cxx S.cxx d.cxx test.cxx -o sum

sumc: SumSumDivisor.c
	$(CC) -std=gnu99 -O3 -lgmp -fopenmp -o sumc SumSumDivisor.c

runc: sumc
	OMP_NUM_THREADS=4 ./sumc

clean:
	rm sumc sum