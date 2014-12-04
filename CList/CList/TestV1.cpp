#include <iostream>
#include "IziAssert.h"
#include "CList.h"

using namespace std;
using namespace nsSdD;

namespace {
	size_t size(10);
	int value(14);

	void ConstructorTest() {
		cout << "Creation of a first list, which size equals" << size << "and fullfilled with the same int (" << value << ")"
			 << endl;
		CList<int>list(size, value);
		cout << "Done"
			<<endl
			<< "Creation of a second list using the copy constructor" 
			<< endl;
		CList<int>list2(list);
		cout << "Done" 
			<<endl
			<< "Testing in progress"
		   	<< endl;

		for (int i (0); i < size; ++i){
			IZI_ASSERT(list [i] == value);
			IZI_ASSERT(list [i] == list2[i]);
		}//for

		cout << "Done"
			<< "Creation of an empty list, size " << size
			<< endl;
		CList<int>list3(size);
		cout << "Done"
			<< endl
			<< "Assignating all values to " << value << "using assign() method"
			<< endl;
		list3.assign(size, value);
		cout << "Assignation réussie"
			<< endl
			<<"Testing in progress"
			<<endl;

		for (int i(0); i < size; ++i) IZI_ASSERT(list3[i] == value);

		cout << "Done"
			<< endl
			<< "Creation of a new list using operator ="
			<< endl;
		CList<int> list4 = list;
		cout << "Done"
			<< endl
			<< "Testing in progress"
			<< endl;

		for (int i(0); i < size; ++i) IZI_ASSERT(list4[i] == list[i]);

			cout << "Done"
				<< endl;


			cout << "Functionnalities tested :" << endl
				<< "-Constructor of an empty list" << endl
				<< "-Constructor of an empty list, size n" << endl
				<< "-Constructor of a list filed with ints, size n" << endl
				<< "-Recopy constructor" << endl
				<< "- = Operator" << endl
				<< "- [] Operator" << endl
				<< "-assign() method" << endl;
				
	}//ConstructorTest()




	

}//namespace