#include "PasswordGeneration.h"

void generate(std::string path) {
	std::fstream file(path);
	file.open(path, std::ios::out | std::ios::in | std::ios::app);
	generate_length_variance(file);
	file.close();
}

void generate_length_variance(std::fstream &file) {
	int lower_b = rand() % 246;
	int x = 1;

	for (int x = 1; x < 101; x++) {
		for (int y = 0; y < 100; y++) {
			int z = 0;
			std::vector<char> pword;
			while (z < x) {
				pword.push_back(rand() % 10 + lower_b); // c in the range lower_b to lower_b + 10
				z++;
			}
			
			std::string s = std::string(pword.begin(), pword.end());
			std::string e_pword = encryption(s);
			file << e_pword << std::endl;
		}
	}
}
void generate_combinatorial_variance() 
{

}
