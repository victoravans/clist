#include "../headers/CNode.h"

template <typename T>
CNode<T>::CNode()
{

}

template <typename T>
CNode<T>::~CNode()
{

}

template <typename T>
T CNode<T>::getInfo()
{
	return m_info;
}

template <typename T>
PCNode CNode<T>::getSuivant()
{
	return m_Suivant;
}

template <typename T>
PCNode CNode<T>::getPrecedent()
{
	return m_Precedent;
}

template <typename T>
void CNode<T>::setInfo(T & info)
{
	m_Info = info;
}

template <typename T>
void CNode<T>::setSuivant(const PCNode suivant)
{
	m_Suivant = suivant;
}

template <typename T>
void CNode<T>::setPrecedent(const PCNode precedent)
{
	m_Precedent = precedent;
}
