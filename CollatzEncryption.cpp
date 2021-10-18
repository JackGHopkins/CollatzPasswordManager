
#include "CollatzEncryption.h"
#include <string>

std::string encryption(std::string pword) {
	int offset = 0;
	std::string ec_pword;

	for (unsigned int str_ind = 0; str_ind < pword.length(); str_ind++) {
		int steps = 0;
		collatz_function(pword[str_ind] + offset, steps);
		ec_pword = (offset != 0) ? concatinate(ec_pword, steps) : std::to_string(steps);
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

std::string concatinate(std::string s1, int b) {
	std::string s2 = std::to_string(b);
	std::string s_concat = s1 + s2;

	return s_concat;
}
