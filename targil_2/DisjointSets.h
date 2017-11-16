#pragma once
#include "Volunteer.h"
#include <list>
#include <map>

class DisjointSets
{
protected:
	class DisNode
	{
	public:
		Volunteer* v;
		DisNode* next;
		DisNode* head;
		DisNode(Volunteer * vol)
		{
			v = new Volunteer();
			v = vol;
			next = NULL;
			head = this;
		}
		~DisNode()
		{
			delete v;
			delete head;
			delete next;
			v = NULL;
			head = NULL;
			next = NULL;
		}

		bool operator<(DisNode* a)
		{
			return v->getId() < (a->v)->getId();
		}
	};

	class Representor : public DisNode
	{
	public:
		DisNode* last;
		int size;
		Representor(Volunteer* vol) :DisNode(vol)
		{
			size = 1;
			last = this;
		}
		~Representor()
		{
			delete last;
			last = NULL;
		}

		Representor* operator+=(Representor* re)
		{
			this->last->next = re->head;
			this->last = re->last;
			re->head = this->head;
			DisNode* temp = re->next;
			for (int i = 0; i < re->size - 1; i++)
			{
				temp->head = this->head;
				temp = temp->next;
			}
			this->size += re->size;
		}
	};

public:
	DisjointSets() { Representors.clear(); }
	//~DisjointSets();
	void makeSet(Volunteer* vol);
	Representor* findSet(int id);
	void unionSets(int id1, int id2);
	void delVolunteer(int id);
	void printSet(int id);
	void printRepresentatives();
	void printAllVolunteers();
private:
	list<Representor*> Representors;
	map<int, DisNode*> com;
};

void DisjointSets::makeSet(Volunteer* vol)
{
	Representor* a = new Representor(vol);
	DisNode* b=new DisNode(vol);
	Representors.push_back(a);
	com.insert(pair<int, DisNode*>(vol->getId(),b));
}

DisjointSets::Representor* DisjointSets::findSet(int id)
{
	map<int, DisNode*>::iterator it;
	it = com.find(id);

	if (it != com.end())
	{
		return (Representor*)it->second->head;
	}
	else
	{
		throw "no such volunteer";
	}
}

void DisjointSets::unionSets(int id1, int id2)
{
	Representor* rep1 = findSet(id1);
	Representor* rep2 = findSet(id2);
	if (rep1->size>rep2->size)
	{

	}
	else
	{

	}

}

void DisjointSets::delVolunteer(int id)
{

}
void DisjointSets::printSet(int id)
{

}
void DisjointSets::printRepresentatives()
{

}
void DisjointSets::printAllVolunteers()
{

}