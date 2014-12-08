
#define CNODE nsSdD::CList<T>::CNode

template <class T>
CNODE::CNode (const T & val /*= T ()*/,
			  std::shared_ptr <typename CNODE> suivant /*= nullptr*/, 
			  std::shared_ptr <typename CNODE> precedent /*= nullptr*/)
			  :m_Info (val), m_Next (suivant), m_Previous (precedent)
{}

template <class T>
bool CNODE::HasNext () const
{ 
	return (m_Next->m_Next != nullptr); 
}

template <class T>
bool CNODE::HasPrevious () const 
{ 
	return (m_Previous->m_Previous != nullptr); 
}

template <class T>
typename CNODE& CNODE::GetNext ()
{
	if (!HasNext ()) return *this; return *m_Next;
}

template <class T>
const typename CNODE& CNODE::GetNext () const
{ 
	if (!HasNext ()) return *this;
	return *m_Next; 
}

template <class T>
typename CNODE& CNODE::GetPrevious ()
{
	if (!HasPrevious ()) return *this; 
	return *m_Previous; 
}

template <class T>
const typename CNODE& CNODE::GetPrevious () const
{ 
	if (!HasPrevious ()) return *this;
	return *m_Previous; 
}

template <class T>
typename CNODE::operator T() const
{
	return m_Info;
}

template <class T>
typename T& CNODE::value()
{
	return m_Info;
}

template <class T>
const typename T& CNODE::value() const
{
	return m_Info;
}