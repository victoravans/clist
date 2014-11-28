#ifndef __CLIST_H__
#define __CLIST_H__


#include <cstddef>		//size_t
#include <memory>		//shared_ptr
#include "CNode.h"


namespace nsSdD
{
template <class T>
class CList
{
private:
	std::shared_ptr <CNode<T>> m_Head;	//head sentinel
	std::shared_ptr <CNode<T>> m_Tail;	//tail sentinel

public:
	explicit CList ();							//empty list
	explicit CList (std::size_t n);				//list of n empty elements
	CList (std::size_t n, const T& val);		//list of n elements of value val
	CList (const CList& x);						//list copied of another list

	CList& operator= (const CList& l);			//duplicates every element of list l to create another one
	void assign (std::size_t n, const T& val);	//fills the list with n elements, each a copy of val

	bool empty ();		//returns true if the list is empty
	size_t size ();		//returns the number of elements of the list

	CNode<T>&	front ();				//reference to the first element
	const CNode<T>&	front () const;		//const reference to the first element

	CNode<T>&	back ();				//reference to the last element
	const CNode<T>&	back() const;		//const reference to the last element

	void push_front (const T& val);		//inserts an element at the beginning of the list (after the head sentinel)
	void push_back (const T& val);		//inserts an element at the end of the list (before the tail sentinel)
	void pop_front();	//deletes the first element of the list
	void pop_back();	//deletes the last element of the list

	void swap (CList& l);	//exchanges the content of the list with l's
	void resize (std::size_t n, T val = T());	//resizes the list to n elements. Delete or create cnodes
	void clear();	//sets list's size to 0

	void remove (const T& val);	//removes list's elements of value val
	void unique();	//removes all but the first element of consecutive group of equal elements

	void merge (CList& l); //transfers all of l's elements in the list, requieres ordered lists. l then becomes empty
	void sort();	//sorts the list using operator<
	void reverse();	//reverse the order of the elements in the list


};
}

#endif /* __CLIST_H__ */
