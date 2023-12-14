#pragma once
#include "Repository.h"
class Service {
private:
	Repository repo;
public:
	Service();
	Service(const Repository& repo);

	void add(std::string n, int cs, int fs);
	void remove(std::string n);
	void modify(std::string n, std::string nume_nou, int cs_nou, int fs_nou);
	int find_by_name(std::string nume);
	void transformare_locuri(Event& e, int tr);
	void rezevare_cu_scaune(Event& e, int rez_cs);
	void rezevare_fara_scaune(Event& e, int rez_fs);
	void rezervare_amandoua(Event& e, int rez_cs, int rez_fs);
	Repository& get_repo();
};
