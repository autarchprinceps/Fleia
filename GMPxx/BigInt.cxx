#include <cgmp>

namespace fleiamath {
	class BigInt {
		public:
			BigInt() {
				mpz_init(value);
			}

			BigInt(unsigned long initialValue) {
				mpz_init_set_ui(value, initialValue);
			}

			~BigInt() {
				mpz_clear(value);
			}

			BigInt* operator + (BigInt* a, BigInt* b) {
				BigInt* result = new BigInt();
				mpz_add(result->value, a->value, b->value);
				return result;
			}

			BigInt* operator * (BigInt* a, BigInt* b) {
				BigInt* result = new BigInt();
				mpz_mul(result->value, a->value, b->value);
				return result;
			}

			BigInt* operator - (BigInt* a, BigInt* b) {
				BigInt* result = new BigInt();
				mpz_sub(result->value, a->value, b->value);
				return result;
			}

			BigInt* operator / (BigInt* a, BigInt* b) {
				BigInt* result = new BigInt();
				mpz_tdiv_q(result->value, a->value, b->value);
				return result;
			}

			BigInt* operator % (BigInt* a, BigInt* b) {
				BigInt* result = new BigInt();
				mpz_mod(result->value, a->value, b->value);
				return result;
			}

			BigInt* operator + (BigInt* a, unsigned long b) {
				BigInt* result = new BigInt();
				mpz_add_ui(result->value, a->value, b);
				return result;
			}

			BigInt* operator * (BigInt* a, unsigned long b) {
				BigInt* result = new BigInt();
				mpz_mul_ui(result->value, a->value, b);
				return result;
			}

			BigInt* operator - (BigInt* a, unsigned long b) {
				BigInt* result = new BigInt();
				mpz_sub_ui(result->value, a->value, b);
				return result;
			}

			BigInt* operator / (BigInt* a, unsigned long b) {
				BigInt* result = new BigInt();
				mpz_tdiv_q_ui(result->value, a->value, b);
				return result;
			}

			BigInt* operator % (BigInt* a, unsigned long b) {
				BigInt* result = new BigInt();
				mpz_mod_ui(result->value, a->value, b);
				return result;
			}

			BigInt* operator + (unsigned long a, BigInt* b) {
				BigInt* result = new BigInt();
				mpz_add_ui(result->value, b->value, a);
				return result;
			}

			BigInt* operator * (unsigned long a, BigInt* b) {
				BigInt* result = new BigInt();
				mpz_mul_ui(result->value, b->value, a);
				return result;
			}

			BigInt* operator - (unsigned long a, BigInt* b) {
				BigInt* result = new BigInt();
				BigInt* A = new BigInt(a);
				mpz_sub(result->value, a->value, b->value);
				delete A;
				return result;
			}

			BigInt* operator / (unsigned long a, BigInt* b) {
				BigInt* result = new BigInt();
				BigInt* A = new BigInt(a);
				mpz_tdiv_q(result->value, a->value, b->value);
				delete A;
				return result;
			}

			BigInt* operator % (unsigned long a, BigInt* b) {
				BigInt* result = new BigInt();
				BigInt* A = new BigInt(a);
				mpz_mod(result->value, A->value, b->value);
				delete A;
				return result;
			}

			mpz_t value;
	}
}