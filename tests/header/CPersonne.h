/*
 * CPersonne.h
 *
 *  Created on: 28 nov. 2014
 *      Author: p13004234
 */

#ifndef CPERSONNE_H_
#define CPERSONNE_H_

class CPersonne {
public:
	CPersonne(){};
	CPersonne(std::string Nom, std::string Prenom){
		m_Nom = Nom;
		m_Prenom = Prenom;
	};
	~CPersonne(){};

private :

	std::string m_Nom;
	std::string m_Prenom;

	void setNom(std::string Nom){
		m_Nom = Nom;
	}
	void setPrenom(std::string Prenom){
		m_Prenom = Prenom;
	}

	std::string getNom(){
		return m_Nom;
	}
	std::string getPrenom(){
		return m_Prenom;
	}
};

#endif /* CPERSONNE_H_ */
