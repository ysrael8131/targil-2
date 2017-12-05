/*
Targil 2
isreal rechtshaffer 301790283
raz zorno 36786960
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Volunteer
{
public:
	Volunteer() {}
	Volunteer(int i, string n, string a, int s, string h);
	friend istream& operator >> (istream& in, Volunteer& a);
	friend ostream& operator<< (ostream& out, Volunteer& a);
	//func
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
//operator output
ostream& operator<< (ostream& out, Volunteer& a)
{
	out << "id = " << a.getId() << " name = " << a.getName() << " address = " << a.getAddres() << " phone = " << a.getphone() << " city = " << a.getCity();
	return out;
}
//operator input
istream& operator >> (istream& in, Volunteer& a)
{

	int i, p;
	string n, ad, r;
	in >> i >> n >> ad >> p >> r;
	a.setId(i);
	a.setName(n); a.setAddres(ad); a.setphone(p); a.setcity(r);
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

