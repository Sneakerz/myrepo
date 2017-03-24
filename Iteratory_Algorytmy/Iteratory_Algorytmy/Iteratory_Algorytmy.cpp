// Iteratory_Algorytmy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>
#include <numeric>
#include <ctime>
#include <string>



using namespace std;

class Student {
public:
	int id;
	vector<int> oceny;
	float srednia = 0;

	Student(int i = 0) :id(i) {
		for (int i = 0; i < 5; i++) {
			oceny.push_back((rand() % 4) + 2);
		}
	};

	~Student() {
		oceny.clear();
	};

	void PrzypiszID(int i) {
		id = i;
	}


	void Wyswietl() {
		cout << "Student o id = " << id <<" i sredniej = "<<srednia<< endl;
		for (auto iter = oceny.begin(); iter != oceny.end(); iter++)
			cout << *iter << " ";

		cout << endl << endl;
	}

	void LiczSrednia() {


		srednia = (float)accumulate(oceny.begin(), oceny.end(), 0) / oceny.size();
		//cout << "Nowa srednia = " << srednia << endl;
	}


};





class Grupa {

	string nazwa;
	int idG;
	list<Student> lista;
	float sredniaG=0;
public:

	Grupa(string n, int id) : nazwa(n), idG(id) {

		Student *tmp;
		for (int i = 1; i < 6; i++) {
			tmp = new Student;
			lista.push_back(*tmp);
		}	
	}

	~Grupa() {
		lista.clear();
	}


	void PrzypiszID() {
		int i=1;
		for_each(lista.begin(), lista.end(), [&i](Student &iter) {
			iter.PrzypiszID(i);
			i++;
		});
	}

	void LiczSredniaG() {
		for (auto iter = lista.begin();iter != lista.end();iter++)
			iter->LiczSrednia();

		float sum = 0;
		for (auto iter = lista.begin();iter != lista.end();iter++)
			sum += iter->srednia;

		sredniaG = sum / lista.size();
		cout << endl << "Srednia grupy " << idG << " = " << sredniaG << endl;
	}


	void Wyswietl() {
		cout << "Grupa " << nazwa << " o id = " << idG << endl;

		for_each(lista.begin(), lista.end(), [](Student iter) {
			iter.Wyswietl();

		});
	}

	void Sort() {
		lista.sort([](Student a, Student b) {
			if (a.srednia < b.srednia) return true;
			return false;
		});

	}


};






int main()
{
	srand(time(NULL));
	

	Grupa moja("Fajna", 3);
	moja.PrzypiszID();
	moja.LiczSredniaG();
	cout << endl;
	moja.Sort();
	moja.Wyswietl();

	getchar();

	

    return 0;
};
