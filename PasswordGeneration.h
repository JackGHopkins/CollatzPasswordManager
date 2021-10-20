#pragma once
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "CollatzEncryption.h"

void generate(std::string path);
void generate_length_variance(std::fstream &file);
void generate_combinatorial_variance(std::fstream& file);
