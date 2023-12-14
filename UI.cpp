#include "UI.h"
#include <iostream>
#include<string.h>
using namespace std;

UI::UI(Service& srv, Validator& validator) : srv{ srv }, validator{ validator } {}

void UI::print_menu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	std::cout << std::endl;
	std::cout << "\t BINE ATI VENIT LA MENIUL DE ORGANIZARE A EVENIMENTELOR !!! \n\n";
	std::cout << "  Comenzile la care aveti acces sunt urmatoarele: \n";
	std::cout << "1. Adauga eveniment \n";
	std::cout << "2. Sterge eveniment \n";
	std::cout << "3. Modifica eveniment \n";
	std::cout << "4. Transformarea unui nr. de locuri în picioare în locuri pe scaun pentru un anumit spectacol \n";
	std::cout << "5. Cautarea unui eveniment dupa nume \n";
	std::cout << "6. Rezervare locuri \n";
	std::cout << "a. Afisare evenimente \n";
	std::cout << "x. Parasire Program \n";
}

void UI::adauga() {
	std::string nume, locuri_cs1, locuri_fs1;
	std::cout << "Dati numele: ";
	std::getline(std::cin >> ws, nume);
	std::cout << "Dati numarul de locuri cu scaune: ";
	std::cin >> locuri_cs1;
	std::cout << "Dati numarul de locuri fara scaune: ";
	std::cin >> locuri_fs1;
	if (validator.validate3(locuri_cs1, locuri_fs1) == 0) {
		int locuri_cs = stoi(locuri_cs1);int locuri_fs = stoi(locuri_fs1);
		if (srv.get_repo().exists_by_name(nume))
			std::cout << "Exista deja acest eveniment !!!\n";
		else
			srv.add(nume, locuri_cs, locuri_fs);
	}
}

void UI::sterge() {
	std::string nume;
	std::cout << "Dati numele evenimentului pe care doresti sa il stergi: ";
	std::getline(std::cin >> ws, nume);
	if (srv.get_repo().exists_by_name(nume))
		srv.remove(nume);
	else
		std::cout << "Nu exista eveniment cu numele dat !!!\n";
}

void UI::modifica() {
	std::string nume_de_modificat, nume_nou, locuri_cs1, locuri_fs1;
	std::cout << "Dati numele evenimentului pe care doresti sa il modifici: ";
	std::getline(std::cin >> ws, nume_de_modificat);
	if (srv.get_repo().exists_by_name(nume_de_modificat)) {
		std::cout << "Dati noul nume: ";
		std::getline(std::cin >> ws, nume_nou);
		if (srv.get_repo().exists_by_name(nume_nou))
			cout << "Exista deja acest eveniment !!!\n";
		else {
			std::cout << "Dati numarul de locuri cu scaune: ";
			std::cin >> locuri_cs1;
			std::cout << "Dati numarul de locuri fara scaune: ";
			std::cin >> locuri_fs1;
			if (validator.validate3(locuri_cs1, locuri_fs1) == 0) {
				int locuri_cs = stoi(locuri_cs1); int locuri_fs = stoi(locuri_fs1);
				srv.modify(nume_de_modificat, nume_nou, locuri_cs, locuri_fs);
			}
		}
	}
	else
		std::cout << "Nu exista evenimentul dat !!!\n";
}

void UI::transformare_locuri() {
	std::string nume, tr1, locuri_cs;
	int poz;
	vector <Event> V = srv.get_repo().get_all();
	std::cout << "Dati numele spectacolului de modificat: ";
	std::getline(std::cin >> ws, nume);
	if (srv.get_repo().find_by_name(nume) != -1) {
		poz = srv.get_repo().find_by_name(nume);
		std::cout << "Dati numarul de locuri pe scaune pe care vreti sa il tranformati in locuri fara: ";
		std::cin >> tr1;
		if (validator.validate_stoi(tr1)) {
			int tr = stoi(tr1);
			if (V[poz].get_locuri_cs() < tr)
				std::cout << "Nu exista suficiente locuri cu scaune !!!\n";
			else {
				srv.transformare_locuri(V[poz], tr);
			}
		}
		else
			std::cout << "Nu exista spectacolul cu numele dat !!!\n";
	}
}

void UI::cautare_dupa_nume()
{
	std::cout << std::endl;
	std::string nume;
	std::cout << "Dati numele spectacolului de cautat: ";
	std::getline(std::cin >> ws, nume);
	vector<Event> V = srv.get_repo().get_all();
	if (srv.get_repo().exists_by_name(nume)) {
		int poz = srv.find_by_name(nume);
		std::cout << "\t Evenimentul gasit este: \n";
		std::cout << V[poz];
	}
	else
		std::cout << "Nu exista evenimentul dat !!!\n";
}

void UI::rezervare()
{
	std::string nume, optiune;
	int rez_cs, rez_fs;
	std::cout << "Dati numele: ";
	std::getline(std::cin >> ws, nume);
	vector<Event> V = srv.get_repo().get_all();
	if (srv.get_repo().exists_by_name(nume)) {
		std::cout << "1. Locuri cu scaune \n";
		std::cout << "2. Locuri fara scaune \n";
		std::cout << "3. Locuri cu scaune, dar si fara\n\n";
		std::cout << "Precizati ce fel de locuri doriti sa rezervati: ";
		cin >> optiune;
		if (optiune == "1") {
			std::cout << "Dati numarul de locuri: ";
			cin >> rez_cs;
			int i = srv.get_repo().find_by_name(nume);
			if (V[i].get_locuri_cs() < rez_cs)
				cout << "Nu exista suficiente locuri !!!";
			else
				srv.rezevare_cu_scaune(V[i], rez_cs);
		}
		else if (optiune == "2") {
			std::cout << "Dati numarul de locuri: ";
			cin >> rez_fs;
			int i = srv.get_repo().find_by_name(nume);
			if (V[i].get_locuri_fs() < rez_fs)
				cout << "Nu exista suficiente locuri !!!";
			else
				srv.rezevare_fara_scaune(V[i], rez_fs);
		}
		else if (optiune == "3") {
			std::cout << "Dati numarul de locuri cu scaune: ";
			cin >> rez_cs;
			std::cout << "Dati numarul de locuri fara scaune: ";
			cin >> rez_fs;
			int i = srv.get_repo().find_by_name(nume);
			if (V[i].get_locuri_cs() < rez_cs || V[i].get_locuri_fs() < rez_fs)
				cout << "Nu exista suficiente locuri !!!";
			else
				srv.rezervare_amandoua(V[i], rez_cs, rez_fs);
		}
		else
			std::cout << "Optiunea este gresita !\n";
	}
}

void UI::showall() {
	std::cout << std::endl;
	vector <Event> V = srv.get_repo().get_all();
	for (int i = 0; i < srv.get_repo().get_size(); i++)
		cout << V[i];
	std::cout << std::endl;
}
void UI::run()
{
	while (true)
	{
		print_menu();
		std::string optiune;
		std::cout << "Alegeti optiunea: ";
		std::cin >> optiune;
		if (optiune == "1")
			adauga();
		else if (optiune == "2")
			if (srv.get_repo().get_size() == 0)
				std::cout << "Nu exista niciun eveniment momentan !\n";
			else
				sterge();
		else if (optiune == "3")
			if (srv.get_repo().get_size() == 0)
				std::cout << "Nu exista niciun eveniment momentan !\n";
			else
				modifica();
		else if (optiune == "4")
			if (srv.get_repo().get_size() == 0)
				std::cout << "Nu exista niciun eveniment momentan !\n";
			else
				transformare_locuri();
		else if (optiune == "5")
			if (srv.get_repo().get_size() == 0)
				std::cout << "Nu exista niciun eveniment momentan !\n";
			else
				cautare_dupa_nume();
		else if (optiune == "6")
			if (srv.get_repo().get_size() == 0)
				std::cout << "Nu exista niciun eveniment momentan !\n";
			else
				rezervare();
		else if (optiune == "a")
			if (srv.get_repo().get_size() == 0)
				std::cout << "Nu exista niciun eveniment momentan !\n";
			else
				showall();
		else if (optiune == "x") {
			std::cout << "\t Programul se opreste ";
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 3; ++j) {
					cout << ".";
					Sleep(250);
				}
				std::cout << '\b'; std::cout << '\b'; std::cout << '\b';
				std::cout << " " ; std::cout << " " ; std::cout << " " ;
				std::cout << "\b"; std::cout << "\b"; std::cout << "\b";
			}
			Sleep(850);
			std::cout << "\n"<< "\t    La Revedere! :) \n";
			Sleep(650);
			break;
		}
		else
			std::cout << "Optiune gresita !\n";
	}
}


UI::~UI()
{
}
