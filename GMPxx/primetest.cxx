/*
 * =====================================================================================
 *
 *       Filename:  primetest.cxx
 *
 *    Description:  asdsaf
 *
 *        Version:  1.0
 *        Created:  22/11/13 16:44:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Groxar (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "prime.hxx"
#include "BigInt.h"
#include <iostream>

using namespace fleiamath;
using namespace fleiamath;

int main(void){
    PrimeList pl = PrimeList();
    BigInt n = BigInt(1200000);
    cout << n << endl;
    pl.calcPrimesUntil(n);
    cout << "isPrime(n)" << endl;
    pl.isPrime( n ); 
    cout << "print list" << endl;
    pl.printList();


    return 0;
}
