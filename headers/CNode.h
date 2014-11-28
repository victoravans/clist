/*
 * CNode.h
 *
 *  Created on: 28 nov. 2014
 *      Author: m13009698
 */

#ifndef CNODE_H_
#define CNODE_H_

namespace nsSdS
{
	template <typename T>
	class CNode {

		typedef CNode <T> * PCNode;

		T m_info;
		PCNode p_Suivant;
		PCNode p_Precedent;

	public:
		CNode();
		virtual ~CNode();

		T getInfo();
		PCNode getSuivant();
		PCNode getPrecedent();

		void setInfo(T & info);
		void setSuivant(const PCNode suivant);
		void setPrecedent(const PCNode precedent);
	};
}
#endif /* CNODE_H_ */
