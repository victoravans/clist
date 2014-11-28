/*
 * CNode.cpp
 *
 *  Created on: 28 nov. 2014
 *      Author: m13009698
 */

#include "../headers/CNode.h"
using namespace nsSdS;
CNode::CNode() {
	// TODO Auto-generated constructor stub

}

CNode::~CNode() {
	// TODO Auto-generated destructor stub
}

T CNode::getInfo()
{
	return m_Info;
}
PCNode CNode::getSuivant()
{
	return m_Suivant;
}
PCNode CNode::getPrecedent()
{
	return m_Precedent;
}

void CNode::setInfo(T & info)
{
	m_Info = info;
}
void CNode::setSuivant(const PCNode suivant)
{
	m_Suivant = suivant;
}
void CNode::setPrecedent(const PCNode precedent)
{
	m_Precedent = precedent;
}
