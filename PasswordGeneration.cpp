#include "PasswordGeneration.h"

void generate(std::string path) {
	std::fstream file;
	file.open(path, std::ios::out | std::ios::in | std::ios::app);
	generate_length_variance(file);
	generate_combinatorial_variance(file);
	file.close();
}

void generate_length_variance(std::fstream &file) {
	int lower_b = rand() % 245 + 1;
	int x = 1;

	for (int x = 1; x < 101; x++) {
		for (int y = 0; y < 100; y++) {
			int z = 0;
			std::vector<char> pword;
			while (z < x) {
				pword.push_back(rand() % 10 + lower_b);
				z++;
			}
			
			std::string s = std::string(pword.begin(), pword.end());
			std::string e_pword = encryption(s);
			file << e_pword << std::endl;
		}
	}
}
void generate_combinatorial_variance(std::fstream& file)
{
	std::vector<int> ascii_values;
	for (auto x = 1; x < 256; x++)
		ascii_values.push_back(x);

	for (int x = 1; x < 101; x++) {
		for (int y = 0; y < 100; y++) {
			int z = 0;
			std::vector<char> pword;
			std::random_shuffle(ascii_values.begin(), ascii_values.end());
			while (z < x) {
				pword.push_back(ascii_values[z]);
				z++;
			}
			std::string s = std::string(pword.begin(), pword.end());
			std::string e_pword = encryption(s);
			file << e_pword << std::endl;
		}
	}
}


