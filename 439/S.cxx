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
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		for(BigInt i = BigInt(1); i <= N; i++) { // TODO
			for(BigInt j = BigInt(1); j <= N; j++) {
				result[id] += d(i * j);
			}
		}
	}
	return (result[0] + result[1] + result[2] + result[3]);
}
