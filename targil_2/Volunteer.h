#pragma once
#include <iostream>
#include <string>
using namespace std;

class Volunteer
{
public:
	Volunteer(){}
	Volunteer(int i, string n, string a, int s, string h);
	friend istream& operator >> (istream& in, Volunteer& a);
	friend ostream& operator<< (ostream& out, Volunteer& a);
	
	void setId(int a) { this->id = a; }
	int getId() { return this->id; }
	void setName(string a) { this->name = a; }
	string getName() { return this->name; }
	void setAddres(string a) { this->addres = a; }
	string getAddres() { return this->addres; }
	void setphone(int a) { this->phone = a; }
	int getphone() { return this->phone; }
	void setcity(string a) { this->city = a; }
	string getCity() { return this->city; }
private:
	int id;
	string name;
	string addres;
	int phone;
	string city;
};

ostream& operator<< (ostream& out, Volunteer& a)
{
	out << "id = " << a.getId() << " name = " << a.getName() << " address = " << a.getAddres() << " phone = " << a.getCity() << endl;
	return out;
}

istream& operator >> (istream& in, Volunteer& a)
{
	
	int i, p;
	string n, ad, r;
	in >> i >> n >> ad >> p >> r;
	Volunteer temp(i, n, ad, p, r);
	return in;
}

Volunteer::Volunteer(int i, string n, string a, int s, string h)
{
	this->id = i;
	this->name = n;
	this->addres = a;
	this->phone = s;
	this->city = h;
}

