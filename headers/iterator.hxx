#define ITER nsSdD::CList<T>::iterator
#define CLIST nsSdD::CList<T>


template <class T>
ITER::iterator (std::shared_ptr <typename CLIST::CNode> Elmt /*= nullptr*/,
	std::shared_ptr <typename CLIST::CNode> Next /*= nullptr*/,
	std::shared_ptr <typename CLIST::CNode> Previous /*= nullptr*/)
	:m_Elmt (Elmt), m_Next (Next), m_Previous (Previous)
{
}

template <class T>
ITER::iterator (const iterator & i)
	: m_Elmt (i.m_Elmt), m_Next (i.m_Next), m_Previous (i.m_Previous)
{
}

template <class T>
typename ITER& ITER::operator= (const iterator & i)
{
	m_Elmt (i.m_Elmt);
	m_Next (i.m_Next);
	m_Previous (i.m_Previous);
	return this;
}

template <class T>
bool ITER::operator== (const iterator & i) const
{
	return (m_Elmt == i.m_Elmt && m_Next == i.m_Next && m_Previous == i.m_Previous);
}

template <class T>
bool ITER::operator!= (const iterator & i) const
{
	return !operator==(i);
}

template <class T>
T& ITER::operator* ()
{
	return (m_Elmt->m_Info);
}

template <class T>
T* ITER::operator-> ()
{
	return *(m_Elmt->m_Info);
}

template <class T>
typename ITER& ITER::operator++()
{
	m_Previous = m_Elmt;
	m_Elmt = m_Next;
	m_Next = m_Next->m_Next;
	return *this;
}
template <class T>
typename ITER& ITER::operator++(int)
{
	iterator Temp (this);
	m_Previous = m_Elmt;
	m_Elmt = m_Next;
	m_Next = m_Next->m_Next;
	return *Temp;
}
template <class T>
typename ITER& ITER::operator--()
{
	m_Next = m_Elmt;
	m_Elmt = m_Previous;
	m_Previous = m_Previous->m_Previous;
	return *this;
}
template <class T>
typename ITER& ITER::operator--(int)
{
	iterator Temp (this);
	m_Next = m_Elmt;
	m_Elmt = m_Previous;
	m_Previous = m_Previous->m_Previous;
	return *Temp;
}
template <class T>
void ITER::Verif () const
{
	if (m_Previous == nullptr) cout << "null ";
	else cout << m_Previous->m_Info << " ";
	cout << m_Elmt->m_Info << " " << m_Next->m_Info << " " << endl;
}