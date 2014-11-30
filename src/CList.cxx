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
	m_Tail.setPrevious(m_Head);
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
typename CLIST::CNode& CLIST::front ()
{

}

template <class T>
const typename CLIST::CNode&	CLIST::front () const
{

}

template <class T>
typename CLIST::CNode& CLIST::back ()
{

}

template <class T>
const typename CLIST::CNode&	CLIST::back() const
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
void CLIST::resize (std::size_t n, T val)
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
	for (std::shared_ptr <CNode>i = l.front(); i != l.m_Tail; i = i.getSuivant())
	{
		for (std::shared_ptr <CNode>j = front(); j != m_Tail; j = j.getSuivant())
		{
			if (*i < *j)
			{

			}
		}
	}
}

template <class T>
void CLIST::sort()
{

}

template <class T>
void CLIST::reverse()
{
	//swap head and tail sentinels
	std::shared_ptr <CNode> temp = m_Head;
	m_Head.setNext (m_Tail.getPrevious());
	m_Tail.setPrevious (temp.getNext());

	m_Head.getNext().setPrevious(m_Head);
	m_Tail.getPrevious().setNext(m_Tail);
	//swap next and previous for each CNode of the list
	for (std::shared_ptr <CNode> i = m_Head.getNext(); i != m_Tail; i = i.getSuivant())
	{
		temp = i.getNext();
		i.setNext(i.getPrevious());
		i.setPrevious(temp);
	}
}
