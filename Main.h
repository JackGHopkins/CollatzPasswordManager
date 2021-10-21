#pragma once
#include <any>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string>

#include "CollatzEncryption.h"
#include "PasswordGeneration.h"
#include "Printer.h"
void start_menu();
void create_user();
void check_user();
bool find_username(std::string uname, Printer& p, std::string &pword);
void strength_test();