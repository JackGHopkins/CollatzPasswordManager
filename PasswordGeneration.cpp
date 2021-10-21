#include "PasswordGeneration.h"
#include <random>

std::multimap<int, char> mmap;

void generate(std::string path) {
	std::fstream file;
	file.open(path, std::ios::out | std::ios::in);
	mmap = create_ascii_map();
	generate_length_variance(file);
	generate_combinatorial_variance(file);

	std::string line;

	/*while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string temp_p;

		std::getline(ss, temp_p);
		std::string s = decryption(temp_p);
		std::cout << temp_p << std::endl;
		std::cout << s << std::endl;
		s = encryption(s);
		if(s == temp_p)
			std::cout << "P Cracked" << std::endl;
	}*/
	file.close();
}

void generate_length_variance(std::fstream &file) {
	srand(time(0));
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
			std::random_device rd;
			std::mt19937 r(rd());
			std::shuffle(ascii_values.begin(), ascii_values.end(), r);
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

std::string decryption(std::string e_pword) {
	int offset = 0;
	int iterator = 0;

	std::vector<int> cur_pword;
	std::vector<std::string> possible_pwords;
	
	rec_decrypt(e_pword, iterator, offset, cur_pword, possible_pwords);
	std::string s = possible_pwords[0];
	return s;
}

void rec_decrypt(std::string e_pword, int iterator, int offset, std::vector<int> &cur_pword, std::vector<std::string> &possible_pwords) {
	if (unsigned(iterator) >= unsigned(e_pword.length())) {
		possible_pwords.push_back(std::string(cur_pword.begin(), cur_pword.end()));
		return;
	}
	std::string d1;
	std::string d2;
	std::string d3;
	unsigned int i1 = 0;
	unsigned int i2 = 0;
	unsigned int i3 = 0;
	if (iterator + 1 != e_pword.length()) {
		d1 = (e_pword[iterator + 1] != '0') ? e_pword.substr(iterator, 1) : std::to_string(0);
		i1 = std::stoi(d1);
		if (iterator + 2 != e_pword.length()) {
			d2 = (e_pword[iterator + 2] != '0') ? e_pword.substr(iterator, 2) : std::to_string(0);
			i2 = std::stoi(d2);
			if (iterator + 3 != e_pword.length()) {
				d3 = (e_pword[iterator + 3] != '0') ? e_pword.substr(iterator, 3) : std::to_string(0);
				i3 = std::stoi(d3);
			}
		}
	}

	if (i1 != 0 ) {
		i1 = i1 - offset;
		auto c_val = mmap.equal_range(i1);
		for (auto it = c_val.first; it != c_val.second; it++) {
			if (it->second < offset)
				continue;
			unsigned int e1 = mmap.find(i1)->second;
			cur_pword.push_back(e1);
			iterator++;
			offset = e1;
			rec_decrypt(e_pword, iterator, offset, cur_pword, possible_pwords);
		}
	}

	if (i2 != 0) {
		i2 = i2 - offset;
		auto c_val = mmap.equal_range(i2);
		for (auto it = c_val.first; it != c_val.second; it++) {
			if (it->second < offset)
				continue;
			
			unsigned int e2 = mmap.find(i2)->second;
			cur_pword.push_back(e2);
			iterator += 2;
			offset = e2;
			rec_decrypt(e_pword, iterator, offset, cur_pword, possible_pwords);
		}
	}

	if (i3 != 0) {
		i3 = i3 - offset;
		auto c_val = mmap.equal_range(i3);
		for (auto it = c_val.first; it != c_val.second; it++) {
						if (it->second < offset)
				continue;
			unsigned int e3 = mmap.find(i3)->second;
			cur_pword.push_back(e3);
			iterator += 3;
			offset = e3;
			rec_decrypt(e_pword, iterator, offset, cur_pword, possible_pwords);
		}
	}
}

std::multimap<int, char> create_ascii_map() {
	std::multimap<int, char> mmap;
	for (int i = 1; i < 256; i++) {
		int steps = 0;
		collatz_function(i, steps);
		mmap.insert(std::make_pair(steps, i));
	}

	//for (auto const& i : mmap) {
	//	std::cout << i.first << " (" << i.second << " char)" << '\n';
	//}
	return mmap;
}

