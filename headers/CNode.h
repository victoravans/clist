#ifndef __CNODE_H__
#define __CNODE_H__

template <typename T>
typedef CNode <T> * PCNode;

template <typename T>
class CNode
{
private:
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


#endif /* __CNODE_H__ */
