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

    
    vector<BigInt> getPrimeFactors(const BigInt &n){
        vector<BigInt> primef;
        
        if(PrimeList::instance().isPrime(n))
        {
            primef.push_back(n);
            return primef;
        }
        
        BigInt until = BigInt();
        until = n.sqrt();
        until++;
        
        for (std::vector<BigInt>::iterator it = PrimeList::instance().list.begin(); (*it) <= until && it!=PrimeList::instance().list.end(); ++it){
            if(n % (*it) == 0)
                primef.push_back(*it);
        }
        
        return primef; 
    }

    vector<BigInt> unifyFactorLists(const vector<BigInt> &a, const vector<BigInt> &b){
        vector<BigInt> result;
        
        int ita = 0;
        int itb = 0;

        for(;ita < a.size() && itb < b.size();){
            if(a[ita]== b[itb]){
                result.push_back(a[ita]);
                ita++;
                itb++;
            }
            else if(a[ita] > b[itb]){
                result.push_back(b[itb]);
                itb++;
            }
            else {
                result.push_back(a[ita]);
                ita++;
            }
        }
        while(ita < a.size()){
            result.push_back(a[ita]);
            ita++;
        }
        while(itb < b.size()){
            result.push_back(b[itb]);
            itb++;
        }
        return result;
    }

    BigInt getDivisorCount(BigInt& a){
        vector<BigInt> pf = getPrimeFactors(a);
        BigInt n = BigInt(1);

        for (std::vector<BigInt>::iterator it = pf.begin(); it!=pf.end(); ++it){
            for(BigInt i = BigInt(1);;i++){
                if(a / ((*it)*i) == 1)
                {
                    n*= (i+1);
                    break;
                }
            }
        }
        return n;
    }


    BigInt d(BigInt& a,BigInt& b){
        vector<BigInt> pfa = getPrimeFactors(a);
        vector<BigInt> pfb = getPrimeFactors(b);
        vector<BigInt> pf = unifyFactorLists(pfb,pfa);

        set<BigInt,BigInt::BigInt_compare> dSet;
        dSet.insert(BigInt(1));

        BigInt result = BigInt(0);
        BigInt target = a*b;

        for (std::vector<BigInt>::iterator it = pf.begin(); it!=pf.end(); ++it){
            for(BigInt i = 1;;i++)
            {
                if(target %((*it)*i) == 0)
                {
                    dSet.insert((*it)*i);
                }
                if(((*it)*i) == target) break;
            }
        }

        //cout << "printSet" << endl;
        //printSet(dSet);
        //cout << "printSet end" << endl;
        for (set<BigInt,BigInt::BigInt_compare>::iterator it = dSet.begin(); it!=dSet.end(); ++it){
            result += *it; 
        }

        return result;
    }

    set<BigInt,BigInt::BigInt_compare> getDivisor(BigInt& a){
        vector<BigInt> pf = getPrimeFactors(a);
        set<BigInt,BigInt::BigInt_compare> result;

        result.insert(BigInt(1));
        for (std::vector<BigInt>::iterator it = pf.begin(); it!=pf.end(); ++it){
            for(BigInt i = 1;;i++)
            {
                if(a %((*it)*i) == 0)
                {
                    result.insert((*it)*i);
                }
                if(a / ((*it)*i) == 1) break;
            }
        }

        return result;
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

    void PrimeList::printList(){
        for (vector<BigInt>::iterator it = list.begin(); it!=list.end(); ++it){
            cout << (*it) << endl;
        }
    }
    
    void printList(vector<BigInt> plist){
        for (vector<BigInt>::iterator it = plist.begin(); it!=plist.end(); ++it){
            cout << (*it) << endl;
        }
    }
    
    void printSet(set<BigInt,BigInt::BigInt_compare> plist){
        for (set<BigInt,BigInt::BigInt_compare>::iterator it = plist.begin(); it!=plist.end(); ++it){
            cout << (*it) << endl;
        }
    }

    bool PrimeList::isPrime(const BigInt &n){
        BigInt until = BigInt();
        until = n.sqrt();
        until++;

        if(until > end)
            calcPrimesUntil(until);

        for (std::vector<BigInt>::iterator it = list.begin(); (*it) <= until && it!=list.end(); ++it){
            //cout << "n: << n << "\n *it: " << *it << "\nn\%*it = " << (n % (*it)) <<endl; 
            if(n % (*it) == 0)
                return 0;
        }
        return 1;
    }
}

