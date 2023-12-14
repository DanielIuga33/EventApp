#include "Event.h"
#include "Event.h"

Event::Event(std::string nume, int locuri_cs, int locuri_fs, int rez)
{
	this->nume = nume;
	this->locuri_cs = locuri_cs;
	this->locuri_fs = locuri_fs;
	this->locuri_rez = rez;
}

Event::Event(const Event& e)
{
	this->nume = e.nume;
	this->locuri_cs = e.locuri_cs;
	this->locuri_fs = e.locuri_fs;
	this->locuri_rez = e.locuri_rez;
}

void Event::set_nume(std::string n)
{
	this->nume = n;
}

void Event::set_locuri_cs(int cs)
{
	this->locuri_cs = cs;
}

void Event::set_locuri_fs(int fs)
{
	this->locuri_fs = fs;
}

void Event::set_locuri_rezervate(int rz)
{
	this->locuri_rez = rz;
}

std::string Event::get_nume()
{
	return this->nume;
}

int Event::get_locuri_cs()
{
	return this->locuri_cs;
}

int Event::get_locuri_fs()
{
	return this->locuri_fs;
}

int Event::get_locuri_rez()
{
	return this->locuri_rez;
}

bool Event::operator==(const Event& e)
{
	return (this->nume == e.nume && this->locuri_cs == e.locuri_cs && this->locuri_fs == e.locuri_fs && this->locuri_rez == e.locuri_rez);
}

Event& Event::operator=(const Event& e)
{
	if (this != &e)
	{
		this->nume = e.nume;
		this->locuri_cs = e.locuri_cs;
		this->locuri_fs = e.locuri_fs;
		this->locuri_rez = e.locuri_rez;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Event& e)
{
	if (e.locuri_rez == 0)
		os << "Eveniment -> nume: " << e.nume << ", locuri cu scaune disponibile: " << e.locuri_cs << ", locuri disponibile fara scaune: " << e.locuri_fs << std::endl;
	else
		os << "Eveniment -> nume: " << e.nume << " locuri cu scaune disponibile: " << e.locuri_cs << " locuri disponibile fara scaune: " << e.locuri_fs << " locuri rezervate: " << e.locuri_rez << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Event& e)
{
	std::string nume;
	int locuri_cs, locuri_fs;

	std::cout << "Numele: ";
	is >> nume;

	std::cout << "Locuri disponibile cu scaune: ";
	is >> locuri_cs;

	std::cout << "Locuri disponibile fara scaune: ";
	is >> locuri_fs;

	e.set_nume(nume);
	e.set_locuri_cs(locuri_cs);
	e.set_locuri_fs(locuri_fs);

	return is;
}
