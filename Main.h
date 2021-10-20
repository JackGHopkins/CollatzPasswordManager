#pragma once
#include <iostream>
#include "CollatzEncryption.h"
#include "PasswordGeneration.h"
#include "Printer.h"
#include <stdexcept>
#include <stdlib.h>

void start_menu();
void create_user();
void check_user();
bool find_username(std::string uname, Printer& p, std::string &pword);
void strength_test();
std::string space_check(std::string uname);
