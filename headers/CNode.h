#ifndef __CNODE_H__
#define __CNODE_H__


#include <memory>		//shared_ptr


template <typename T>
class CNode
{
private:
	typedef std::shared_ptr <CNode<T>> PCNode;
	T m_Info;
	PCNode m_Suivant;
	PCNode m_Precedent;

public:
	CNode(T info, PCNode suivant, PCNode precedent);
	virtual ~CNode();

	T getInfo();
	PCNode getSuivant();
	PCNode getPrecedent();

	void setInfo(T & info);
	void setSuivant(const PCNode suivant);
	void setPrecedent(const PCNode precedent);
};


#endif /* __CNODE_H__ */
