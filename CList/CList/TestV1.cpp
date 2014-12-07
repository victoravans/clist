#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IziAssert.h"
#include "CList.h"


using namespace std;
using namespace nsSdD;

namespace {
	size_t size(10);
	int value(14);
	int value1(8);
	unsigned i;

	void ConstructorTest() {		
		cout << "Creation d'une premiere liste remplie de " << value << " dont la taille vaut "<< size
			 << endl;
		CList<int>list(size, value);
		cout << "Termine"
			<<endl
			<< "Creation d'une seconde liste en utilisant le constructeur par recopie" 
			<< endl;
		CList<int>list2(list);
		cout << "Termine"
			<< endl
			<< "Test de ces deux constructeurs et de l'operateur [] en cours..."
			<< endl
			<< endl
			<< endl;

		i = rand() % size;
		IZI_ASSERT(list [i] == value);
		IZI_ASSERT(list [i] == list2[i]);
		

		cout << "Test termine."
			<<endl
			<< "Creation d'une liste vide de taille " << size
			<< endl;
		CList<int>list3(size);
		cout << "Termine"
			<< endl
			<< "Assignation de toutes les valeurs a " << value << " en utilisant la methode assign()"
			<< endl;
		list3.assign(size, value);
		cout << "Assignation reussie"
			<< endl
			<<"Test de ce constructeur et de la methode en cours..."
			<<endl
			<< endl
			<< endl;

		i = rand() % size;
		IZI_ASSERT(list3[i] == value);

		cout << "Termine"
			<< endl
			<< "Creation d'une nouvelle liste en se servant de l'operateur ="
			<< endl;
		CList<int> list4 = list;
		cout << "Termine"
			<< endl
			<< "Test de l'operateur = en cours..."
			<< endl
			<< endl
			<< endl;

		i = rand() % size;
		IZI_ASSERT(list4[i] == list[i]);

			cout << "Termine"
				<< endl;


			cout << "Fonctionnalites testees :" << endl
				<< "-Constructeur d'une liste vide" << endl
				<< "-Constructeur d'une liste vide de taille n" << endl
				<< "-Constructeur d'une liste remplie d'entiers de taille n" << endl
				<< "-Constructeur par recopie" << endl
				<< "-Operateur =" << endl
				<< "-Operateur []" << endl
				<< "-Methode assign()" << endl;
				
			char c;
			cin >> c;
	}//ConstructorTest()

	void EmptyTest(){
		cout << "Creation de trois listes, une vide, une remplie d'éléments vides et une remplie d'entiers."
			<< endl;
		CList<int>list1;
		CList<int>list2(size);
		CList<int>list3(size, value);
		cout << "Creation terminee, debut des tests de empty()..."
			<< endl
			<< endl
			<< endl;
		IZI_ASSERT(list1.empty());
		IZI_ASSERT(!list2.empty());
		IZI_ASSERT(!list3.empty());
		cout << "Termine"
			<< endl;

		cout << "Fonctionnalite testee :" << endl
			<< "Methode assign()" << endl;

		char c;
		cin >> c;
	}//EmptyTest()


	void Size_tTest(){
		cout << "Creation d'une liste de taille " << size << "."
			<< endl;
		CList<int>list(size);
		cout << "Creation terminee, debut du test de la methode size()..."
			<< endl
			<< endl
			<< endl;
		IZI_ASSERT(list.size() == size);
		cout << "Termine"
			<< endl;
		cout << "Fonctionalite testee :" << endl
			<< "Methode size()" << endl;

		char c;
		cin >> c;
	}//Size_tTest()

	void FrontBackTest(){
		cout << "Creation d'une liste de taille " << size << " remplie de " << value
			<< endl;
		CList<int>list(size, value);
		cout << "Creation terminee, debut des tests de back() et front()"
			<< endl
			<< endl
			<< endl;
		IZI_ASSERT(list.front() == list[0]);
		IZI_ASSERT(list.back() == list[size - 1]);
		cout << "Termine"
			<< endl;
		cout << "Fontionalites testees :" << endl
			<< "Methode front()" << endl
			<< "Methode back()" << endl;

		char c;
		cin >> c;
	}//FrontBackTest()

	void PushPopFrontBackTest(){
		CList<int>list(size, value);
		list.push_front(value1);
		IZI_ASSERT(list[0] == value1 && list[1] == value);
		list.pop_front();
		IZI_ASSERT(list[0] == value);
		list.push_back(value1);
		IZI_ASSERT(list[size] == value1 && list[size-1] == value);
		list.pop_back();
		IZI_ASSERT(list[size] == value);
	}//PushPopFrontBackTest

	void SwapTest(){
		CList<int>list;
		CList<int>list1(size, value);
		CList<int>list2 = list1;
		list.swap(list1);
		i = rand() % size;
		IZI_ASSERT(list[i] == list2[i]);
	}//SwapTest()

	void ResizeTest(){
		CList<int>list(size);
		list.resize(size + 2);
		IZI_ASSERT(list.size() == size + 2);
		list.resize(size);
		IZI_ASSERT(list.size() == size);
	}//ResizeTest()

	void ClearTest(){
		CList<int>list(size);
		list.clear();
		IZI_ASSERT(list.size() == 0);
	}//ClearTest()

	void RemoveTest(){
		CList<int>list(size, value);
		list.remove(value);
		IZI_ASSERT(list.size() == 0);
		CList<int>list1(size, value);
		list1.push_back(value1);
		list1.push_back(value1 - 5);
		list1.push_front(value1);
		list1.edit();
		list1.remove(value);
		list1.edit();
	}//RemoveTest()

	void InsertTest(){
		CList<int>list(size, value);
		list.edit();
		list.insert(size - 3, value1);
		list.edit();
		IZI_ASSERT(list[size - 3] == value1);
	}//InsertTest()

	void EraseTest(){
		CList<int>list(size);
		for (unsigned n(0); n < size; ++n) { list.insert(n, n); }
		list.edit();
		list.erase(size - 3);
		IZI_ASSERT(list[size - 3] == size - 2);
	}//EraseTest()

	void UniqueTest(){
		CList<int>list(size*2);
		for (unsigned n(0); n < size*2; ++n) { list.insert(n, n/2); }
		list.edit();
		list.unique();
		list.edit();
		i = rand() % size*2 + 2;
		IZI_ASSERT(list[i - 1] != list[i - 2] && list[i - 1] != list[i]);
	}//UniqueTest()

	void SortTest(){
		CList<int>list;
		for (unsigned n = 0; n < 10; ++n)
			list.push_back(rand() % 10);
		list.edit();
		list.sort();
		list.edit();
		i = rand() % 9;
			IZI_ASSERT(list[i] >= list[i + 1]);
	}//SortTest()

	void MergeTest(){
		CList<int>list1; 
		CList<int>list2;
		for (unsigned n = 0; n < 10; ++n) {
			list1.push_back(rand() % 10);
			list2.push_back(rand() % 10);
		}//for()
		list1.sort();
		list2.sort();
		list1.edit();
		list2.edit();
		list1.merge(list2);
		list1.edit();
		i = rand() % 19;
		IZI_ASSERT(list1[i] >= list1[i + 1]);
	}//MergeTest()

	void ReverseTest(){
		CList<int>list;
		CList<int>wlist;
		for (unsigned n = 0; n < 10; ++n)
			list.push_back(rand() % 10);
		wlist = list;
		list.edit();
		list.reverse();
		list.edit();
		i = rand() % 10;
		IZI_ASSERT(list[i] == wlist[9 - i]);
	}//ReverseTest()


	

}//namespace

int main(){
	CList <int> a;
	for (unsigned i = 0; i < 10; ++i)
		a.push_back (rand () % 10);
	a.edit ();
	cout << endl;
	a.sort ();
	a.edit ();

	//ConstructorTest();
	//EmptyTest();
	//Size_tTest();
	//FrontBackTest ();

	char Char;
	std::cin >> Char;
	return 0;
}