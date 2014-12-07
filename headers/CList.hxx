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
CLIST::CList (const CList& l) :m_Head (make_shared<CNode> ()), m_Tail (make_shared<CNode> ())
{
	m_Head->m_Next = m_Tail;
	m_Tail->m_Previous = m_Head;
	resize(l.size());
	iterator j = l.begin ();
	for (iterator i = begin (); i != end (); ++i, ++j) *i = *j;
}

template <class T>
CLIST& CLIST::operator= (const CList& l)
{
	resize (l.size ());
	iterator j = l.begin ();
	for (iterator i = begin (); i != end (); ++i, ++j) 
		*i = *j;
	return *this;
}

template <class T>
typename CLIST::iterator CLIST::begin ()
{
	return iterator (m_Head->m_Next);
}

template <class T>
const typename CLIST::iterator CLIST::begin () const
{
	return iterator (m_Head->m_Next);
}

template <class T>
typename CLIST::iterator CLIST::end ()
{
	return iterator (m_Tail);
}

template <class T>
const typename CLIST::iterator CLIST::end () const
{
	return iterator (m_Tail);
}

template <class T>
void CLIST::assign (std::size_t n, const T& val)
{
	size_t Size = size();
	if (n < Size)
	{
		resize (n);
		for (iterator i = begin(); i != end(); ++i)
			*i = val;
	}
	else
	{
		for (iterator i = begin (); i != end (); ++i)
			*i = val;
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
	for (iterator i = begin(); i != m_Tail;++i)
		++count;
	return count;
}

template <class T>
T& CLIST::front ()
{
	return m_Head->m_Next->m_Info;
}

template <class T>
const T& CLIST::front () const
{
	return m_Head->m_Next->m_Info;
}

template <class T>
T& CLIST::back ()
{
	return m_Tail->m_Previous->m_Info;
}

template <class T>
const T& CLIST::back () const
{
	return m_Tail->m_Previous->m_Info;
}

template <class T>
void CLIST::push_front (const T& val)
{
	m_Head->m_Next->m_Previous = std::make_shared <CNode> (val, m_Head->m_Next, m_Head);
	m_Head->m_Next = m_Head->m_Next->m_Previous;
}

template <class T>
template <class... Args>
void CLIST::emplace_front (Args&&... args)
{
	m_Head->m_Next->m_Previous = std::make_shared <CNode> (T (args...), m_Head->m_Next, m_Head);
	m_Head->m_Next = m_Head->m_Next->m_Previous;
}

template <class T>
void CLIST::push_back (const T& val)
{
	m_Tail->m_Previous->m_Next = std::make_shared <CNode> (val, m_Tail, m_Tail->m_Previous);
	m_Tail->m_Previous = m_Tail->m_Previous->m_Next;
}

template <class T>
template <class... Args>
void CLIST::emplace_back (Args&&... args)
{
	m_Tail->m_Previous->m_Next = std::make_shared <CNode> (T (args...), m_Tail, m_Tail->m_Previous);
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
	size_t Size = size ();
	if (Size == n) return;
	if (n > Size)
		while (Size++ < n)
			push_back (val);

	else
		for (size_t i = Size; i > n; --i)
		{
		m_Tail->m_Previous->m_Previous->m_Next = m_Tail;
		m_Tail->m_Previous = m_Tail->m_Previous->m_Previous;
		}
}

template <class T>
void CLIST::clear()
{
	size_t Size = size ();
	if (Size == 0) return;
	for (size_t i = 0; i < Size; ++i)
	{
		m_Head->m_Next = m_Head->m_Next->m_Next;
		m_Head->m_Next->m_Previous = m_Head;
	}
}

template <class T>
void CLIST::splice (iterator position, CList& x)
{
	insert (position, x.begin (), x.end ());
	x.clear ();
}

template <class T>
void CLIST::splice (iterator position, CList& x, iterator i)
{

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
typename CLIST::iterator CLIST::insert (iterator position, const T& val)
{
	position.m_Elmt->m_Previous->m_Next = make_shared <CNode> (val, position.m_Elmt, position.m_Elmt->m_Previous);
	position.m_Elmt->m_Previous = position.m_Elmt->m_Previous->m_Next;
	return iterator (position.m_Elmt->m_Previous);
}

template <class T>
void CLIST::insert (iterator position, std::size_t n, const T& val)
{
	iterator Iter;
	if (n > 0)  Iter = insert (position, val);
	for (size_t i = 1; i < n; ++i, ++Iter)
		Iter.m_Elmt->m_Next = make_shared <CNode> (val, position.m_Elmt, Iter.m_Elmt);
}

template <class T>
template <class InputIterator>
void CLIST::insert (iterator position, InputIterator first, InputIterator last)
{
	iterator Iter = insert (position, T(*first));
	for (++first; first != last; ++first, ++Iter)
		Iter.m_Elmt->m_Next = make_shared <CNode> (T(*first), position.m_Elmt, Iter.m_Elmt);
}

template <class T>
template <class... Args>
typename CLIST::iterator CLIST::emplace (iterator position, Args&&... args)
{
	position.m_Elmt->m_Previous->m_Next = make_shared <CNode> (T(args...), position.m_Elmt, position.m_Elmt->m_Previous);
	position.m_Elmt->m_Previous = position.m_Elmt->m_Previous->m_Next;
	return iterator (position.m_Elmt->m_Previous);
}
template <class T>
typename CLIST::iterator CLIST::erase (iterator position)
{
	position.m_Elmt->m_Next->m_Previous = position.m_Elmt->m_Previous;
	position.m_Elmt->m_Previous->m_Next = position.m_Elmt->m_Next;
	return iterator (position.m_Elmt->m_Next);
}

template <class T>
typename CLIST::iterator CLIST::erase (iterator first, iterator last)
{
	for (; first != last; ++first)
	{
		first.m_Elmt->m_Next->m_Previous = first.m_Elmt->m_Previous;
		first.m_Elmt->m_Previous->m_Next = first.m_Elmt->m_Next;
	}
	return last;
}

template <class T>
void CLIST::unique()
{
	iterator j = begin ();
	++j;
	char C;
	for (iterator i = begin (); j != end () && i != end (); ++i, ++j)
		if (*i == *j)
			j = erase (j);
}

template <class T>
void CLIST::merge (CList& l)
{
	//Cas spécial ou this est vide
	if (size () == 0)
	{
		if (l.size () == 0)
			return;
		T val = l.front (); // Pour ne pas toucher à la référence 
		push_back (val);
		l.pop_front ();
	}
	//On place tous les éléments inférieurs au plus grand éléments de this dans this
	for (iterator i = begin (); i != end (); ++i)
		for (iterator j = l.begin (); j != l.end ();)
		{
			if (! (*i < *j))
			{
				insert (i, *j);
				j = l.erase (l.begin ());
			}
			else break;
		}
	//On place les éléments qui restent à la fin
	if (l.size () > 0)
	{
		//On colle la fin de this au début de l
		m_Tail->m_Previous->m_Next = l.m_Head->m_Next;
		l.m_Head->m_Next->m_Previous = m_Tail->m_Previous;
		//On colle la fin de l à la sentinelle de fin de this
		m_Tail->m_Previous = l.m_Tail->m_Previous;
		l.m_Tail->m_Previous->m_Next = m_Tail;
		//On "referme" l (pointer la tete et la queue l'une sur l'autre)
		l.m_Head->m_Next = l.m_Tail;
		l.m_Tail->m_Previous = l.m_Head;
	}
}

template <class T>
void CLIST::sort()
{
	CList <T> Temp, Buf;
	while (m_Head->m_Next != m_Tail)
	{
		//Insérer le premier élément dans le buffer vide
		Buf.push_front (front ());
		pop_front ();
		//Remplir le buffer d'éléments croissants
		while (!(front() < Buf.back ()))
		{
			Buf.push_back (front());
			pop_front ();
		}
		//Vider le buffer dans Temp en triant
		Temp.merge (Buf);
	}
	//Vider Temp dans this
	swap (Temp);
}

template <class T>
void CLIST::reverse()
{
	if (size () <= 1)
		return;
	for (iterator i = begin (); i != end (); --i)
		std::swap (i.m_Elmt->m_Next, i.m_Elmt->m_Previous);

	std::swap (m_Head->m_Next->m_Next, m_Tail->m_Previous->m_Previous);
	std::swap (m_Head->m_Next, m_Tail->m_Previous);
}

template <class T>
void CLIST::edit (bool jumpLines /* = false */) const
{
	for (iterator i = begin (); i != end (); ++i)
	{
		std::cout << *i;
		if (jumpLines) std::cout << std::endl;
		else std::cout << "; ";
		std::cout << std::flush;
	}
}