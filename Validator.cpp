#include "Validator.h"

void WriteInColor(unsigned short color, string outputString)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
	cout << outputString;
}

int Validator::validate1(std::string locuri_cs)
{
	try {
		int a = stoi(locuri_cs);
	}
	catch (exception& exc) {
		WriteInColor(4, ("Locurile cu scaune trebuie sa fie reprezenatate prin numere !!!")); 
		WriteInColor(2, " "); 
		std::cout << std::endl;
		return -1;
	}
	return 0;
}

int Validator::validate2(std::string locuri_fs)
{
	try {
		int b = stoi(locuri_fs);
	}
	catch (exception& exc) {
		WriteInColor(4, ("Locurile fara scaune trebuie sa fie reprezenatate prin numere !!!"));
		WriteInColor(2, " ");
		std::cout << std::endl;
		return -1;
	}
	return 0;
}

int Validator::validate3(std::string locuri_cs, std::string locuri_fs)
{
	try {
		int a = stoi(locuri_cs);
	}
	catch (exception& exc) {
		WriteInColor(4, (" Locurile cu scaune trebuie sa fie reprezenatate prin numere !!!"));
		WriteInColor(2, " ");
		std::cout << std::endl;
		return -1;
	}
	
	try {
		int b = stoi(locuri_fs);
	}
	catch (exception& exc) {
		WriteInColor(4, (" Locurile fara scaune trebuie sa fie reprezenatate prin numere !!!"));
		WriteInColor(2, " ");
		std::cout << std::endl;
		return -1;
	}
	return 0;
}

bool Validator::validate_stoi(std::string a)
{
	try {
		int b = stoi(a);
	}
	catch (exception& exc) {
		WriteInColor(4, (" Parametrul dat trebuie sa fie un numar !!!"));
		WriteInColor(2, " ");
		std::cout << std::endl;
		return false;
	}
	return true;
}
