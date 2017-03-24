#include<iostream>
#include<array> 
#include<ctime> // randomization
#include<list>
#include<numeric> // accumulate()
using namespace std;
// Utworz funkcje wpiszOceny() zwracajaca losowe wartosci typu <int> od 1 do 5
int giveMark() 
{
	int mark = rand() % 5 + 1;
	return mark;
}
// Stworz klase Uczen zawierajaca pola ID typu int, kontener na STALA liczbe ocen oraz pole typu double o nazwane srednia
class Student 
{

	int id;
	array<int, 5> grades;
	float mean;

	// Utworz konstruktor jednoargumentowy dla obiektu klasy Uczen, ktory przyjmuje
	//wartoœc typu int bedaca ID nowoutworzonego obiektu typu Uczen. Konstruktor powinien ponadto
	//wypelnic kontener z ocenami za pomoca wczesniej zdefiniowanej funkcji wpiszOceny()
	// oraz obliczy ich srednia korzystajac z algorytmow biblioteki STL
public:
	Student(int id_)
		:id(id_)
	{
		for ( int i=0;i<grades.size();i++)
		{
			grades[i] = giveMark();
		}
		mean = (float)accumulate(grades.begin(), grades.end(),0) / (float)grades.size();

	}
	void print()
	{
		cout << "Student ID: " << id << "\nGrades:";
		for (array<int, 5>::iterator it = grades.begin(); it != grades.end(); it++)
		{
			cout << *it << " ";
		}
		cout << "\nMean: " << mean << endl;
	}
};
// Zdefiniuj klase Klasa/grupa ktora bedzie zawierac pole ID oraz kontener obiektow typu Uczen.
// Napisz konstruktor jednoargumentowy, ktory przyjmie wartosc typu int i przypisze ja do id Klasy/Grupy
// oraz wypelni kontener obiektow typu Uczen 20-30 obiekatmi;
class Group
{
	int id;
	list<Student> students;
public:
	Group(int id_)
		:id(id_)
	{
		for (int i = 0; i < 25; i++)
		{
			students.push_back(Student(i));
		}
	}
	void printAll()
	{
		cout << "Group " << id << " students list:\n";
		for (list<Student>::iterator it = students.begin(); it != students.end(); it++)
		{
			it->print();
			cout << endl;
		}
		cout << "_____________________________" << endl;
	}

};

int main()
{
	srand(time(NULL));
	
	list<Group> groups;
	for (int i = 0; i < 3; i++)
	{
		groups.push_back(Group(i + 1));
	}
	for (list<Group>::iterator it =groups.begin(); it != groups.end(); it++)
	{
		it->printAll();
	}


	
	
	
	
}