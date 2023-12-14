#include "Repository.h"

Repository::Repository()
{
	this->no_events = 0;
	this->capacity = 20;
	this->list_of_events = new Event[this->capacity];
}

Repository::Repository(const Repository& repo)
{
	this->list_of_events = repo.list_of_events;
	this->no_events = repo.no_events;
	this->capacity = repo.capacity;
}

int Repository::get_size()
{
	return no_events;
}

vector<Event> Repository::get_all()
{
	vector <Event> V;
	V.reserve(no_events);
	for (int i = 0; i < no_events; i++)
		V.push_back(list_of_events[i]);
	return V;

}

void Repository::add(const Event e)
{
	if (no_events >= capacity) {
		capacity *= 2;
		Event* v = new Event[capacity];
		for (int i = 0; i < this->no_events; i++)
			v[i] = list_of_events[i];
		delete[] this->list_of_events;
	}
	list_of_events[no_events++] = e;
}

void Repository::remove_by_name(std::string nume)
{
	for (int i = 0; i < no_events; i++)
		if (list_of_events[i].get_nume() == nume) {
			int poz = i;
			for (int j = poz; j < no_events; j++)
				list_of_events[j] = list_of_events[j + 1];
			this->no_events--;
			i--;
		}
}

void Repository::modify_by_name(std::string nume_old, const Event e)
{
	for (int i = 0; i < no_events; i++)
		if (list_of_events[i].get_nume() == nume_old)
			list_of_events[i] = e;
}

bool Repository::exists(const Event& e)
{
	for (int i = 0; i < no_events; i++)
		if (list_of_events[i] == e)
			return true;
	return false;
}

bool Repository::exists_by_name(std::string nume)
{
	for (int i = 0; i < no_events; i++)
		if (list_of_events[i].get_nume() == nume)
			return true;
	return false;
}

int Repository::find(const Event& e)
{
	if (exists(e))
		for (int i = 0; i < no_events; i++) {
			if (list_of_events[i] == e)
				return i;
		}
	else return -1;
}

int Repository::find_by_name(std::string nume)
{
	if (exists_by_name(nume))
		for (int i = 0; i < no_events; i++) {
			if (list_of_events[i].get_nume() == nume)
				return i;
		}
	else return -1;
}


Repository& Repository::operator=(const Repository& repo)
{
	if (this != &repo)
	{
		this->capacity = repo.capacity;
		this->no_events = repo.no_events;
		this->list_of_events = repo.list_of_events;
	}
	return *this;
}
