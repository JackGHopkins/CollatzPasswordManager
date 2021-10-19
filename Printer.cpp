#include <fstream>
#include "Printer.h"

Printer::Printer() {
	this->path = "Null";
}

Printer::Printer(std::string path) {
	this->path = path;
}

Printer::~Printer(){}

void Printer::print_passwords() {
	this->password_file;
}

std::string Printer::get_path() {
	return this->path;
}