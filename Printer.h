#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class Printer {
public:
	std::fstream										password_file;

	Printer();
	Printer(std::string);
	~Printer();

	void print_passwords();
	std::string get_path();

private:
	std::string		path;
};
