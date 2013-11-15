/*
 * =====================================================================================
 *
 *       Filename:  d.cxx
 *
 *    Description:  TODO groxar viel Spaﬂ beim optimieren
 *
 *        Created:  08.11.2013 16:19:06
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */

#include "d.h"

BigInt d(const BigInt N) {
	BigInt sum = BigInt();
	for(BigInt i = BigInt(1); i <= N / 2; i++) {
		if(N % i == 0) {
			sum += i;
		}
	}
	sum += N;
	return sum;
}
