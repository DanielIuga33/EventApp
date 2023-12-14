#pragma once
#include "Service.h"
#include <Windows.h>
#include <sstream>
#include "Validator.h"

class UI {
private:
	Service srv;
	Validator validator;
public:
	UI(Service& srv, Validator& validator);

	void run();
	void print_menu();
	void showall();

	void adauga();
	void sterge();
	void modifica();
	void transformare_locuri();
	void cautare_dupa_nume();
	void rezervare();

	~UI();
};
