#pragma once

#include "BigInt.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace fleiamath{
    class PrimeList{
        public:
            static PrimeList& instance(){
                static PrimeList instance = PrimeList();
                return instance;
            }
            //vector<BigInt> getPrimefactors(BigInt n);
            void calcPrimesUntil(const BigInt &n);
            bool isPrime(const BigInt &n);
            vector<BigInt> list;
            void printList();

        private:
            PrimeList(); 
            PrimeList(PrimeList const&);              
            void operator=(PrimeList const&); 
            
            BigInt end;
    };
    
    void printList(vector<BigInt> plist);
    void printSet(set<BigInt,BigInt::BigInt_compare> plist);
    vector<BigInt> getPrimeFactors(const BigInt &n);
    vector<BigInt> unifyFactorLists(const vector<BigInt> &a,const vector<BigInt> &b);
    BigInt getDivisorCount(BigInt& a);
    set<BigInt,BigInt::BigInt_compare> getDivisor(BigInt& a);
    
    BigInt d(BigInt& a,BigInt& b);

}
