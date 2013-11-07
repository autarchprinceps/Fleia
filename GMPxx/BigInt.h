/*
 * =====================================================================================
 *
 *       Filename:  BigInt.h
 *
 *    Description:  
 *
 *        Created:  07.11.2013 08:29:06
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
 #pragma once
 
 #include <gmp.h>

namespace fleiamath {
	class BigInt {
		public:
			BigInt();
			BigInt(const unsigned long initialValue);
			~BigInt();
			mpz_t value;
	};
	BigInt operator + (const BigInt& a, const BigInt& b);
	BigInt operator * (const BigInt& a, const BigInt& b);
	BigInt operator - (const BigInt& a, const BigInt& b);
	BigInt operator / (const BigInt& a, const BigInt& b);
	BigInt operator % (const BigInt& a, const BigInt& b);
	BigInt operator + (const BigInt& a, const unsigned long b);
	BigInt operator * (const BigInt& a, const unsigned long b);
	BigInt operator - (const BigInt& a, const unsigned long b);
	BigInt operator / (const BigInt& a, const unsigned long b);
	BigInt operator % (const BigInt& a, const unsigned long b);
	BigInt operator + (const unsigned long a, const BigInt& b);
	BigInt operator * (const unsigned long a, const BigInt& b);
	BigInt operator - (const unsigned long a, const BigInt& b);
	BigInt operator / (const unsigned long a, const BigInt& b);
	BigInt operator % (const unsigned long a, const BigInt& b);

	BigInt operator += (const BigInt& a, const BigInt& b);
	BigInt operator += (const BigInt& a, const unsigned long b);
	BigInt operator -= (const BigInt& a, const BigInt& b);
	BigInt operator -= (const BigInt& a, const unsigned long b);
	BigInt operator *= (const BigInt& a, const BigInt& b);
	BigInt operator *= (const BigInt& a, const unsigned long b);
	BigInt operator /= (const BigInt& a, const BigInt& b);
	BigInt operator /= (const BigInt& a, const unsigned long b);
	BigInt operator %= (const BigInt& a, const BigInt& b);
	BigInt operator %= (const BigInt& a, const unsigned long b);

	BigInt operator ++ (const BigInt& a);
	BigInt operator -- (const BigInt& a);
	BigInt operator ++ (const BigInt& a, int unused);
	BigInt operator -- (const BigInt& a, int unused);

	bool operator == (const BigInt& a, const BigInt& b);
	bool operator == (const BigInt& a, const unsigned long b);
	bool operator == (const unsigned long a, const BigInt& b);
	bool operator != (const BigInt& a, const BigInt& b);
	bool operator != (const BigInt& a, const unsigned long b);
	bool operator != (const unsigned long a, const BigInt& b);
	bool operator >= (const BigInt& a, const BigInt& b);
	bool operator >= (const BigInt& a, const unsigned long b);
	bool operator >= (const unsigned long a, const BigInt& b);
	bool operator <= (const BigInt& a, const BigInt& b);
	bool operator <= (const BigInt& a, const unsigned long b);
	bool operator <= (const unsigned long a, const BigInt& b);
	bool operator < (const BigInt& a, const BigInt& b);
	bool operator < (const BigInt& a, const unsigned long b);
	bool operator < (const unsigned long a, const BigInt& b);
	bool operator > (const BigInt& a, const BigInt& b);
	bool operator > (const BigInt& a, const unsigned long b);
	bool operator > (const unsigned long a, const BigInt& b);
}
