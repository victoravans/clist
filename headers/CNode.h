#ifndef __CNODE_H__
#define __CNODE_H__

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

	void
};

#endif /* __CNODE_H__ */
