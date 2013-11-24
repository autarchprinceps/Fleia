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

int main(void){
    BigInt result = BigInt(0);
    for(BigInt i = BigInt(1);i <= 1000; i++)
    {
        for(BigInt j = BigInt(1); j <= 1000; j++)
        {
            result +=d(i,j);
            cout <<"d("<<i<<","<<j<<") "<< d(i,j) << endl;
        }
    }
    cout << result << endl;

    //pl.printList();
    //pl.printList(list);
    //pl.calcPrimesUntil(n);
    //cout << "isPrime(n)" << endl;
    //pl.isPrime( n ); 
    //cout << "print list" << endl;
    //pl.printList();


    return 0;
}
