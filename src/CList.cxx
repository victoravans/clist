#include "CList.h"


#define CLIST nsSdD::CList<T>

template <class T>
CLIST::CList ()
{

}

template <class T>
CLIST::CList (std::size_t n)
{
	m_Head.setInfo("HEAD");
	m_Head.setNext(m_Tail);

	m_Tail.setInfo("TAIL");
	m_Tail.setPrevious(m_Head)
}

template <class T>
CLIST::CList (std::size_t n, const T& val)
{

}

template <class T>
CLIST::CList (const CList& x)
{

}

template <class T>
CLIST& CLIST::operator= (const CList& l)
{

}

template <class T>
void CLIST::assign (std::size_t n, const T& val)
{

}

template <class T>
bool CLIST::empty ()
{

}

template <class T>
size_t CLIST::size ()
{

}

template <class T>
CNode<T>& CLIST::front ()
{

}

template <class T>
const CNode<T>&	CLIST::front () const
{

}

template <class T>
CNode<T>& CLIST::back ()
{

}

template <class T>
const CNode<T>&	CLIST::back() const
{

}

template <class T>
void CLIST::push_front (const T& val)
{

}

template <class T>
void CLIST::push_back (const T& val)
{

}

template <class T>
void CLIST::pop_front()
{

}

template <class T>
void CLIST::pop_back()
{

}

template <class T>
void CLIST::swap (CList& l)
{

}

template <class T>
void CLIST::resize (std::size_t n, T val = T())
{

}

template <class T>
void CLIST::clear()
{

}

template <class T>
void CLIST::remove (const T& val)
{

}

template <class T>
void CLIST::unique()
{

}

template <class T>
void CLIST::merge (CList& l)
{

}

template <class T>
void CLIST::sort()
{

}

template <class T>
void CLIST::reverse()
{

}
