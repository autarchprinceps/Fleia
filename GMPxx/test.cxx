/*
 * =====================================================================================
 *
 *       Filename:  test.cxx
 *
 *    Description:  
 *
 *        Created:  08.11.2013 08:35:01
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
#include "BigInt.h"
#include <iostream>

using namespace fleiamath;
using namespace std;

int main() {
	BigInt a = BigInt(4);
	BigInt b = BigInt(3);
	cout << "Basic Ops" << endl;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;
	cout << "ints" << endl;
	cout << a + 3 << endl;
	cout << a - 3 << endl;
	cout << a * 3 << endl;
	cout << a / 3 << endl;
    cout << a % 3 << endl;
	cout << 4 + b << endl;
	cout << 4 - b << endl;
	cout << 4 * b << endl;
	cout << 4 / b << endl;
	cout << 4 % b << endl;
	cout << "Comparisons" << endl;
	cout << (a < b) << endl;
	cout << (a <= b) << endl;
	cout << (a > b) << endl;
	cout << (a >= b) << endl;
	cout << (a == b) << endl;
	cout << (a != b) << endl;
	cout << "ints" << endl;
	cout << (a < 3) << endl;
	cout << (a <= 3) << endl;
	cout << (a > 3) << endl;
	cout << (a >= 3) << endl;
	cout << (a == 3) << endl;
	cout << (a != 3) << endl;
	cout << (4 < b) << endl;
	cout << (4 <= b) << endl;
	cout << (4 > b) << endl;
	cout << (4 >= b) << endl;
	cout << (4 == b) << endl;
	cout << (4 != b) << endl;
    cout << "Assignment" << endl;
    cout << (a=b) << endl;
    cout << (a+=b) << endl;
    cout << (a-=b) << endl;
    cout << (a*=b) << endl;
    cout << (a/=b) << endl;
    cout << (a%=b) << endl;
    cout << (a++) << endl;
    cout << (++a) << endl;
    cout << (a--) << endl;
    cout << (--a) << endl;
    cout << a << endl;
	cout << "zero" << endl;
	cout << (a + 0) << endl;
	cout << (a * 0) << endl;
	cout << (a - 0) << endl;
	cout << (a += 0) << endl;
}
