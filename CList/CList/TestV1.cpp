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
		CList<int>list1();
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

	

}//namespace

int main(){
	//ConstructorTest();
	//EmptyTest();
	//Size_tTest();
	return 0;
}