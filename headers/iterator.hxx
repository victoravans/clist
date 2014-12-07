#define ITER nsSdD::CList<T>::iterator
#define CLIST nsSdD::CList<T>


template <class T>
ITER::iterator (std::shared_ptr <typename CLIST::CNode> Elmt /*= nullptr*/)
	:m_Elmt (Elmt)
{
}

template <class T>
ITER::iterator (const iterator & i)
	: m_Elmt (i.m_Elmt)
{
}

template <class T>
typename ITER ITER::operator= (const iterator & i)
{
	m_Elmt = i.m_Elmt;
	iterator Temp (m_Elmt);
	return Temp;
}

template <class T>
bool ITER::operator== (const iterator & i) const
{
	return (m_Elmt == i.m_Elmt);
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
const T& ITER::operator* () const
{
	return (m_Elmt->m_Info);
}

template <class T>
T* ITER::operator-> ()
{
	return &(m_Elmt->m_Info);
}

template <class T>
const T* ITER::operator-> () const
{
	return &(m_Elmt->m_Info);
}

template <class T>
typename ITER& ITER::operator++()
{
	m_Elmt = m_Elmt->m_Next;
	return *this;
}
template <class T>
typename ITER ITER::operator++(int)
{
	iterator Temp (*this);
	m_Elmt = m_Elmt->m_Next;
	return Temp;
}
template <class T>
typename ITER& ITER::operator--()
{;
	m_Elmt = m_Elmt->m_Previous;
	return *this;
}
template <class T>
typename ITER ITER::operator--(int)
{
	iterator Temp (this);
	m_Elmt = m_Elmt->m_Previous;
	return *Temp;
}
template <class T>
void ITER::Verif () const
{
	if (m_Elmt->m_Previous == nullptr) cout << "N ";
	else cout << m_Elmt->m_Previous->m_Info << " ";
	cout << m_Elmt->m_Info << " " << m_Elmt->m_Next->m_Info << " " << endl;
}