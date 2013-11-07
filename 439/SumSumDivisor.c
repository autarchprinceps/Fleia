/*
 * =====================================================================================
 *
 *       Filename:  SumSumDivisor.c
 *
 *    Description:  Project Euler Problem 439
 *
 *        Created:  06.11.2013 08:36:35
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

mpz_t* p(mpz_t k){

}

mpz_t* d1(mpz_t k){

}

mpz_t* d(mpz_t k) {
	mpz_t* result = malloc(sizeof(mpz_t));
	mpz_t i, check;
	mpz_init(*result);
	mpz_init(check);
	mpz_init_set_ui(i, 1);
	for(;mpz_cmp(k, check) >= 0;) {
		mpz_mod(check, k, i);
		if(mpz_cmp_ui(check, 0) == 0) {
			mpz_mul(check, i, i);
			mpz_add(*result, *result, i);
			if(mpz_cmp(check, k) != 0) {
				mpz_tdiv_q(check, k, i);
				mpz_add(*result, *result, check);
			}
		}
		mpz_add_ui(i, i, 1);
		mpz_mul(check, i, i);
	}
	mpz_clear(i);
	mpz_clear(check);
	return result;
}

/*unsigned long S(unsigned long N) {
	unsigned long result = 0;
	for(unsigned long i = 1; i <= N; i++) {
		for(unsigned long j = 1; j <= N; j++) {
			result += d(i * j);
		}
	}
	return result;
}*/

mpz_t* S(mpz_t N) {
	/**
	 * thread_count
	 * results[thread_count]
	 * splitN = N/4 + 1
	 *
	 * parallel {
	 * 	thread_id
	 * 	start = splitN * id + 1
	 * 	end = splitN * (id + 1)
	 *
	 * 	foreach(i in start..end) {
	 * 		foreach(j in 1..N) {
	 * 			results[thread_id] += d(i * j)
	 * 		}
	 * 	}
	 * }
	 *
	 * composition = +/ results
	 */
	gmp_fprintf(stderr, "N: %Zd\n", N);
	const unsigned int thread_count = 4; // TODO automatic detection
	mpz_t* results = malloc(sizeof(mpz_t) * thread_count);
	mpz_t splitN;
	mpz_init(splitN);

	fprintf(stderr, "count: %d\n", thread_count);
	mpz_cdiv_q_ui(splitN, N, thread_count);
	gmp_fprintf(stderr, "splitN: %Zd\n", splitN);

	#pragma omp parallel
	{
		unsigned int thread_id = omp_get_thread_num();
		mpz_t start, end, tmp, i, j;
		mpz_init(start);
		mpz_init(end);
		mpz_init(tmp);
		mpz_init(i);
		mpz_init(j);
		mpz_init(results[thread_id]);

		mpz_mul_ui(start, splitN, thread_id);
		mpz_add_ui(start, start, 1);

		mpz_mul_ui(end, splitN, thread_id + 1);

		mpz_sub(tmp, end, start);
		
		#pragma omp critical
		{
			gmp_fprintf(stderr, "[%d] start: %Zd end: %Zd length: %Zd\n", thread_id, start, end, tmp);
		}

		for(mpz_set(i, start); mpz_cmp(i, end) <= 0; mpz_add_ui(i, i, 1)) {
			for(mpz_set_ui(j, 1); mpz_cmp(j, end) <= 0; mpz_add_ui(j, j, 1)) {
				mpz_mul(tmp, i, j);
				mpz_add(results[thread_id], results[thread_id], *d(tmp));
			}
		}
	}
	mpz_t* composition = malloc(sizeof(mpz_t));
	mpz_init(*composition);
	for(unsigned int nz = 0; nz < thread_count; nz++) {
		mpz_add(*composition, *composition, results[nz]);	
	}
	return composition;
}

int main() {
    omp_set_num_threads(4);
	mpz_t ubergabe, result;
	mpz_init(ubergabe);
	mpz_init(result);

	mpz_set_ui(ubergabe, 1);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 2);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 3);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 2);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 4);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 6);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 3);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 6);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 9);
	mpz_add(result, result, *d(ubergabe));

	gmp_fprintf(stderr, "| Manuelle Addition von d: %Zd\n",  result);

	mpz_set_ui(ubergabe, 1000);
	gmp_fprintf(stderr, "| S(1000): %Zd\n", *S(ubergabe));
	return 0;
}
