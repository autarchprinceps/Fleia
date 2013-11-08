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

BigInt d(const BigInt N) {
	BigInt sum = BigInt();
	for(BigInt i = BigInt(1); i * i <= num; i++)
		sum += (N % i) ? 0 : ((i * i == N) ? i : i + num/i);
	return sum;
}