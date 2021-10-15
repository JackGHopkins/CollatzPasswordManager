#pragma once
#include <iostream>
#include <fstream>

class Printer {
public:
	Printer(std::string);
	~Printer();
	void print_passwords();
private:
	std::fstream password_file;
	std::string path;
};
