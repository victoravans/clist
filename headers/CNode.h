#ifndef __CNODE_H__
#define __CNODE_H__


#include <memory>		//shared_ptr


template <typename T>
class CNode
{
private:
	T m_Info;
	std::shared_ptr <CNode<T>> m_Next;
	std::shared_ptr <CNode<T>> m_Previous;

public:
	CNode(T info, std::shared_ptr <CNode<T>> next, std::shared_ptr <CNode<T>> previous);
	virtual ~CNode();

	T getInfo();
	std::shared_ptr <CNode<T>> getSuivant();
	std::shared_ptr <CNode<T>> getPrecedent();

	void setInfo(T & info);
	void setSuivant(const std::shared_ptr <CNode<T>> suivant);
	void setPrecedent(const std::shared_ptr <CNode<T>> precedent);
};


#endif /* __CNODE_H__ */
