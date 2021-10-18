#include <iostream>
#include "CollatzEncryption.h"
#include "Main.h"
#include "Printer.h"

std::string password; 
std::string passwordtest;

int main() {
	/*std::string i = encryption("password");
	std::cout << i << std::endl;*/
	start_menu();
}

void start_menu() {
	password = "password.txt";
	passwordtest = "passwordtest.txt";
	int select = 0;
	while (true) {
		std::cout << "PASSWORD ENCRYPTOR" << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "1. Create User" << std::endl;
		std::cout << "2. Check Username and Password" << std::endl;
		std::cout << "3. Password Strength Test" << std::endl;
		std::cout << "4. Quit Program" << std::endl;

		std::cin >> select;

		switch (select)
		{
		default:
			break;
		case 1:
			create_user();
			break;
		case 2:
			check_user();
			break;
		case 3:
			strength_test();
			break;
		case 4:
			exit(0);
		}
	}
}

void create_user() {
	std::string uname;
	std::string upw;
	Printer p(password);
	try {
		if (!p.password_file)
			throw; 
	}
	catch(int e) {
		std::cout << "FileAccessError: Could not access File." << std::endl;
	}
	p.password_file.open(p.get_path(), std::ios::out | std::ios::in | std::ios::app);
	std::cout << "Create Username: ";
	std::cin >> uname;
	find_username(uname);
	std::cout << "Create Password: ";
	std::cin >> upw;

	upw = encryption(upw);

	p.password_file << uname + " " + upw << std::endl;
	p.password_file.close();
}

void check_user() {

}
 
void find_username(std::string uname) {

}

void strength_test() {

}

