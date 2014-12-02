#include "CList.h"
#include <unistd.h>



#define CLIST nsSdD::CList<T>



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
	return m_Head->m_Next == m_Tail;
}

template <class T>
size_t CLIST::size ()
{
	size_t count = 0;
	for (std::shared_ptr <CNode> i (m_Head->m_Next); i != m_Tail; i = i->m_Next)
		++count;
	return count;
}

template <class T>
typename CLIST::CNode& CLIST::front ()
{
	return *(m_Head->m_Next);
}

template <class T>
const typename CLIST::CNode& CLIST::front () const
{
	return *(m_Head->m_Next);
}

template <class T>
typename CLIST::CNode& CLIST::back ()
{
	return *(m_Tail.get()->m_Previous);
}

template <class T>
const typename CLIST::CNode& CLIST::back() const
{
	return *(m_Tail.get()->m_Previous);
}

template <class T>
void CLIST::push_front (const T& val)
{
	m_Head->m_Next->m_Previous = std::shared_ptr <CNode>  (new CNode(val, m_Head->m_Next, m_Head));
	m_Head->m_Next = m_Head->m_Next->m_Previous;
}

template <class T>
void CLIST::push_back (const T& val)
{
	m_Tail->m_Previous->m_Next = std::shared_ptr <CNode> (new CNode(val, m_Tail, m_Tail->m_Previous));;
	m_Tail->m_Previous = m_Tail->m_Previous->m_Next;
}

template <class T>
void CLIST::pop_front()
{
	m_Head->m_Next = m_Head->m_Next->m_Next;
	m_Head->m_Next->m_Previous = m_Head;
}

template <class T>
void CLIST::pop_back()
{
	m_Tail->m_Previous= m_Tail->m_Previous->m_Previous;
	m_Tail->m_Previous->m_Next = m_Tail;
}

template <class T>
void CLIST::swap (CList& l)
{
	std::swap (m_Head, l.m_Head);
	std::swap (m_Tail, l.m_Tail);
}

template <class T>
void CLIST::resize (std::size_t n, T val)
{
	if (n > size())
	{
		m_Tail->m_Info = val;
		unsigned i = size();
		std::shared_ptr <CNode> ptr = m_Tail;
		for (; i < n; ++i, ptr = ptr->m_Next)
		{
			ptr->m_Next = std::shared_ptr <CNode> (new CNode (val));
			ptr->m_Next->m_Previous = ptr;
		}
		m_Tail = ptr;
	}
	else if (n < size())
	{

	}
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
	for (std::shared_ptr <CNode>i = m_Head->m_Next; i->m_Next != m_Tail && i != m_Tail; i = i->m_Next)
		if (i->m_Info == i->m_Next->m_Info)
		{
			i->m_Next->m_Next->m_Previous = i;
			i->m_Next = i->m_Next->m_Next;
		}
}

template <class T>
void CLIST::merge (CList& l)
{
	for (std::shared_ptr <CNode>i = m_Head->m_Next; i != m_Tail; i = i->m_Next)
		for (std::shared_ptr <CNode>j = l.m_Head->m_Next; j != l.m_Tail; )
		{
			if (j->m_Info <= i->m_Info)
			{
				l.pop_front();
				j->m_Next = i;
				j->m_Previous = i->m_Previous;
				i->m_Previous->m_Next = j;
				i->m_Previous = j;
				j = l.m_Head->m_Next;
			}
			else break;
		}
	for (std::shared_ptr <CNode>j = l.m_Head->m_Next; j != l.m_Tail; j = l.m_Head->m_Next)
	{
		l.pop_front();
		j->m_Next = m_Tail;
		j->m_Previous = m_Tail->m_Previous;
		m_Tail->m_Previous->m_Next = j;
		m_Tail->m_Previous = j;
	}
}

template <class T>
void CLIST::sort()
{

}

template <class T>
void CLIST::reverse()
{
	for (std::shared_ptr <CNode>i = m_Head->m_Next; i != m_Tail; i = i-> m_Previous)
		std::swap (i->m_Next, i->m_Previous);

	std::swap (m_Head->m_Next->m_Next, m_Tail->m_Previous->m_Previous);
	std::swap (m_Head->m_Next, m_Tail->m_Previous);
}
