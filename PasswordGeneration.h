#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include "CollatzEncryption.h"

void generate(std::string path);
void generate_length_variance(std::fstream &file);
void generate_combinatorial_variance(std::fstream& file);
std::string decryption(std::string e_pword);
void rec_decrypt(std::string e_pword, int iterator, int offset, std::vector<int> &cur_pword, std::vector<std::string> &possible_pwords);
std::multimap<int, char> create_ascii_map();
