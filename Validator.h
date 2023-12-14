#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


class Validator {
public:
	int validate1(std::string locuri_cs);
	int validate2(std::string locuri_fs);
	int validate3(std::string locuri_cs,std::string locuri_fs);
	bool validate_stoi(std::string a);

};