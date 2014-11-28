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
	explicit CList (std::size_t n);				//
	CList (std::size_t n, const T& val);
	CList (const CList& x);

	CList& operator= (const CList& l);
	void assign (std::size_t n, const T& val);	//fill the list with n elements, each a copy of val

	bool empty ();		//returns true if the list is empty
	size_t size ();		//returns the number of elements of the list

	CNode<T>&	front ();				//reference to the first element
	const CNode<T>&	front () const;		//const reference to the first element

};
}

#endif /* __CLIST_H__ */
