#pragma once
#include <iostream>
#include <string>
class Event {
private:
	std::string nume;
	int locuri_cs; // cu scaune
	int locuri_fs; // fara scaune
	int locuri_rez;
public:
	// Constructori si destructor
	Event() = default;
	Event(std::string nume, int locuri_cs, int locuri_fs, int rez);
	Event(const Event& e);
	~Event() = default;

	// Setteri si Getteri
	void set_nume(std::string n);
	void set_locuri_cs(int cs);
	void set_locuri_fs(int fs);
	void set_locuri_rezervate(int rz);

	std::string get_nume();
	int get_locuri_cs();
	int get_locuri_fs();
	int get_locuri_rez();

	// Operatori
	bool operator ==(const Event& e);
	Event& operator =(const Event& e);

	friend std::ostream& operator <<(std::ostream& os, const Event& e);
	friend std::istream& operator >>(std::istream& is, Event& e);
};