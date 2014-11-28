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
std::shared_ptr <CNode<T>> CNode<T>::getSuivant()
{
	return m_Next;
}

template <typename T>
std::shared_ptr <CNode<T>> CNode<T>::getPrecedent()
{
	return m_Previous;
}

template <typename T>
void CNode<T>::setInfo(T & info)
{
	m_Info = info;
}

template <typename T>
void CNode<T>::setSuivant(const std::shared_ptr <CNode<T>> suivant)
{
	m_Next = suivant;
}

template <typename T>
void CNode<T>::setPrecedent(const std::shared_ptr <CNode<T>> precedent)
{
	m_Previous = precedent;
}
