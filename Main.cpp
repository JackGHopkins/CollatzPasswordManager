#include "Main.h"

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
	catch(const std::invalid_argument& iae) {
		std::cout << "FileAccessError: Could not access File." << std::endl;
	}
	p.password_file.open(p.get_path(), std::ios::out | std::ios::in | std::ios::app);
	std::cout << "Create Username: ";

	std::cin.ignore(); 
	std::getline(std::cin, uname, static_cast<char>(10));
	for (auto c : uname) {
		if (c == ' ') {
			std::cout << "Unacceptable Username. Please remove whitespace when inputing Username." << std::endl;
			return;
		}
	}

	if (!find_username(uname, p, upw)) {
		std::cout << "Create Password: ";
			std::cin >> upw;
			upw = encryption(upw);

			p.password_file << uname + " " + upw << std::endl;
	}
	else {
		std::cout << "Username already taken. Please try again." << std::endl;
	}
	p.password_file.close();
}

void check_user() {
	std::string uname;
	std::string upw;
	Printer p(password);
	
	std::any attempts = 3;

	try {
		if (!p.password_file)
			throw std::invalid_argument("File: " + password + " Not found.");
	}
	catch (const std::invalid_argument& iae) {
		std::cout << "FileAccessError: Could not access File." << std::endl;
	}
	p.password_file.open(p.get_path(), std::ios::in);
	std::cout << "Username: ";
	std::cin >> uname;

	if (find_username(uname, p, upw)){
		std::cout << "Password:";
		std::string temp_p;
		while (true) {
			std::cin >> temp_p;
			temp_p = encryption(temp_p);
			if (temp_p == upw) {
				std::cout << "Password Authenticated." << std::endl;
				break;
			}
			else {
				attempts = std::any_cast<int>(attempts) - 1;
				std::cout << "Password Incorrect. " << std::any_cast<int>(attempts) << " attempts remaining." << std::endl;
			}
			if (std::any_cast<int>(attempts) == 0)
				break;
		}
	}
}

bool find_username(std::string uname, Printer& p, std::string& pword) {
	std::string line;


	std::ifstream file;

	file.open(password);

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string temp_u;
		std::string temp_p;

		std::getline(ss, temp_u, ' ');
		ss >> temp_p;

		if (temp_u == uname) {
			pword = temp_p;
			return true;
		}
	}
	return false;
}

void strength_test() {
	generate(passwordtest);
}

