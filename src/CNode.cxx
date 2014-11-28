#include "CNode.h"

template <typename T>
CNode<T>::CNode(T info, std::shared_ptr <CNode<T>> suivant, std::shared_ptr <CNode<T>> precedent)
	:m_Info(info), m_Next(suivant), m_Previous(precedent)
{

}

template <typename T>
CNode<T>::~CNode()
{

}

template <typename T>
T CNode<T>::getInfo()
{
	return m_Info;
}

template <typename T>
std::shared_ptr <CNode<T>> CNode<T>::getNext()
{
	return m_Next;
}

template <typename T>
std::shared_ptr <CNode<T>> CNode<T>::getPrevious()
{
	return m_Previous;
}

template <typename T>
void CNode<T>::setInfo(T & info)
{
	m_Info = info;
}

template <typename T>
void CNode<T>::setNext(const std::shared_ptr <CNode<T>> next)
{
	m_Next = next;
}

template <typename T>
void CNode<T>::setPrevious(const std::shared_ptr <CNode<T>> prev)
{
	m_Previous = prev;
}
