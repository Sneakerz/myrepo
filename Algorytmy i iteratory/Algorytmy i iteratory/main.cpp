#include<iostream>
#include<array>
#include<ctime>
#include<list>
using namespace std;
// Utworz funkcje wpiszOceny() zwracajaca losowe wartosci typu <int> od 1 do 5
int giveMark() 
{
	int mark = rand() % 5 + 1;
	return mark;
}
// Stworz klase Uczen zawierajaca pola ID typu int, oraz kontener na STALA liczbe ocen
class Student 
{
	int id;
	array<int, 5> grades;
public:
	// Utworz konstruktor jednoargumentowy dla obiektu klasy Uczen, ktory przyjmuje
	//wartoœc typu int bedaca ID nowoutworzonego obiektu typu Uczen. Konstruktor powinien ponadto
	//wypelnic kontener z ocenami za pomoca wczesniej zdefiniowanej funkcji wpiszOceny()
	Student(int id_)
		:id(id_)
	{
		for (array<int, 5>::iterator it = grades.begin(); it != grades.end();it++)
		{
			*it = giveMark();
		}

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

};

int main()
{
	srand(time(NULL));
	
	
	
	
}