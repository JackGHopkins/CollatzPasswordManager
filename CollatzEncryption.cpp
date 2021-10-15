
#include "CollatzEncryption.h"
#include <string>

int encryption(std::string pword) {
	int offset = 0;
	int ec_pword = 0;

	for (unsigned int str_ind = 0; str_ind < pword.length(); str_ind++) {
		int steps = 0;
		collatz_function(pword[str_ind] + offset, steps);
		ec_pword = (offset != 0) ? concatinate(ec_pword, steps) : ec_pword + steps;
		offset = steps;
	}
	return ec_pword;
}


void collatz_function(int n, int& steps) {
	n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
	steps += 1;
	if (n != 1)
		collatz_function(n, steps);
}

int concatinate(int a, int b) {
	std::string s1 = std::to_string(a);
	std::string s2 = std::to_string(b);
	std::string s_concat = s1 + s2;

	int i_concat = std::stoi(s_concat);
	return i_concat;
}
