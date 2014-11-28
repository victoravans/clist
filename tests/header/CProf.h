/*
 * CProf.h
 *
 *  Created on: 28 nov. 2014
 *      Author: p13004234
 */

#ifndef CPROF_H_
#define CPROF_H_

class CProf : public CPersonne {
public:
	CProf(){};
	CProf(std::string Nom, std::string Prenom, std::string Etablissement){
		m_Nom = Nom;
		m_Prenom = Prenom;
		m_Etablissement = Etablissement;
	};
	~CProf(){};

private :
	std::string m_Etablissement;

	void setEtablissement(std::string Etablissement){
		m_Etablissement = Etablissement;
	}
	std::string getEtablissement(){
		return m_Etablissement;
	}
};

#endif /* CPROF_H_ */
