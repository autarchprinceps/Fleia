/*
 * =====================================================================================
 *
 *       Filename:  S.cxx
 *
 *    Description:  
 *
 *        Created:  08.11.2013 16:19:06
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */

#include "S.h"
#define NUM_THREADS = 4

BigInt S(const BigInt N) {
	BigInt result = BigInt();
	for(BigInt i = BigInt(1); i <= N; i++) {
		for(BigInt j = BigInt(1); j <= N; j++) {
			result += d(i * j);
		}
	}
	return result;
}
