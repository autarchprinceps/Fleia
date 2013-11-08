/*
 * =====================================================================================
 *
 *       Filename:  test.cxx
 *
 *    Description:  Project Euler Problem 439
 *
 *        Created:  08.11.2013 16:19:06
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */

#include "S.h"
#include <iostream>

using namespace std;

int main() {
	cout << (d(BigInt(1)) + d(BigInt(2)) * 2 + d(BigInt(3)) * 2 + d(BigInt(4)) + g(BigInt(6)) * 2 + g(BigInt(9))) << ' ?= 59' << endl; 
	cout << S(BigInt(3)) << ' ?= 59' << endl;
	cout << S(BigInt(1000)) << ' ?= 563576517282' << endl;
	cout << (S(BigInt(10).pow(5)) % BigInt(10).pow(9)) << ' ?= 215766508' << endl;
	cout << (S(BigInt(10).pow(11)) % BigInt(10).pow(9)) << endl;
}