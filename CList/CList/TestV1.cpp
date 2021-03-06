#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IziAssert.h"
#include "CList.h"
#include "TestV1Unsigned.h"

using namespace std;
using namespace nsSdD;
//
//namespace {
//	size_t size(10);
//	
//	//unsigned i;
//	bool constructor1 = true;
//	bool constructor2 = true;
//	bool constructor3 = true;
//	bool equaloperator = true;
//
//	void ConstructorTest() {		
//		cout << "Creation d'une premiere liste remplie de " << value << " dont la taille vaut "<< size
//			 << endl;
//		CList<unsigned>list(size, value);
//		cout << "Termine"
//			<<endl
//			<< "Creation d'une seconde liste en utilisant le constructeur par recopie" 
//			<< endl;
//		CList<unsigned>list2(list);
//		cout << "Termine"
//			<< endl
//			<< "Test de ces deux constructeurs et de l'operateur [] en cours..."
//			<< endl
//			<< endl
//			<< endl;
//
//		for (unsigned i(0); constructor1 && i < size; ++i)
//			constructor1 = list[i] == value;
//
//		for (unsigned i(0); constructor2 && i < size; ++i)
//			constructor2 = list[i] == list2[i];
//
//		IZI_ASSERT(constructor1);
//		IZI_ASSERT(constructor2);
//		
//
//		cout << "Test termine."
//			<<endl
//			<< "Creation d'une liste vide de taille " << size
//			<< endl;
//		CList<unsigned>list3(size);
//		cout << "Termine"
//			<< endl
//			<< "Assignation de toutes les valeurs a " << value << " en utilisant la methode assign()"
//			<< endl;
//		list3.assign(size, value);
//		cout << "Assignation reussie"
//			<< endl
//			<<"Test de ce constructeur et de la methode en cours..."
//			<<endl
//			<< endl
//			<< endl;
//
//		for (unsigned i(0); constructor3 && i < size; ++i)
//			constructor3 = list3[i] == value;
//
//		IZI_ASSERT(constructor3);
//
//		cout << "Termine"
//			<< endl
//			<< "Creation d'une nouvelle liste en se servant de l'operateur ="
//			<< endl;
//		CList<unsigned> list4 = list;
//		cout << "Termine"
//			<< endl
//			<< "Test de l'operateur = en cours..."
//			<< endl
//			<< endl
//			<< endl;
//
//		for (unsigned i(0); equaloperator && i < size; ++i)
//			list4[i] == list[i];
//
//		IZI_ASSERT(equaloperator);
//
//			cout << "Termine"
//				<< endl;
//
//
//			cout << "Fonctionnalites testees :" << endl
//				<< "-Constructeur d'une liste vide" << endl
//				<< "-Constructeur d'une liste vide de taille n" << endl
//				<< "-Constructeur d'une liste remplie d'entiers de taille n" << endl
//				<< "-Constructeur par recopie" << endl
//				<< "-Operateur =" << endl
//				<< "-Operateur []" << endl
//				<< "-Methode assign()" << endl;
//				
//			
//	}//ConstructorTest()
//
//	void EmptyTest(){
//		bool emptylist = true;
//		bool emptyclist = true;
//		bool notemptylist1 = true;
//		bool notemptylist2 = true;
//		cout << "Creation de trois listes, une vide, une remplie d'�l�ments vides et une remplie d'entiers."
//			<< endl;
//		CList<unsigned>list1;
//		const CList<unsigned>clist1;
//		CList<unsigned>list2(size);
//		CList<unsigned>list3(size, value);
//		cout << "Creation terminee, debut des tests de empty()..."
//			<< endl
//			<< endl
//			<< endl;
//
//
//		emptylist = list1.empty();
//		emptyclist = clist1.empty();
//		notemptylist1 = !list2.empty();
//		notemptylist2 = !list3.empty();
//
//		IZI_ASSERT(emptylist);
//		IZI_ASSERT(emptyclist);
//		IZI_ASSERT(notemptylist1);
//		IZI_ASSERT(notemptylist2);
//
//
//		cout << "Termine"
//			<< endl;
//
//		cout << "Fonctionnalite testee :" << endl
//			<< "Methode assign()" << endl;
//
//	}//EmptyTest()
//
//
//	void Size_tTest(){
//		cout << "Creation d'une liste de taille " << size << "."
//			<< endl;
//		CList<unsigned>list(size);
//		const CList<unsigned>clist = list;
//		cout << "Creation terminee, debut du test de la methode size()..."
//			<< endl
//			<< endl
//			<< endl;
//
//		IZI_ASSERT(list.size() == size);
//		IZI_ASSERT(clist.size() == size);
//
//		cout << "Termine"
//			<< endl;
//		cout << "Fonctionalite testee :" << endl
//			<< "Methode size()" << endl;
//
//
//	}//Size_tTest()
//
//	void FrontBackTest(){
//		cout << "Creation d'une liste de taille " << size << " remplie de " << value
//			<< endl;
//		CList<unsigned>list(size, value);
//		const CList<unsigned>clist=list;
//		cout << "Creation terminee, debut des tests de back() et front()"
//			<< endl
//			<< endl
//			<< endl;
//
//		IZI_ASSERT(list.front() == list[0]);
//		IZI_ASSERT(list.back() == list[size - 1]);
//		IZI_ASSERT(clist.front() == list[0]);
//		IZI_ASSERT(clist.back() == list[size - 1]);
//
//		cout << "Termine"
//			<< endl;
//		cout << "Fontionalites testees :" << endl
//			<< "Methode front()" << endl
//			<< "Methode back()" << endl;
//
//
//	}//FrontBackTest()
//
//	void PushPopFrontBackTest(){
//		CList<unsigned>list(size, value);
//		list.push_front(value1);
//
//		IZI_ASSERT(list[0] == value1 && list[1] == value);
//
//		list.pop_front();
//
//		IZI_ASSERT(list[0] == value);
//
//		list.push_back(value1);
//
//		IZI_ASSERT(list[size-1] == value1 && list[size-2] == value);
//
//		list.pop_back();
//
//		IZI_ASSERT(list[size-1] == value);
//	}//PushPopFrontBackTest
//
//	void SwapTest(){
//		bool swapped = true;
//		CList<unsigned>list;
//		CList<unsigned>list1(size, value);
//		CList<unsigned>list2 = list1;
//		list.swap(list1);
//		
//		for (unsigned i(0); swapped && i < size; ++i)
//			swapped = list[i] == list2[i];
//
//		IZI_ASSERT(swapped);
//	}//SwapTest()
//
//	void ResizeTest(){
//		CList<unsigned>list(size);
//		list.resize(size + 2);
//		IZI_ASSERT(list.size() == size + 2);
//		list.resize(size);
//		IZI_ASSERT(list.size() == size);
//	}//ResizeTest()
//
//	void ClearTest(){
//		CList<unsigned>list(size);
//		list.clear();
//		IZI_ASSERT(list.size() == 0);
//	}//ClearTest()
//
//	void RemoveTest(){
//		CList<unsigned>list(size, value);
//		list.remove(value);
//		IZI_ASSERT(list.size() == 0);
//		CList<unsigned>list1(size, value);
//		list1.push_back(value1);
//		list1.push_back(value1 - 5);
//		list1.push_front(value1);
//		list1.edit(true);
//		list1.remove(value);
//		list1.edit(true);
//	}//RemoveTest()
//
//	void InsertTest(){
//		CList<unsigned>list(size, value);
//		list.edit(true);
//		list.insert(size - 3, value1);
//		list.edit(true);
//		IZI_ASSERT(list[size - 4] == value1);
//	}//InsertTest()
//
//	void EraseTest(){
//		CList<unsigned>list;
//		for (unsigned n(0); n < size; ++n) { list.push_back(n); }
//		list.edit(true);
//		list.erase(3);
//		IZI_ASSERT(list[3] == 4);
//	}//EraseTest()
//
//	void UniqueTest(){
//		bool unique = true;
//		CList<unsigned>list;
//		for (unsigned n (0); n < size; ++n) { list.push_back (n);list.push_back(n); }
//		list.edit(true);
//		cout << endl;
//		list.unique();
//		list.edit(true);
//		cout << endl;
//
//		for (unsigned i(2); unique && i < list.size(); ++i)
//			unique = list[i - 1] != list[i - 2] && list[i - 1] != list[i];
//
//		IZI_ASSERT(unique);
//	}//UniqueTest()
//
//	void SortTest(){
//		bool sorted = true;
//		CList<unsigned>list;
//		for (unsigned n = 0; n < 10; ++n)
//			list.push_back(rand() % 10);
//		list.edit(true);
//		list.sort();
//		list.edit(true);
//
//
//		for (unsigned i(0); sorted && i < list.size(); ++i)
//			sorted = list[i] >= list[i + 1];
//
//		IZI_ASSERT(sorted);
//	}//SortTest()
//
//	void MergeTest(){
//		bool merged = true;
//		CList<unsigned>list1; 
//		CList<unsigned>list2;
//		for (unsigned n = 0; n < 10; ++n) 
//		{
//			list1.push_back(rand() % 10);
//			list2.push_back(rand() % 10);
//		}
//		list1.sort();
//		list2.sort();
//		list1.edit(true);
//		list2.edit(true);
//		list1.merge(list2);
//		list1.edit(true);
//
//		for (unsigned i(0); merged && i < list1.size(); ++i)
//			merged = list1[i] >= list1[i + 1];
//	
//		IZI_ASSERT(merged);
//	}//MergeTest()
//
//	void ReverseTest(){
//		bool reversed = true;
//		CList<unsigned>list;
//		CList<unsigned>wlist;
//		for (unsigned n = 0; n < 10; ++n)
//			list.push_back(rand() % 10);
//		wlist = list;
//		list.edit(true);
//		list.reverse();
//		list.edit(true);
//
//		for (unsigned i(0); reversed && i < list.size(); ++i)
//			reversed = list[i] == wlist[9 - i];
//
//		IZI_ASSERT(reversed);
//	}//ReverseTest()
//
//
//	void TestUnsigned(){
//		unsigned value(14);
//		unsigned value1(8);
//		ConstructorTest();
//		EmptyTest();
//		Size_tTest();
//		FrontBackTest();
//		PushPopFrontBackTest();
//		SwapTest();
//		ResizeTest();
//		ClearTest();
//		RemoveTest();
//		InsertTest();
//		EraseTest();
//		UniqueTest();
//		SortTest();
//		MergeTest();
//		ReverseTest();
//
//		char c;
//		cin >> c;
//
//	}//TestUnsigned()
//
//	void TestString(){
//		unsigned value(14);
//		unsigned value1(8);
//		ConstructorTest();
//		EmptyTest();
//		Size_tTest();
//		FrontBackTest();
//		PushPopFrontBackTest();
//		SwapTest();
//		ResizeTest();
//		ClearTest();
//		RemoveTest();
//		InsertTest();
//		EraseTest();
//		UniqueTest();
//		SortTest();
//		MergeTest();
//		ReverseTest();
//
//		char c;
//		cin >> c;
//
//	}//TestString()
//
//
//	void TestCProf(){
//		unsigned value(14);
//		unsigned value1(8);
//		ConstructorTest();
//		EmptyTest();
//		Size_tTest();
//		FrontBackTest();
//		PushPopFrontBackTest();
//		SwapTest();
//		ResizeTest();
//		ClearTest();
//		RemoveTest();
//		InsertTest();
//		EraseTest();
//		UniqueTest();
//		SortTest();
//		MergeTest();
//		ReverseTest();
//
//		char c;
//		cin >> c;
//
//	}//TestCProf()
//
//	
//
//}//namespace
//
/*int main(){

	TestUnsigned();

	return 0;
}*/