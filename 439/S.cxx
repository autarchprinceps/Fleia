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

BigInt* S(const BigInt N) {
    getPrimeFactors(N);
	if(N < 10) {
		BigInt* sum = new BigInt();
		for(BigInt ii = BigInt(1); ii <= N; ii++) {
			BigInt maxs = BigInt(), tempsum = BigInt();
			for(BigInt jj = BigInt(1); jj <= ii; jj++) {
				maxs = d(ii, jj);
				tempsum += maxs;
			}
			tempsum *= 2;
			tempsum -= maxs;
			// cout << tempsum << " ";
			*sum += tempsum;
		}
		// cout << "Final result (non-threaded): ";
		// cout << *sum << endl;
		return sum;
	} else {
		omp_set_num_threads(4);
		BigInt result[4];
		for (int t = 0; t < 4; t++) result[t] = BigInt();
		#pragma omp parallel
		{
			const unsigned int id = omp_get_thread_num();
			for (BigInt i = BigInt(1); i <= N; i++) {
				if (i % 4 == id) {
					BigInt max = BigInt(), temsum = BigInt();
					vector<BigInt> pfa = getPrimeFactors(i);
					for (BigInt j = BigInt(1); j <= i; j++) {
						max = d(pfa, j);
						temsum += max;
					}
					temsum *= 2;
					temsum -= max;
					result[id] += temsum;
				}
			}
		}
		/*
		omp_set_num_threads(4);
		BigInt result[4], split[4];
		for(int t = 0; t < 4; t++) {
			result[t] = BigInt();
			split[t] = BigInt();
		}
		split[0] = N / 2;
		split[1] = split[0] + N / 4; // TODO
		split[2] = split[1] + N / 6; // TODO
		split[3] = N;
		#pragma omp parallel
		{
			const unsigned int id = omp_get_thread_num();
			// sleep(id * 5);
			// cout << "ID: " << id << " " << ((id == 0) ? 1 : (split[id - 1] + 1)) << " " << split[id] << endl;
			// sleep(50);
			BigInt i = BigInt();
			for(i = (id == 0) ? 1 : (split[id - 1] + 1); i <= split[id]; i++) {
				BigInt max = BigInt(), temsum = BigInt();
				for(BigInt j = BigInt(1); j <= i; j++) {
					max = d(i, j);
					temsum += max;
				}
				temsum *= 2;
				temsum -= max;
				result[id] += temsum;
				// cout << "[DEBUG] i loop " << id << " " << i << " " << (result[0] + result[1] + result[2] + result[3]) << endl;
			}
		}*/
		BigInt* res = new BigInt();
		*res = (result[0] + result[1] + result[2] + result[3]);
		return res;
	}
}
