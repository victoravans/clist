/**
* \CList.hxx
* \brief Implémentation de CList
* \author Mathieu MÉRINO
* \date 30/11/14
*
* Définition des fonctions de CList, une classe générique
*
*/

#pragma once

#define CLIST nsSdD::CList<T>


template <class T>
CLIST::CList ():m_Head (make_shared<CNode> ()), m_Tail (make_shared<CNode> ())
{
	m_Head->m_Next = m_Tail;
	m_Tail->m_Previous = m_Head;
}

template <class T>
CLIST::CList (std::size_t n):m_Head (make_shared<CNode> ()), m_Tail (make_shared<CNode> ())
{
	m_Head->m_Next = m_Tail;
	m_Tail->m_Previous = m_Head;
	resize (n);
}

template <class T>
CLIST::CList (std::size_t n, const T& val):m_Head (make_shared<CNode> ()), m_Tail (make_shared<CNode> ())
{
	m_Head->m_Next = m_Tail;
	m_Tail->m_Previous = m_Head;
	resize (n, val);
}

template <class T>
CLIST::CList (const CList& l):m_Head (make_shared<CNode> ()), m_Tail (make_shared<CNode> ())
{
	size_t lSize = l.size();
	m_Head->m_Next = m_Tail;
	m_Tail->m_Previous = m_Head;
	if (lSize != size())
		resize(lSize);
	
	std::shared_ptr <CNode> i = m_Head;
	std::shared_ptr <CNode> j = l.m_Head;
	for (; i != m_Tail; i = i->m_Next, j = j->m_Next)
		i->m_Info = j->m_Info;
}

template <class T>
CLIST& CLIST::operator= (const CList& l)
{
	size_t lSize = l.size();
	if (lSize != size())
		resize (lSize);

	std::shared_ptr <CNode> i = m_Head;
	std::shared_ptr <CNode> j = l.m_Head;
	for (;i != m_Tail; i = i->m_Next, j=j->m_Next)
		i->m_Info = j->m_Info;
	return *this;
}

template <class T>
void CLIST::assign (std::size_t n, const T& val)
{
	size_t Size = size();
	if (n < Size)
	{
		resize (n);
		for (std::shared_ptr<CNode> i = m_Head->m_Next; i != m_Tail; i = i->m_Next)
			i->m_Info = val;
	}
	else
	{
		for (std::shared_ptr<CNode> i = m_Head->m_Next; i != m_Tail; i = i->m_Next)
			i->m_Info = val;
		if (n != Size) resize (n, val);
	}
}

template <class T>
bool CLIST::empty () const
{
	return m_Head->m_Next == m_Tail;
}

template <class T>
size_t CLIST::size () const
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
	return *(m_Tail->m_Previous);
}

template <class T>
const typename CLIST::CNode& CLIST::back () const
{
	return *(m_Tail->m_Previous);
}

template <class T>
typename CLIST::CNode&	CLIST::operator[] (std::size_t position)
{
	size_t Size = size ();
	if (position > size () - 1)
		throw std::out_of_range ("Trying to access an element out of the CList's range!");
	std::shared_ptr <CNode> ptr;
	std::size_t i;
	if (position > Size)
	{
		ptr = m_Tail->m_Previous;
		i = Size - 1;
	}
	else
	{
		ptr = m_Head->m_Next;
		i = 0;
	}
	while (true)
	{
		if (i == position) return *ptr;
		if (position > Size)
		{
			ptr = ptr->m_Previous;
			--i;
		}
		else
		{
			ptr = ptr->m_Next;
			++i;
		}
	}
}

template <class T>
const typename CLIST::CNode& CLIST::operator[] (std::size_t position) const
{
	size_t Size = size ();
	if (position > size () - 1)
		throw std::out_of_range ("Trying to access an element out of the CList's range!");
	std::shared_ptr <CNode> ptr;
	std::size_t i;
	if (position > Size)
	{
		ptr = m_Tail->m_Previous;
		i = Size - 1;
	}
	else
	{
		ptr = m_Head->m_Next;
		i = 0;
	}
	while (true)
	{
		if (i == position) return *ptr;
		if (position > Size)
		{
			ptr = ptr->m_Previous;
			--i;
		}
		else
		{
			ptr = ptr->m_Next;
			++i;
		}
	}
}
template <class T>
void CLIST::push_front (const T& val)
{
	m_Head->m_Next->m_Previous = std::make_shared <CNode> (val, m_Head->m_Next, m_Head);
	m_Head->m_Next = m_Head->m_Next->m_Previous;
}

template <class T>
void CLIST::push_back (const T& val)
{
	m_Tail->m_Previous->m_Next = std::make_shared <CNode> (val, m_Tail, m_Tail->m_Previous);
	m_Tail->m_Previous = m_Tail->m_Previous->m_Next;
}

template <class T>
void CLIST::pop_front()
{
	if (m_Head->m_Next == m_Tail) return;
	m_Head->m_Next = m_Head->m_Next->m_Next;
	m_Head->m_Next->m_Previous = m_Head;
}

template <class T>
void CLIST::pop_back()
{
	if (m_Head->m_Next == m_Tail) return;
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
void CLIST::resize (std::size_t n, T val /* = T() */)
{
	size_t Size = size();
	push_back (val);
	if (n > ++Size)
		while (Size++ < n)
			push_back (val);

	else if (n < Size)
		for (size_t i = Size; i > n; --i)
		{
			m_Tail->m_Previous->m_Previous->m_Next = m_Tail;
			m_Tail->m_Previous = m_Tail->m_Previous->m_Previous;
		}
}

template <class T>
void CLIST::clear()
{
	if (size () == 0) return;
	for (std::shared_ptr <CNode>i = m_Head->m_Next->m_Next;; i = i->m_Next)
	{
		i->m_Previous->m_Next = nullptr;
		i->m_Previous->m_Previous = nullptr;
		if (i == m_Tail)
		{
			m_Head->m_Next = i;
			i->m_Previous = m_Head;
		}
	}
}

template <class T>
void CLIST::remove (const T& val)
{
	for (std::shared_ptr <CNode>i = m_Head->m_Next; i != m_Tail; i = i->m_Next)
		if (i->m_Info == val)
		{
			i->m_Previous->m_Next = i->m_Next;
			i->m_Next->m_Previous = i->m_Previous;
		}
}

template <class T>
bool CLIST::insert (const T & position, const T & val)
{
	if (size () == 0)
	{
		push_front (val);
		return true;
	}
	for (std::shared_ptr <CNode>i = m_Head; i->m_Next != m_Tail; i = i->m_Next)
		if (i->m_Next->m_Info == position)
		{
			i->m_Next->m_Previous = std::make_shared <CNode> (val, i->m_Next, i);
			i->m_Next = i->m_Next->m_Previous;
			return true;
		}
	return false;
}

template <class T>
void CLIST::erase (const T & position)
{
	if (size () == 0)
		return;
	for (std::shared_ptr <CNode>i = m_Head; i->m_Next != m_Tail; i = i->m_Next)
		if (i->m_Next->m_Info == position)
		{
			i->m_Next->m_Next->m_Previous = i;
			i->m_Next = i->m_Next->m_Next;
			return;
		}
	return;
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
	if (size () <= 1)
		return;
	CList <T> Temp, Buf;
	Temp.push_front (front ());
	pop_front ();
	while (m_Head->m_Next != m_Tail)
	{
		if (Buf.empty ())
		{
			Buf.push_front (front());
			pop_front ();
		}
		if (Buf.back () <= front ())
		{
			Buf.push_back (front ());
			pop_front ();
		}
		else
		{
			Temp.merge (Buf);
		}
	}
	merge (Temp);
}

template <class T>
void CLIST::reverse()
{
	for (std::shared_ptr <CNode>i = m_Head->m_Next; i != m_Tail; i = i-> m_Previous)
		std::swap (i->m_Next, i->m_Previous);

	std::swap (m_Head->m_Next->m_Next, m_Tail->m_Previous->m_Previous);
	std::swap (m_Head->m_Next, m_Tail->m_Previous);
}

template <class T>
void CLIST::edit (bool jumpLines /* = false */) const
{
	for (std::shared_ptr <CNode> i = m_Head->m_Next; i != m_Tail; i = i->m_Next)
	{
		std::cout << i->m_Info;
		if (jumpLines) std::cout << std::endl;
		else std::cout << "; ";
		std::cout << std::flush;
	}
}