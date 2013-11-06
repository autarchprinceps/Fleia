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
	// fprintf(stderr, "d pre init\n");
	mpz_init(*result);
	mpz_init(check);
	mpz_init_set_ui(i, 1);
	// fprintf(stderr, "d pre for\n");
	for(;mpz_cmp(k, check) >= 0;) {
		// result += (k % i) ? 0 : ((i * i == k) ? i : i + k / i);
		mpz_mod(check, k, i);
		if(mpz_cmp_ui(check, 0) == 0) {
			mpz_mul(check, i, i);
			mpz_add(*result, *result, i);
			if(mpz_cmp(check, k) != 0) {
				mpz_cdiv_q(check, k, i);
				mpz_add(*result, *result, check);
			}
		}
		mpz_add_ui(i, i, 1);
	    mpz_mul(check, i, i);
	}
	// fprintf(stderr, "d pre clear\n");
	mpz_clear(i);
	mpz_clear(check);
	return result;
}

/*unsigned long S(unsigned long N) {
	unsigned long result = 0;
	unsigned long* gs = malloc(N * N * sizeof(unsigned long));
	#pragma omp parallel for
	for(unsigned long nu = 0; nu < N * N; nu++) {
		gs[nu] = 0;
	}
	#pragma omp parallel for
	for(unsigned long i = 1; i <= N; i++) {
		for(unsigned long j = 1; j <= N; j++) {
			if(gs[i * j - 1] == 0)
				gs[i * j - 1] = d(i * j);
		}
	}
	for(unsigned long i = 1; i <= N; i++) {
		for(unsigned long j = 1; j <= N; j++) {
			result += gs[i * j - 1];
		}
	}
	return result;
}*/

mpz_t* S(mpz_t N) {
	const int count = omp_get_num_threads();
	mpz_t* result = malloc(sizeof(mpz_t) * count);
	mpz_t tmp, i, j;
	// fprintf(stderr, "S pre init\n");
	#pragma omp parallel for
	for(int nu = 0; nu < count; nu++) {
		mpz_init(result[nu]);
	}
	mpz_init(tmp);
	mpz_init_set_ui(i, 1);
	mpz_init(j);
	// fprintf(stderr, "S pre for\n");
	#pragma omp parallel for
	for(;mpz_cmp(N, i) >= 0; mpz_add_ui(i, i, 1)) {
		const int thread_id = omp_get_thread_num();
		for(mpz_set_ui(j, 1);mpz_cmp(N, j) >= 0; mpz_add_ui(j, j, 1)) {
			mpz_mul(tmp, i, j);
			mpz_add(result[thread_id], result[thread_id], *d(tmp));
		}
	}
	// fprintf(stderr, "S pre clear\n");
	mpz_clear(tmp);
	mpz_clear(i);
	mpz_clear(j);
	mpz_t* composition = malloc(sizeof(mpz_t));
	mpz_init(*composition);
	for(int nz = 0; nz < count; nz++) {
		mpz_add(*composition, *composition, result[nz]);
		mpz_clear(result[nz]);
	}
	return composition;
}

int main() {
    omp_set_num_threads(4);
	/* printf("%lu\n", d(1) + d(2) + d(3) + d(2) + d(4) + d(6) + d(3) + d(6) + d(9));
	printf("%lu\n", S(3));
	printf("%lu\n", S(1000));
	printf("%lu\n", S(pow(10, 5)) % (unsigned long)pow(10, 9));
	printf("%lu\n", S(pow(10, 11)) % (unsigned long)pow(10, 9)); */
	mpz_t ubergabe, tmp, result;
	// fprintf(stderr, "main pre init\n");
	mpz_init(ubergabe);
	// fprintf(stderr, "main dur init\n");
	mpz_init(tmp);
	mpz_init(result);
	
	mpz_set_ui(ubergabe, 1);
	mpz_set(result, *d(ubergabe));
	mpz_set_ui(ubergabe, 2);
	mpz_add(result, result, *d(ubergabe));
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 3);
	mpz_add(result, result, *d(ubergabe));
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 4);
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 6);
	mpz_add(result, result, *d(ubergabe));
	mpz_add(result, result, *d(ubergabe));
	mpz_set_ui(ubergabe, 9);
	mpz_add(result, result, *d(ubergabe));
	gmp_printf("%Zd\n", result);

	// fprintf(stderr, "main post init\n");
	mpz_set_ui(ubergabe, 3);
	// fprintf(stderr, "main pre S(3)\n");
	gmp_printf("%Zd\n", *S(ubergabe));
	mpz_set_ui(ubergabe, 1000);
	// fprintf(stderr, "main pre S(1000)\n");
	gmp_printf("%Zd\n", *S(ubergabe));
	mpz_ui_pow_ui(ubergabe, 10, 5);
	mpz_ui_pow_ui(tmp, 10, 9);
	mpz_mod(ubergabe, *S(ubergabe), tmp);
	// fprintf(stderr, "main pre S(10 hoch 5) mod 10 hoch 9\n");
	gmp_printf("%Zd\n", ubergabe);
	mpz_ui_pow_ui(ubergabe, 10, 11);
	mpz_mod(ubergabe, *S(ubergabe), tmp);
	// fprintf(stderr, "main pre S(10 hoch 11) mod 10 hoch 9\n");
	gmp_printf("%Zd\n", ubergabe);
	return 0;
}
