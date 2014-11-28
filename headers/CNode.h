#ifndef __CNODE_H__
#define __CNODE_H__




template <typename T>
class CNode
{
private:
	typedef CNode <T> * PCNode;
	T m_Info;
	PCNode m_Suivant_p;
	PCNode m_Precedent_p;

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
