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
	std::shared_ptr <CNode<T>> getNext();
	std::shared_ptr <CNode<T>> getPrevious();

	void setInfo(T & info);
	void setNext(const std::shared_ptr <CNode<T>> next);
	void setPrevious(const std::shared_ptr <CNode<T>> prev);
};


#endif /* __CNODE_H__ */
