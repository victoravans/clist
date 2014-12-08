#include "TestV1Unsigned.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IziAssert.h"
#include "CList.h"


using namespace std;
using namespace nsSdD;

namespace nsSdD{
	unsigned us1(14);
	unsigned us2(8);
	size_t size = 10;

	void ConstructorTest() {
		bool constructor1 = true;
		bool constructor2 = true;
		bool constructor3 = true;
		bool equaloperator = true;

		cout << "Creation d'une premiere liste remplie de " << us1 << " dont la taille vaut " << size
			<< endl;
		CList<unsigned>list(size, us1);
		cout << "Termine"
			<< endl
			<< "Creation d'une seconde liste en utilisant le constructeur par recopie"
			<< endl;
		CList<unsigned>list2(list);
		cout << "Termine"
			<< endl
			<< "Test de ces deux constructeurs et de l'operateur [] en cours..."
			<< endl
			<< endl
			<< endl;

		for (unsigned i(0); constructor1 && i < size; ++i)
			constructor1 = (list[i] == us1);

		for (unsigned i(0); constructor2 && i < size; ++i)
			constructor2 = list[i] == list2[i];

		IZI_ASSERT(constructor1);
		IZI_ASSERT(constructor2);


		cout << "Test termine."
			<< endl
			<< "Creation d'une liste vide de taille " << size
			<< endl;
		CList<unsigned>list3(size);
		cout << "Termine"
			<< endl
			<< "Assignation de toutes les valeurs a " << us1 << " en utilisant la methode assign()"
			<< endl;
		list3.assign(size, us1);
		cout << "Assignation reussie"
			<< endl
			<< "Test de ce constructeur et de la methode en cours..."
			<< endl
			<< endl
			<< endl;

		for (unsigned i(0); constructor3 && i < size; ++i)
			constructor3 = list3[i] == us1;

		IZI_ASSERT(constructor3);

		cout << "Termine"
			<< endl
			<< "Creation d'une nouvelle liste en se servant de l'operateur ="
			<< endl;
		CList<unsigned> list4 = list;
		cout << "Termine"
			<< endl
			<< "Test de l'operateur = en cours..."
			<< endl
			<< endl
			<< endl;

		for (unsigned i(0); equaloperator && i < size; ++i)
			equaloperator = list4[i] == list[i];

		IZI_ASSERT(equaloperator);

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


	}//ConstructorTest()

	void EmptyTest(){
		bool emptylist = true;
		bool emptyclist = true;
		bool notemptylist1 = true;
		bool notemptylist2 = true;
		cout << "Creation de trois listes, une vide, une remplie d'�l�ments vides et une remplie d'entiers."
			<< endl;
		CList<unsigned>list1;
		const CList<unsigned>clist1;
		CList<unsigned>list2(size);
		CList<unsigned>list3(size, us1);
		cout << "Creation terminee, debut des tests de empty()..."
			<< endl
			<< endl
			<< endl;


		emptylist = list1.empty();
		emptyclist = clist1.empty();
		notemptylist1 = !list2.empty();
		notemptylist2 = !list3.empty();

		IZI_ASSERT(emptylist);
		IZI_ASSERT(emptyclist);
		IZI_ASSERT(notemptylist1);
		IZI_ASSERT(notemptylist2);


		cout << "Termine"
			<< endl;

		cout << "Fonctionnalite testee :" << endl
			<< "Methode assign()" << endl;

	}//EmptyTest()


	void Size_tTest(){
		cout << "Creation d'une liste de taille " << size << "."
			<< endl;
		CList<unsigned>list(size);
		const CList<unsigned>clist = list;
		cout << "Creation terminee, debut du test de la methode size()..."
			<< endl
			<< endl
			<< endl;

		IZI_ASSERT(list.size() == size);
		IZI_ASSERT(clist.size() == size);

		cout << "Termine"
			<< endl;
		cout << "Fonctionalite testee :" << endl
			<< "Methode size()" << endl;


	}//Size_tTest()

	void FrontBackTest(){
		cout << "Creation d'une liste de taille " << size << " remplie de " << us1
			<< endl;
		CList<unsigned>list(size, us1);
		const CList<unsigned>clist = list;
		cout << "Creation terminee, debut des tests de back() et front()"
			<< endl
			<< endl
			<< endl;

		IZI_ASSERT(list.front() == list.front());
		IZI_ASSERT(list.back() == list.back());
		IZI_ASSERT(clist.front() == list.front());
		IZI_ASSERT(clist.back() == list.back());

		cout << "Termine"
			<< endl;
		cout << "Fontionalites testees :" << endl
			<< "Methode front()" << endl
			<< "Methode back()" << endl;


	}//FrontBackTest()

	void PushPopFrontBackTest(){
		CList<unsigned>list;
		for (unsigned i = 0; i < 10; list.push_back(i));
		list.push_front(99);

		IZI_ASSERT(list.front() == 99 && list.front().GetNext() == 0);

		list.pop_front(); list.pop_front();

		IZI_ASSERT(list.front() == 1);

		list.push_back(66);

		IZI_ASSERT(list.back() == 66 && list.back().GetPrevious() == 9);

		list.pop_back(); list.pop_back();

		IZI_ASSERT(list.back() == 8);
	}//PushPopFrontBackTest

	void SwapTest(){
		bool swapped = true;
		CList<unsigned>list;
		CList<unsigned>list1(size, us1);
		CList<unsigned>list2 = list1;
		list.swap(list1);

		for (unsigned i(0); swapped && i < size; ++i)
			swapped = list[i] == list2[i];

		IZI_ASSERT(swapped);
	}//SwapTest()

	void ResizeTest(){
		CList<unsigned>list(size);
		list.resize(size + 2);
		IZI_ASSERT(list.size() == size + 2);
		list.resize(size);
		IZI_ASSERT(list.size() == size);
	}//ResizeTest()

	void ClearTest(){
		CList<unsigned>list(size);
		list.clear();
		IZI_ASSERT(list.size() == 0);
	}//ClearTest()

	void RemoveTest(){
		CList<unsigned>list(size, us1);
		list.remove(us1);
		IZI_ASSERT(list.size() == 0);
	}//RemoveTest()

	void InsertTest(){
		CList<unsigned>list;
		for (unsigned i = 0; i < 10; list.push_back(i++));
		list.edit(true);
		list.insert(5, 25);
		list.edit(true);
		IZI_ASSERT(list[5] == 25);
	}//InsertTest()

	void EraseTest(){
		CList<unsigned>list;
		for (unsigned n(0); n < size; ++n) { list.push_back(n); }
		list.edit(true);
		list.erase(3);
		IZI_ASSERT(list[3] == 4);
	}//EraseTest()

	void UniqueTest(){
		bool unique = true;
		CList<unsigned>list;
		for (unsigned n(0); n < size; ++n) { list.push_back(n); list.push_back(n); }
		list.edit(true);
		cout << endl;
		list.unique();
		list.edit(true);
		cout << endl;

		for (unsigned i(2); unique && i < list.size(); ++i)
			unique = list[i - 1] != list[i - 2] && list[i - 1] != list[i];

		IZI_ASSERT(unique);
	}//UniqueTest()

	void SortTest(){
		bool sorted = true;
		CList<unsigned>list;
		for (unsigned n = 0; n < 10; ++n)
			list.push_back(rand() % 10);
		list.edit(true);
		list.sort();
		list.edit(true);


		for (unsigned i(0); sorted && i < list.size() - 1; ++i)
			sorted = (list[i] <= list[i + 1]);

		IZI_ASSERT(sorted);
	}//SortTest()

	void MergeTest(){
		bool merged = true;
		CList<unsigned>list1;
		CList<unsigned>list2;
		for (unsigned n = 0; n < 10; ++n)
		{
			list1.push_back(rand() % 10);
			list2.push_back(rand() % 10);
		}
		list1.sort();
		list2.sort();
		list1.edit(true);
		list2.edit(true);
		list1.merge(list2);
		list1.edit(true);

		for (unsigned i(0); merged && i < list1.size() - 1; ++i)
			merged = (list1[i] <= list1[i + 1]);
		merged = (list1.size() == 20);
		IZI_ASSERT(merged);
	}//MergeTest()

	void ReverseTest(){
		bool reversed = true;
		CList<unsigned>list;
		CList<unsigned>wlist;
		for (unsigned n = 0; n < 10; ++n)
			list.push_back(rand() % 10);
		wlist = list;
		list.edit(true);
		list.reverse();
		list.edit(true);

		for (unsigned i(0); reversed && i < list.size(); ++i)
			reversed = list[i] == wlist[9 - i];

		IZI_ASSERT(reversed);
	}//ReverseTest()

	void TestUnsigned(){
		ConstructorTest();
		::sleep (1);
		EmptyTest();
		::sleep (1);
		Size_tTest();
		::sleep (1);
		FrontBackTest();
		::sleep (1);
		PushPopFrontBackTest();
		::sleep (1);
		SwapTest();
		::sleep (1);
		ResizeTest();
		::sleep (1);
		ClearTest();
		::sleep (1);
		RemoveTest();
		::sleep (1);
		InsertTest();
		::sleep (1);
		EraseTest();
		::sleep (1);
		UniqueTest();
		::sleep (1);
		SortTest();
		::sleep (1);
		MergeTest();
		::sleep (1);
		ReverseTest();
		
		char c;
		cin >> c;
		
	}//TestUnsigned()

}// namespace

/*int main()
{
	TestUnsigned();
	return 0;
}*/
