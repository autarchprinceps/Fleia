/*
 * =====================================================================================
 *
 *       Filename:  S.cxx
 *
 *    Description:  TODO autarch 
 *
 *        Created:  08.11.2013 16:19:06
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */

#include "S.h"

BigInt S(const BigInt N) {
	BigInt result[4];
	for(int i = 0; i < 4; i++)
		result[i] = BigInt();
	BigInt splitN = N / 4;
	#pragma omp parallel
	{
		const unsigned int id = omp_get_thread_num();
		BigInt i = BigInt();
		BigInt borderR = splitN * (id + 1);
		if(borderR > N) borderR = N;
		for(i = splitN * id + 1; i <= borderR; i++) {
			BigInt max = BigInt(), temsum = BigInt();
			for(BigInt j = BigInt(1); j <= i; j++) {
				max = d(i * j);
				temsum += max;
			}
			temsum *= 2;
			temsum -= max;
			result[id] += temsum;
		}
	}
	return (result[0] + result[1] + result[2] + result[3]);
}
