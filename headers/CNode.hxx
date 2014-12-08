#define CNODE nsSdD::CList<T>::CNode

template <class T>
CNODE::CNode (const T & val /*= T ()*/,
	std::shared_ptr <typename CNODE> suivant /*= nullptr*/,
	std::shared_ptr <typename CNODE> precedent /*= nullptr*/)
	:m_Info (val), m_Next (suivant), m_Previous (precedent) {}