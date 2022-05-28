#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Student
{
	string id;
	string Fname;
	string Lname;
public:
	Student(string ID = "0", string F_name = "", string L_name = "")//ctor with a defult values 
		:id(ID), Fname(F_name), Lname(L_name) {}
	bool operator < (Student S) {
		if (S.Lname == this->Lname) return this->Fname < S.Fname;
		return this->Lname < S.Lname;
	}
	bool operator <= (Student S) {
		if (S.Lname == this->Lname) return this->Fname <= S.Fname;
		return this->Lname <= S.Lname;
	}
	bool operator > (Student S) {
		if (S.Lname == this->Lname) return this->Fname > S.Fname;
		return this->Lname > S.Lname;
	}
	bool operator >= (Student S) {
		if (S.Lname == this->Lname) return this->Fname >= S.Fname;
		return this->Lname >= S.Lname;
	}
	bool operator == (Student S) {
		return this->Fname == S.Fname && this->Lname == S.Lname && this->id == S.id;
	}
	void operator =(Student S) { this->id = S.id;this->Fname = S.Fname;this->Lname = S.Lname; }
	string getID() { return id; }
	friend ostream& operator<<(ostream& out, Student& S) { out << S.id << '\t' << S.Fname << '\t' << S.Lname;return out; }
	friend istream& operator>>(istream& in, Student& S) { in >> S.id >> S.Fname >> S.Lname;return in; }

};
