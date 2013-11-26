CC = gcc
CXX = g++

run: sum
	OMP_NUM_THREADS=4 ./sum

sum: S.cxx test.cxx ../GMPxx/BigInt.cxx ../GMPxx/prime.cxx
	$(CXX) -O3 -lgmp -lecm -fopenmp -o $@ $+

sumc: SumSumDivisor.c
	$(CC) -std=gnu99 -O3 -lgmp -fopenmp -o $@ $+

perf: S.cxx test.cxx ../GMPxx/BigInt.cxx ../GMPxx/prime.cxx
	$(CXX) -pg -lgmp -lecm -fopenmp -o $@ $+
	OMP_NUM_THREADS=4 ./perf
	gprof ./perf gmon.out > analysis.txt
	gprof2dot analysis.txt | dot -Tsvg -o analysis.svg

runc: sumc
	OMP_NUM_THREADS=4 ./sumc

clean:
	rm sumc sum
