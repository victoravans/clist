#include "TestV1String.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IziAssert.h"
#include "CList.h"


using namespace std;
using namespace nsSdD;

namespace {
	size_t size = 10;
}

namespace nsSdD{
	string str1 = "abc";
	string str2 = "def";
	size_t size = 10;

	void StringConstructorTest() {
		bool constructor1 = true;
		bool constructor2 = true;
		bool constructor3 = true;
		bool equaloperator = true;

		cout << "Creation d'une premiere liste remplie de " << str1 << " dont la taille vaut " << size
			<< endl;
		CList<string>list(size, str1);
		cout << "Termine"
			<< endl
			<< "Creation d'une seconde liste en utilisant le constructeur par recopie"
			<< endl;
		CList<string>list2(list);
		cout << "Termine"
			<< endl
			<< "Test de ces deux constructeurs et de l'operateur [] en cours..."
			<< endl
			<< endl
			<< endl;
		for (unsigned i(0); constructor1 && i < size; ++i)
			constructor1 = (list[i].value() == str1);

		for (unsigned i(0); constructor2 && i < size; ++i)
			constructor2 = list[i].value() == list2[i].value();

		IZI_ASSERT(constructor1);
		IZI_ASSERT(constructor2);


		cout << "Test termine."
			<< endl
			<< "Creation d'une liste vide de taille " << size
			<< endl;
		CList<string>list3(size);
		cout << "Termine"
			<< endl
			<< "Assignation de toutes les valeurs a " << str1 << " en utilisant la methode assign()"
			<< endl;
		list3.assign(size, str1);
		cout << "Assignation reussie"
			<< endl
			<< "Test de ce constructeur et de la methode en cours..."
			<< endl
			<< endl
			<< endl;

		for (unsigned i(0); constructor3 && i < size; ++i)
			constructor3 = list3[i].value() == str1;

		IZI_ASSERT(constructor3);

		cout << "Termine"
			<< endl
			<< "Creation d'une nouvelle liste en se servant de l'operateur ="
			<< endl;
		CList<string> list4 = list;
		cout << "Termine"
			<< endl
			<< "Test de l'operateur = en cours..."
			<< endl
			<< endl
			<< endl;

		for (unsigned i(0); equaloperator && i < size; ++i)
			equaloperator = list4[i].value() == list[i].value();

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

	void StringEmptyTest(){
		bool emptylist = true;
		bool emptyclist = true;
		bool notemptylist1 = true;
		bool notemptylist2 = true;
		cout << "Creation de trois listes, une vide, une remplie d'éléments vides et une remplie d'entiers."
			<< endl;
		CList<string>list1;
		const CList<string>clist1;
		CList<string>list2(size);
		CList<string>list3(size, str1);
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


	void StringSize_tTest(){
		cout << "Creation d'une liste de taille " << size << "."
			<< endl;
		CList<string>list(size);
		const CList<string>clist = list;
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

	void StringFrontBackTest(){
		cout << "Creation d'une liste de taille " << size << " remplie de " << str1
			<< endl;
		CList<string>list;
		list.push_back("abc");
		list.push_back("def");
		list.push_back("ghi");
		list.push_back("jkl");
		const CList<string>clist = list;
		cout << "Creation terminee, debut des tests de back() et front()"
			<< endl
			<< endl
			<< endl;

		IZI_ASSERT(list.front().value() == "abc");
		IZI_ASSERT(list.back().value() == "jkl");
		IZI_ASSERT(clist.front().value() == "abc");
		IZI_ASSERT(clist.back().value() == "jkl");

		cout << "Termine"
			<< endl;
		cout << "Fontionalites testees :" << endl
			<< "Methode front()" << endl
			<< "Methode back()" << endl;


	}//FrontBackTest()

	void StringPushPopFrontBackTest(){
		CList<string>list;
		list.push_back("abc");
		list.push_back("def");
		list.push_back("ghi");
		list.push_back("jkl");
		list.push_back("mno");
		list.push_back("pqr");
		
		list.push_front("aaa");

		IZI_ASSERT(list.front().value() == "aaa" && list.front().GetNext().value() == "abc");

		list.pop_front(); list.pop_front();

		IZI_ASSERT(list.front().value() == "def");

		list.push_back("zzz");

		IZI_ASSERT(list.back().value() == "zzz" && list.back().GetPrevious().value() == "pqr");

		list.pop_back(); list.pop_back();

		IZI_ASSERT(list.back().value() == "mno");
	}//PushPopFrontBackTest

	void StringSwapTest(){
		bool swapped = true;
		CList<string>list;
		CList<string>list1(size, str1);
		CList<string>list2 = list1;
		list.swap(list1);

		for (unsigned i(0); swapped && i < size; ++i)
			swapped = list[i].value() == list2[i].value();

		IZI_ASSERT(swapped);
	}//SwapTest()

	void StringResizeTest(){
		CList<unsigned>list(size);
		list.resize(size + 2);
		IZI_ASSERT(list.size() == size + 2);
		list.resize(size);
		IZI_ASSERT(list.size() == size);
	}//ResizeTest()

	void StringClearTest(){
		CList<unsigned>list(size);
		list.clear();
		IZI_ASSERT(list.size() == 0);
	}//ClearTest()

	void StringRemoveTest(){
		CList<string>list(size, str1);
		list.remove(str1);
		IZI_ASSERT(list.size() == 0);
	}//RemoveTest()

	void StringInsertTest(){
		CList<string>list;
		list.push_back("abc");
		list.push_back("def");
		list.push_back("ghi");
		list.push_back("jkl");
		list.push_back("mno");
		list.push_back("pqr");

		list.edit(true);
		list.insert("ghi", "aaa");
		list.edit(true);
		IZI_ASSERT(list[2].value() == "aaa");
	}//InsertTest()

	void StringEraseTest(){
		CList<string>list;
		list.push_back("abc");
		list.push_back("def");
		list.push_back("ghi");
		list.push_back("jkl");
		list.push_back("mno");
		list.push_back("pqr");

		list.edit(true);
		list.erase("def");
		IZI_ASSERT(list[1].value() == "ghi");
	}//EraseTest()

	void StringUniqueTest(){
		bool unique = true;
		CList<string>list;
		list.push_back("abc");
		list.push_back("abc");
		list.push_back("def");
		list.push_back("def");
		list.push_back("ghi");
		list.push_back("ghi");
		list.push_back("jkl");
		list.push_back("jkl");

		list.edit(true);
		cout << endl;
		list.unique();
		list.edit(true);
		cout << endl;

		for (unsigned i(2); unique && i < list.size(); ++i)
			unique = list[i - 1].value() != list[i - 2].value() && list[i - 1].value() != list[i].value();

		IZI_ASSERT(unique);
	}//UniqueTest()

	void StringSortTest(){
		bool sorted = true;
		CList<string>list;
		list.push_back("ghi");
		list.push_back("jkl");
		list.push_back("def");
		list.push_back("abc");

		list.edit(true);
		list.sort();
		list.edit(true);


		for (unsigned i(0); sorted && i < list.size() - 1; ++i)
			sorted = (list[i].value() <= list[i + 1].value());

		IZI_ASSERT(sorted);
	}//SortTest()

	void StringMergeTest(){
		bool merged = true;
		CList<string>list1;
		CList<string>list2;
		list1.push_back("abc");
		list1.push_back("def");
		list1.push_back("ghi");
		list1.push_back("jkl");

		list2.push_back("abc");
		list2.push_back("def");
		list2.push_back("ghi");
		list2.push_back("jkl");

		list1.edit(true);
		list2.edit(true);
		list1.merge(list2);
		list1.edit(true);

		for (unsigned i(0); merged && i < list1.size() - 1; ++i)
			merged = (list1[i].value() <= list1[i + 1].value());
		merged = (list1.size() == 20);
		IZI_ASSERT(merged);
	}//MergeTest()

	void StringReverseTest(){
		bool reversed = true;
		CList<string>list;
		CList<string>wlist;
		list.push_back("abc");
		list.push_back("def");
		list.push_back("ghi");
		list.push_back("jkl");
		wlist = list;

		list.edit(true);
		list.reverse();
		list.edit(true);

		for (unsigned i(0); reversed && i < list.size(); ++i)
			reversed = list[i].value() == wlist[wlist.size()-1 - i].value();

		IZI_ASSERT(reversed);
	}//ReverseTest()

	void TestString(){

		StringConstructorTest();
		StringEmptyTest();
		StringSize_tTest();
		StringFrontBackTest();
		StringPushPopFrontBackTest();
		StringSwapTest();
		StringResizeTest();
		StringClearTest();
		StringRemoveTest();
		StringInsertTest();
		StringEraseTest();
		StringUniqueTest();
		StringSortTest();
		StringMergeTest();
		StringReverseTest();

		char c;
		cin >> c;

	}//TestUnsigned()

}// namespace

int main()
{
	TestString();
	return 0;
}