#include "Teste.h"

void test_entity()
{
	Event e("Party", 10, 20, 0);
	assert(e.get_nume() == "Party");
	assert(e.get_locuri_cs() == 10);
	assert(e.get_locuri_fs() == 20);

	e.set_nume("After Party");
	e.set_locuri_cs(1);
	e.set_locuri_fs(50);

	assert(e.get_nume() == "After Party");
	assert(e.get_locuri_cs() == 1);
	assert(e.get_locuri_fs() == 50);
}

void test_repository()
{
	Event e1("Party 1", 10, 20, 0);
	Event e2("Party 2", 12, 24, 0);
	Event e3("Party 3", 20, 30, 0);
	Repository repo;
	assert(repo.get_size() == 0);
	repo.add(e1);
	assert(repo.get_size() == 1);
	repo.add(e2);
	repo.add(e3);
	assert(repo.get_size() == 3);
	assert(repo.get_all()[0].get_nume() == "Party 1");

	assert(repo.exists(e3) == true);
	repo.remove_by_name("Party 3");
	assert(repo.exists(e3) == false);
	assert(repo.get_size() == 2);

	Event e4("New Party", 100, 200, 0);
	repo.modify_by_name("Party 2", e4);
	assert(repo.get_size() == 2);
	assert(repo.get_all()[1].get_locuri_cs() == 100);
	assert(repo.find(e1) == 0);
}

void test_service()
{
	Service srv;
	Repository repo;
	Event e1("Party1", 10, 20, 0);
	Event e2("Party2", 12, 24, 0);
	Event e3("Party3", 20, 30, 0);
	srv.add("Party1", 10, 20);
	srv.add("Party2", 12, 24);
	srv.add("Party3", 20, 30);
	assert(srv.find_by_name("Party1") == 0);
	srv.transformare_locuri(e2, 12);
	assert(srv.get_repo().get_all()[1].get_locuri_cs() == 0);
	assert(srv.get_repo().get_all()[1].get_locuri_fs() == 36);
	srv.rezervare_amandoua(e3, 20, 30);
	assert(srv.get_repo().get_all()[2].get_locuri_cs() == 0);
	assert(srv.get_repo().get_all()[2].get_locuri_fs() == 0);
	assert(srv.get_repo().get_all()[2].get_locuri_rez() == 50);

}

void test_all()
{
	test_entity();
	test_repository();
	test_service();
}
