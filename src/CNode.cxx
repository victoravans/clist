#include "CNode.h"

template <typename T>
CNode<T>::CNode(T info, PCNode suivant, PCNode precedent)
	:m_Info(info), m_Suivant_p(suivant), m_Precedent_p(precedent)
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
PCNode CNode<T>::getSuivant()
{
	return m_Suivant_p;
}

template <typename T>
PCNode CNode<T>::getPrecedent()
{
	return m_Precedent_p;
}

template <typename T>
void CNode<T>::setInfo(T & info)
{
	m_Info = info;
}

template <typename T>
void CNode<T>::setSuivant(const PCNode suivant)
{
	m_Suivant_p = suivant;
}

template <typename T>
void CNode<T>::setPrecedent(const PCNode precedent)
{
	m_Precedent_p = precedent;
}
