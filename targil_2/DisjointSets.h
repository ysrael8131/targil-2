/*
Targil 2
isreal rechtshaffer 301790283
raz zorno 36786960
*/
#pragma once
#include "Volunteer.h"
#include <list>
#include <map>
#include<algorithm>
class DisjointSets
{
protected:
	class DisNode
	{
	public:
		Volunteer* v;
		DisNode* next;
		DisNode* head;
		//CTOR
		DisNode(Volunteer * vol)
		{

			v = vol;
			next = NULL;
			head = this;
		}
		//DTOR
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
		//Union between 2 representatives
		Representor* operator += (Representor* re);

		//CTOR
		Representor(Volunteer* vol) :DisNode(vol)
		{
			size = 1;
			last = this;
		}
		//DTOR
		~Representor()
		{
			delete last;
			last = NULL;
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

//Union between 2 representatives
DisjointSets::Representor* DisjointSets::Representor::operator+=(Representor* re)
{
	//The pointer last->next points to representor of other group 
	this->last->next = re;
	//update this->last
	this->last = re->last;
	//update head
	re->head = this->head;
	//to update all element in other group that points to representor
	DisNode* temp = re->next;
	for (int i = 0; i < re->size - 1; i++)
	{
		temp->head = this->head;
		temp = temp->next;
	}
	//update size
	this->size += re->size;
	return this;
}
//Build a group with one element
void DisjointSets::makeSet(Volunteer* vol)
{
	Representor* a = new Representor(vol);
	//insert to list
	Representors.push_back(a);
	//map with key ID
	com.insert(pair<int, DisNode*>(vol->getId(), a));
}
// Search the element according to key,and return his representor  
DisjointSets::Representor* DisjointSets::findSet(int checkId)
{
	if (com[checkId])
		return (Representor*)(com[checkId]->head);
	throw "no such volunteer";
}
//union between 2 groups according size of groups
void DisjointSets::unionSets(int id1, int id2)
{
	Representor* rep1 = findSet(id1);
	Representor* rep2 = findSet(id2);
	//if in group one element
	if (rep1->head == rep2->head || rep2->head == rep1->head)
		return;
	if (rep1->size > rep2->size)
	{
		//union
		*rep1 += rep2;
		//remove representor from list
		list<Representor*>::iterator it = Representors.begin();
		for (; it != Representors.end(); it++)
		{
			if ((*it)->v->getId() == id2)
			{
				Representors.remove(*it);
				return;
			}
		}
	}
	else
	{
		*rep2 += rep1;
		list<Representor*>::iterator it = Representors.begin();
		for (; it != Representors.end(); it++)
		{
			if ((*it)->v->getId() == id1)
			{
				Representors.remove(*it);
				return;
			}
		}
	}

}
//delete element
void DisjointSets::delVolunteer(int id)
{

	Representor* rep1 = findSet(id);
	//If the group has one element  
	if (rep1->size == 1)
	{
		Representors.remove(rep1);
		return;
	}
	DisNode*p = rep1;
	DisNode* a = rep1->next;
	//if remove the representor
	if (rep1->v->getId() == id&&rep1->next != NULL)
	{
		rep1->v->setId(rep1->next->v->getId());
		rep1->v->setName(rep1->next->v->getName());
		rep1->v->setAddres(rep1->next->v->getAddres());
		rep1->v->setphone(rep1->next->v->getphone());
		rep1->v->setcity(rep1->next->v->getCity());
		rep1->next = a->next;
		delete a;
		return;
	}
	while (p->v->getId() != id)
	{
		p = p->next;
		a = a->next;
	}
	p->next = a->next;
	rep1->size -= 1;
	delete a;

	com.erase(id);


}
//print all volunteers according id of one from group
void DisjointSets::printSet(int id)
{

	Representor* rep = findSet(id);
	DisNode* p = rep;
	while (p)
	{
		cout << p->v->getName() << " ";
		p = p->next;
	}
	cout << endl;
}
//print names of all representor
void DisjointSets::printRepresentatives()
{
	list<Representor*>::iterator it = Representors.begin();
	for (; it != Representors.end(); it++)
	{
		cout << (*it)->v->getName() << " ";
	}
	cout << endl;
}
//print all volunteers
void DisjointSets::printAllVolunteers()
{
	list<Representor*>::iterator it = Representors.begin();
	for (; it != Representors.end(); it++)
	{
		DisNode*p = *it;
		while (p)
		{
			cout << *p->v;
			p = p->next;
			cout << endl;
		}
		cout << "**********";
		cout << endl;

	}
}
