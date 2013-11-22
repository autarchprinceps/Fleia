#pragma once

#include "BigInt.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace fleiamath{
    class PrimeList{
        public:
            PrimeList(); 
            ~PrimeList(); 
            //vector<BigInt> getPrimefactors(BigInt n);
            void calcPrimesUntil(const BigInt &n);
            bool isPrime(const BigInt &n);
            vector<BigInt> getPrimeFactors(const BigInt &n);
            void printList();

        private:
            vector<BigInt> list;
            BigInt end;
    };
}
