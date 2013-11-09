/*
 * =====================================================================================
 *
 *       Filename:  d.cxx
 *
 *    Description:  TODO groxar viel Spa� beim optimieren
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
	for(BigInt i = BigInt(1); i * i <= sum; i++)
		sum += (N % i) ? 0 : ((i * i == N) ? i : i + sum/i);
	return sum;
}
