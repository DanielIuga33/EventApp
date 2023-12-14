#include "Service.h"

Service::Service()
{
}

Service::Service(const Repository& repo)
{
	this->repo = repo;
}

void Service::add(std::string n, int cs, int fs)
{
	int rez = 0;
	Event e(n, cs, fs, rez);
	repo.add(e);
}

void Service::remove(std::string n)
{
	repo.remove_by_name(n);
}

void Service::modify(std::string n, std::string nume_nou, int cs_nou, int fs_nou)
{
	int rez = 0;
	Event e(nume_nou, cs_nou, fs_nou, rez);
	repo.modify_by_name(n, e);
}

int Service::find_by_name(std::string nume)
{
	return repo.find_by_name(nume);
}

void Service::transformare_locuri(Event& e, int tr)
{
	std::string nume = e.get_nume();
	int locuri_cs, locuri_fs;
	locuri_cs = e.get_locuri_cs() - tr;
	locuri_fs = e.get_locuri_fs() + tr;
	modify(nume, nume, locuri_cs, locuri_fs);
}

void Service::rezevare_cu_scaune(Event& e, int rez_cs)
{
	Event f(e.get_nume(), e.get_locuri_cs() - rez_cs, e.get_locuri_fs(), e.get_locuri_rez() + rez_cs);
	repo.modify_by_name(e.get_nume(), f);

}

void Service::rezevare_fara_scaune(Event& e, int rez_fs)
{
	Event f(e.get_nume(), e.get_locuri_cs(), e.get_locuri_fs() - rez_fs, e.get_locuri_rez() + rez_fs);
	repo.modify_by_name(e.get_nume(), f);
}

void Service::rezervare_amandoua(Event& e, int rez_cs, int rez_fs)
{
	Event f(e.get_nume(), e.get_locuri_cs() - rez_cs, e.get_locuri_fs() - rez_fs,e.get_locuri_rez() + rez_fs + rez_cs);
	repo.modify_by_name(e.get_nume(), f);
}

Repository& Service::get_repo()
{
	return this->repo;
}
