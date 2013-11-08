/*
 * =====================================================================================
 *
 *       Filename:  BigInt.cxx
 *
 *    Description:  TODO testing
 *
 *        Created:  07.11.2013 08:29:06
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
#include "BigInt.h"

namespace fleiamath {
	BigInt::BigInt() {
		mpz_init(value);
	}

	BigInt::BigInt(const unsigned long initialValue) {
		mpz_init_set_ui(value, initialValue);
	}

	BigInt::~BigInt() {
		mpz_clear(value);
	}

	BigInt::operator string() const {
		char* cstr;
		gmp_asprintf(&cstr, "%Zd", this->value);
		string result = string(cstr);
		free(cstr);
		return result;
	}

	ostream& operator << (ostream& os, const BigInt& a) {
		os << (string)a;
		return os;
	}

	BigInt operator + (const BigInt& a, const BigInt& b) {
		BigInt result = BigInt();
		mpz_add(result.value, a.value, b.value);
		return result;
	}

	BigInt operator * (const BigInt& a, const BigInt& b) {
		BigInt result = BigInt();
		mpz_mul(result.value, a.value, b.value);
		return result;
	}

	BigInt operator - (const BigInt& a, const BigInt& b) {
		BigInt result = BigInt();
		mpz_sub(result.value, a.value, b.value);
		return result;
	}

	BigInt operator / (const BigInt& a, const BigInt& b) {
		BigInt result = BigInt();
		mpz_tdiv_q(result.value, a.value, b.value);
		return result;
	}

	BigInt operator % (const BigInt& a, const BigInt& b) {
		BigInt result = BigInt();
		mpz_mod(result.value, a.value, b.value);
		return result;
	}

	BigInt operator + (const BigInt& a, const unsigned long b) {
		BigInt result = BigInt();
		mpz_add_ui(result.value, a.value, b);
		return result;
	}

	BigInt operator * (const BigInt& a, const unsigned long b) {
		BigInt result = BigInt();
		mpz_mul_ui(result.value, a.value, b);
		return result;
	}

	BigInt operator - (const BigInt& a, const unsigned long b) {
		BigInt result = BigInt();
		mpz_sub_ui(result.value, a.value, b);
		return result;
	}

	BigInt operator / (const BigInt& a, const unsigned long b) {
		BigInt result = BigInt();
		mpz_tdiv_q_ui(result.value, a.value, b);
		return result;
	}

	BigInt operator % (const BigInt& a, const unsigned long b) {
		BigInt result = BigInt();
		mpz_mod_ui(result.value, a.value, b);
		return result;
	}

	BigInt operator + (const unsigned long a, const BigInt& b) {
		BigInt result = BigInt();
		mpz_add_ui(result.value, b.value, a);
		return result;
	}

	BigInt operator * (const unsigned long a, const BigInt& b) {
		BigInt result = BigInt();
		mpz_mul_ui(result.value, b.value, a);
		return result;
	}

	BigInt operator - (const unsigned long a, const BigInt& b) {
		BigInt result = BigInt();
		BigInt A(a);
		mpz_sub(result.value, A.value, b.value);
		return result;
	}

	BigInt operator / (const unsigned long a, const BigInt& b) {
		BigInt result = BigInt();
		BigInt A(a);
		mpz_tdiv_q(result.value, A.value, b.value);
		return result;
	}

	BigInt operator % (const unsigned long a, const BigInt& b) {
		BigInt result = BigInt();
		BigInt A(a);
		mpz_mod(result.value, A.value, b.value);
		return result;
	}

    BigInt& BigInt::operator = (const BigInt& b) {
        mpz_set(this->value, b.value);
        return *this;
    }
    BigInt& BigInt::operator = (const unsigned long b) {
        mpz_set_ui(this->value, b);
        return *this;
    }
	BigInt& operator += (BigInt& a, const BigInt& b) {
        mpz_add(a.value, a.value, b.value);
		return a;
	}
	BigInt& operator += (BigInt& a, const unsigned long b) {
        mpz_add_ui(a.value, a.value, b);
        return a;
	}
	BigInt& operator -= (BigInt& a, const BigInt& b) {
        mpz_sub(a.value, a.value, b.value);
		return a;
	}
	BigInt& operator -= (BigInt& a, const unsigned long b) {
        mpz_sub_ui(a.value, a.value, b);
		return a;
	}
	BigInt& operator *= (BigInt& a, const BigInt& b) {
        mpz_mul(a.value, a.value, b.value);
		return a;
	}
	BigInt& operator *= (BigInt& a, const unsigned long b) {
        mpz_mul_ui(a.value, a.value, b);
		return a;
	}
	BigInt& operator /= (BigInt& a, const BigInt& b) {
        mpz_tdiv_q(a.value, a.value, b.value);
		return a;
	}
	BigInt& operator /= (BigInt& a, const unsigned long b) {
        mpz_tdiv_q_ui(a.value, a.value, b);
		return a;
	}
	BigInt& operator %= (BigInt& a, const BigInt& b) {
        mpz_mod(a.value, a.value, b.value);
		return a;
	}
	BigInt& operator %= (BigInt& a, const unsigned long b) {
        mpz_mod_ui(a.value, a.value, b);
		return a;
	}

	BigInt& operator ++ (BigInt& a) {
		return a;
	}
	BigInt& operator -- (BigInt& a) {
		return a;
	}
	BigInt& operator ++ (BigInt& a, int unused) {
		return a;
	}
	BigInt& operator -- (BigInt& a, int unused) {
		return a;
	}

	bool operator == (const BigInt& a, const BigInt& b) {
		return mpz_cmp(a.value, b.value) == 0;
	}
	bool operator == (const BigInt& a, const unsigned long b) {
		return mpz_cmp_ui(a.value, b) == 0;
	}
	bool operator == (const unsigned long a, const BigInt& b) {
		return mpz_cmp_ui(b.value, a) == 0;
	}
	bool operator != (const BigInt& a, const BigInt& b) {
		return mpz_cmp(a.value, b.value) != 0;
	}
	bool operator != (const BigInt& a, const unsigned long b) {
		return mpz_cmp_ui(a.value, b) != 0;
	}
	bool operator != (const unsigned long a, const BigInt& b) {
		return mpz_cmp_ui(b.value, a) != 0;
	}
	bool operator >= (const BigInt& a, const BigInt& b) {
		return mpz_cmp(a.value, b.value) >= 0;
	}
	bool operator >= (const BigInt& a, const unsigned long b) {
		return mpz_cmp_ui(a.value, b) >= 0;
	}
	bool operator >= (const unsigned long a, const BigInt& b) {
		return mpz_cmp_ui(b.value, a) < 0;
	}
	bool operator <= (const BigInt& a, const BigInt& b) {
		return mpz_cmp(a.value, b.value) <= 0;
	}
	bool operator <= (const BigInt& a, const unsigned long b) {
		return mpz_cmp_ui(a.value, b) <= 0;
	}
	bool operator <= (const unsigned long a, const BigInt& b) {
		return mpz_cmp_ui(b.value, a) > 0;
	}
	bool operator < (const BigInt& a, const BigInt& b) {
		return mpz_cmp(a.value, b.value) < 0;
	}
	bool operator < (const BigInt& a, const unsigned long b) {
		return mpz_cmp_ui(a.value, b) < 0;
	}
	bool operator < (const unsigned long a, const BigInt& b) {
		return mpz_cmp_ui(b.value, a) >= 0;
	}
	bool operator > (const BigInt& a, const BigInt& b) {
		return mpz_cmp(a.value, b.value) > 0;
	}
	bool operator > (const BigInt& a, const unsigned long b) {
		return mpz_cmp_ui(a.value, b) > 0;
	}
	bool operator > (const unsigned long a, const BigInt& b) {
		return mpz_cmp_ui(b.value, a) <= 0;
	}
}
