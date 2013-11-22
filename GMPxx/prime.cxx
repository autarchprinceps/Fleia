/*
 * =====================================================================================
 *
 *       Filename:  prime.cxx
 *
 *    Description:  prime function
 *
 *        Version:  1.0
 *        Created:  21/11/13 23:04:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Groxar (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "prime.hxx"
#include "iostream"

namespace fleiamath{
    PrimeList::PrimeList(){
        end = BigInt();
        end = 2;
        list.push_back(end);
    }

    PrimeList::~PrimeList(){
    }
    
    vector<BigInt> PrimeList::getPrimeFactors(const BigInt &n){
       return list; 
    }
   
    void PrimeList::calcPrimesUntil(const BigInt &n){
        BigInt i = BigInt();
        i = end;

        if(i % 2 == 0)
            i++;

        while( i <= n ){
            if(isPrime(i))
            {
                list.push_back(i);
                end = i;
            }
            i+=2;
        }
        end = i;
    }

    void PrimeList::printList()
    {
        for (std::vector<BigInt>::iterator it = list.begin(); it!=list.end(); ++it){
            cout << (*it) << endl;
        }
    }

    bool PrimeList::isPrime(const BigInt &n){
        BigInt until = BigInt();
        until = n.sqrt();

        if(until > end)
            calcPrimesUntil(until);

        for (std::vector<BigInt>::iterator it = list.begin(); (*it) <= until && it!=list.end(); ++it){
            //cout << "n: " << n << "\n *it: " << *it << "\nn\%*it = " << (n % (*it)) <<endl; 
            if(n % (*it) == 0)
                return 0;
        }
        return 1;
    }
}

