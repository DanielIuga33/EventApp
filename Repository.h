#pragma once
#include "Event.h"
#include <vector>
using namespace std;
class Repository {
private:
	Event* list_of_events;
	int no_events;
	int capacity;
public:
	Repository();
	Repository(const Repository& repo);
	~Repository() = default;

	int get_size();
	vector <Event> get_all();

	void add(const Event e);
	void remove_by_name(std::string nume);
	void modify_by_name(std::string nume_old, const Event e);
	bool exists(const Event& e);
	bool exists_by_name(std::string nume);
	int find(const Event& e);
	int find_by_name(std::string nume);
	Repository& operator=(const Repository& repo);

};