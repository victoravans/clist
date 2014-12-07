#ifndef __CLIST_H__
#define __CLIST_H__

/**
* \CList.h
* \brief Déclaration CList
* \author Mathieu MÉRINO
* \date 30/11/14
*
* Déclaration de la classe CList
*
*/

#include <cstddef>		//size_t
#include <memory>		//shared_ptr
#include <ostream>		//ostream

/*! \namespace nsSdD
 *
 * Espace de nom regroupant des outils 
 * de structures de données
 */
namespace nsSdD
{
	template <class T>
	/*! \class CList 
	* \brief Classe imitant std::list (version 1)
	*
	* La classe CList en version 1, imitant le comportement de list
	* de la std sans utiliser d'itérateurs et en utilisant la classe privée CNode 
	* en version 1, contenant l'information à stocker de type T
	* (le type utilisé par la liste), et deux shared_ptr vers le CNode suivant 
	* et le CNode précédent.
	*
	* Pour se déplacer dans la liste,
	* on utilise donc GetNext, HasNext, GetPrevious et HasPrevious sur les 
	* référence renvoyées par l'opérateur [], front () et back (). Ces
	* références sont en fait des CNode, mais se comportent comme le type
	* avec lequel la liste a été initialisée, grâce à l'opérateur () qui
	* permet une conversion implicite. En cas de besoin, par ex pour l'appel à une
	* fonction explicit, l'utilisateurs peut utiliser la fonction GetInfo()
	* sur le CNode pour récupérer la donnée membre m_Info.
	*
	* C'est une liste doublement chaînée afin de permettre le déplacement dans les
	* deux sens, ce qui est à nos yeux trop pratique pour s'en dispenser. L'utilisation
	* D'une double sentinelle a permit l'implémentation des fonctions membres sans cas
	* particulier à gérer lors du parcours de la liste, ce qui se traduit par un gain de 
	* performance dans les algorithmes.
	*
	* La plupart des fonctions de la std::list ont été implémentées, exceptées celles
	* nécessitant l'utilisation d'itérateurs, qui seront rajoutées dans la version 2.
	* La majorité des algorithmes utilisés dans les fonctions seraient plus efficaces
	* et surtout lisibles s'ils fonctionnaient avec des itérateurs, c'est pourquoi
	* beaucoup de code sera réécrit dans le version 2.
	*/
	class CList
	{
	private:
		/*! \class CNode
		* \brief Classe contenant les informations d'une CList
		*
		* La classe CNode en version 1, contenant l'information à stocker de type T
		* (le type utilisé par la liste), et deux shared_ptr vers le CNode suivant 
		* et le CNode précédent.
		*/
		class CNode
		{
			friend CList;
		private:
			std::shared_ptr <CNode> m_Next; /*!< Pointeur vers l'élément suivant de la liste*/
			std::shared_ptr <CNode> m_Previous; /*!< Pointeur vers l'élément précédent de la liste*/
			T m_Info; /*!< Information contenue dans le CNode*/
		public:
			/**
			* \brief Constructeur de CNode
			*
			* 
			*/
			CNode (const T & val = T (), std::shared_ptr <CNode> suivant = nullptr, std::shared_ptr <CNode> precedent = nullptr)
				:m_Info (val), m_Next (suivant), m_Previous (precedent){}
			/**
			* \brief Vérifie si l'élément est le dernier de la liste
			*
			* Si l'élément suivant est la sentinelle de queue, l'élément courant est le dernier de la liste et la fonction renvoie
			* faux, vrai sinon.
			*
			* \return true si le CNode n'est pas le dernier de la liste, false sinon
			*/
			bool HasNext () const { return (m_Next->m_Next != nullptr); } 
			/**
			* \brief Vérifie si l'élément est le premier de la liste
			*
			* Si l'élément suivant est la sentinelle de tête, l'élément courant est le premier de la liste et la fonction renvoie
			* faux, vrai sinon.
			*
			* \return true si le CNode n'est pas le premier de la liste, false sinon
			*/
			bool HasPrevious () const { return (m_Previous->m_Previous != nullptr); }
			/**
			* \brief Récupère l'élément suivant de la liste
			*
			* Renvoie une référence vers le prochain élément de la liste, et si l'élément courant est le dernier, renvoie l'élément
			* courant.
			*
			* \return Référence vers le prochain élément de la liste
			*/
			CNode& GetNext (){ if (!HasNext ()) return *this; return *m_Next; }
			/**
			* \brief Récupère l'élément suivant de la liste
			*
			* Cette fonction est appelée à la place de l'autre GetNext () si la liste est constante.
			*
			* Renvoie une référence constante vers le prochain élément de la liste, et si l'élément courant est le dernier, 
			* renvoie l'élément courant.
			*
			* \return Référence constante vers le prochain élément de la liste
			*/
			const CNode& GetNext () const { if (!HasNext ()) return *this; return *m_Next; }
			/**
			* \brief Récupère l'élément précédent de la liste
			*
			* Renvoie une référence vers l'élément précédent de la liste, et si l'élément courant est le
			* premier, renvoie l'élément courant.
			*
			* \return Référence vers l'élément précédent de la liste
			*/
			CNode& GetPrevious () { if (!HasPrevious ()) return *this; return *m_Previous; }
			/**
			* \brief Récupère l'élément précédent de la liste
			*
			* Cette fonction est appelée à la place de l'autre GetPrevious () si la liste est constante.
			*
			* Renvoie une référence constante vers l'élément précédent de la liste, et si l'élément courant est le
			* premier, renvoie l'élément courant.
			*
			* \return Référence constante vers l'élément précédent de la liste
			*/
			const CNode& GetPrevious () const { if (!HasPrevious ()) return *this; return *m_Previous; }
			/**
			* \brief Conversion implicite du CNode en T
			*
			* Permet à l'utilisateur de récupérer l'information contenue dans le CNode sans faire de 
			* conversion explicite.
			*
			* \return
			*/
			operator T() const { return m_Info; }
		};

		std::shared_ptr <CNode> m_Head;	/*!< Pointeur vers la sentinelle de tête*/
		std::shared_ptr <CNode> m_Tail;	/*!< Pointeur vers la sentinelle de queue*/

	public:
		/**
		* \brief Constructeur par défaut de CList
		*
		* Initialise une CList de type T vide, en faisant pointer m_Head et m_Tail l'un sur l'autre.
		*/
		explicit CList ();
		/**
		* \brief Constructeur de CList créant une liste de taille passée en paramètre
		*
		* Crée une CList de type T comme le constructeur par défaut, puis appelle la fonction resize (n)
		*
		* \param n Taille de la liste
		*/
		explicit CList (std::size_t n);
		/**
		* \brief Constructeur de CList créant une liste de taille et de valeur passées en paramètre
		*
		* Crée une CList de type T comme le constructeur par défaut, puis appelle la fonction resize (n, val)
		*
		* \param n Taille de la liste
		* \param val Valeur à laquelle initaliser chaque case de la liste
		*/
		CList (std::size_t n, const T& val);
		/**
		* \brief Constructeur de CList créant une liste à partir d'une autre liste du même type à recopier
		*
		* Crée une CList de type T comme le constructeur par défaut, puis appelle la fonction resize (n)
		*
		* \param l Liste à copier
		*/
		CList (const CList& l);
		/**
		* \brief Transforme la CList en une copie de celle passée en paramètre.
		*
		* Remplace le contenu actuel de la liste, modifiant sa taille en celle de la liste à copier.
		* Le contenu actuel de la liste est soit réassigné, soit supprimé. Chaque élément est copié,
		* dont au final aucun élément n'est commun aux deux listes.
		*
		* \param l Liste à copier
		* \return La liste modifiée
		*/
		CList& operator= (const CList& l);			//duplicates every element of list l to create another one
		/**
		* \brief Redimensionne la liste et remplace son contenu par une valeur
		*
		* Redimensionne la liste à la taille voulue, et remplace l'information de chacun des CNode par
		* celle passée en paramètre.
		*
		* \param n La taille voulue pour la liste
		* \param val La valeur de tous les éléments de la liste
		*/
		void assign (std::size_t n, const T& val);
		/**
		* \brief Vérifie si la liste est vide
		*
		* Si la sentinelle de tête pointe directement vers la sentinelle de queue, la list est vide,
		* sinon elle ne l'est pas.
		*
		* \return true si la liste est vide, false sinon
		*/
		bool empty () const;
		/**
		* \brief Renvoie la talle de la liste
		*
		* Parcourt la liste du début à la fin, incrémentant un compteur, puis renvoie celui-ci une fois
		* arrivé à la sentinelle de fin.
		*
		* \return La taille de la liste
		*/
		size_t size () const;		//returns the number of elements of the list
		/**
		* \brief Renvoie le premier élément
		*
		* Renvoie la référence du CNode du premier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de queue.
		*
		* \return La référence vers le premier élément de la liste
		*/
		CNode& front ();		//reference to the first element
		/**
		* \brief Renvoie le premier élément
		*
		* Cette fonction est appelée à la place de l'autre front () si la liste est constante.
		*
		* Renvoie la référence constante du CNode du premier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de queue.
		*
		* \return La référence constante vers le premier élément de la liste
		*/
		const CNode& front () const;		//const reference to the first element
		/**
		* \brief Renvoie le dernier élément
		*
		* Renvoie la référence du CNode du dernier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de tête.
		*
		* \return La référence vers le dernier élément de la liste
		*/
		CNode& back ();				//reference to the last element
		/**
		* \brief Renvoie le dernier élément
		*
		* Cette fonction est appelée à la place de l'autre back () si la liste est constante.
		*
		* Renvoie la référence constante du CNode du dernier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de tête.
		*
		* \return La référence constante vers le dernier élément de la liste
		*/
		const CNode& back () const;	//const reference to the last element
		/**
		* \brief Renvoie l'élément situé à l'index voulu
		*
		* Renvoie la référence du CNode correspondant au numéro voulu, sachant que le premier élément vaut 0 et que leur
		* numéro augmente de 1 par case. throw une exception de type out_of_range si la case demandé est hors de la liste.
		*
		* \param position Le numéro d'index de l'élément à renvoyer
		* \return La référence vers l'élément de la liste demandé
		*/
		CNode& operator[] (std::size_t position);
		/**
		* \brief Renvoie l'élément situé à l'index voulu
		*
		* Cette fonction est appelée à la place de l'autre operator[] si la liste est constante.
		*
		* Renvoie la référence constante du CNode correspondant au numéro voulu, sachant que le premier élément vaut 0 et que leur
		* numéro augmente de 1 par case. throw une exception de type out_of_range si la case demandé est hors de la liste.
		*
		* \param position Le numéro d'index de l'élément à renvoyer
		* \return La référence constante vers l'élément de la liste demandé
		*/
		const CNode& operator[]  (std::size_t position) const;
		/**
		* \brief Rajoute un élément au début
		*
		* Une case est insérée à la suite de la sentinelle de tête, contenant comme information une copie de val.
		*
		* \param val La valeur de l'élément à insérer
		*/
		void push_front (const T& val);		//inserts an element at the beginning of the list (after the head sentinel)
		/**
		* \brief Rajoute un élément à la fin
		*
		* Une case est insérée avant la sentinelle de queue, contenant comme information une copie de val.
		*
		* \param val La valeur de l'élément à insérer
		*/
		void push_back (const T& val);		//inserts an element at the end of the list (before the tail sentinel)
		/**
		* \brief Supprime le premier élément
		*
		* Le premier élément de la liste disparait. Sans effet si la liste est vide.
		*/
		void pop_front();	//deletes the first element of the list
		/**
		* \brief Supprime le dernier élément
		*
		* Le dernier élément de la liste disparait. Sans effet si la liste est vide.
		*/
		void pop_back();	//deletes the last element of the list
		/**
		* \brief Echange le contenu de la liste avec celle passée en paramètre
		*
		* Les deux listes échangent leurs deux sentinelles, résultant en un échange complet des listes.
		*
		* \param l La liste avec laquelle échanger le contenu
		*/
		void swap (CList& l);	//exchanges the content of the list with l's
		/**
		* \brief Redimensionne la liste
		*
		* La liste prend la taille voulue, et si le second paramètre est précisé, lorsque des nouveaux éléments
		* sont créés, ils prennent cette valeur.
		*
		* \param n La taille voulue pour la liste
		* \param val La valeur des nouveaux éléments de la liste
		*/
		void resize (std::size_t n, T val = T());	//resizes the list to n elements. Delete or create cnodes
		/**
		* \brief Efface toute la liste
		*
		* Tous les éléments de la liste sont supprimés, et la taille de la liste devient 0.
		*/
		void clear();	//sets list's size to 0
		/**
		* \brief Supprime de la liste tous les éléments égaux à la valeur donnée
		*
		* Tous les éléments de la liste dont l'information est égale à celle passée en paramètre sont supprimés.
		*
		* \param val La valeur des éléments à supprimer
		*/
		void remove (const T& val);	//removes list's elements of value val
		/**
		* \brief Insère un élément
		*
		* Recherche le premier élément de la liste correspondant à la position donnée en paramètre, et insère
		* la valeur donnée dans une nouvelle case avant celui-ci. Si aucun élément de la liste n'a une valeur
		* égale à celle de la position, l'insertion échoue
		*
		* \param position La valeur de l'élément avant lequel insérer le nouvel élément
		* \param val La valeur de l'élément à insérer
		* \return true si l'insertion a réussi, false si elle échoue
		*/
		bool insert (const T & position, const T & val);
		/**
		* \brief Supprime le premier élément égal à la valeur donnée
		*
		* Supprime de la liste la première case rencontrée, à partir du début, dont l'information est égale à 
		* celle passée en paramètre.
		*
		* \param position La valeur de l'élément à supprimer
		*/
		void erase (const T & position);
		/**
		* \brief Supprime les doublons qui se suivent
		*
		* Supprime de la liste tous les éléments sauf le premier des groupes d'éléments se suivant et étant
		* de même valeur. Cela garantit donc la suppression de tous les doublons uniquement dans les listes
		* triées.
		*/
		void unique();
		/**
		* \brief Fusionne deux listes triées
		*
		* Fusionne la liste avec celle passée en paramètre, vidant cette dernière. Les éléments sont rangés de manière
		* rangée, ce qui requiert donc d'avoir des listes triées.
		*
		* \param l La liste avec laquelle fusionner
		*/
		void merge (CList& l);
		/**
		* \brief Trie la liste
		*
		* Trie la liste en utilisant un tri par fusion. Nécessite que le type de la liste supporte l'opérateur <=
		*/
		void sort();
		/**
		* \brief Inverse la liste
		*
		* Renverse l'ordre de la liste, le premier élément devenant le dernier, et ainsi de suite.
		*/
		void reverse();	//reverse the order of the elements in the list
		/**
		* \brief Affiche le contenu de la liste
		*
		* Affiche chaque élément de la liste, du début à la fin, en sautant des lignes ou non si le paramètre le précise.
		* Nécéssite un type d'éléments injectable dans un flux.
		*
		* \param jumpLines Si vrai, l'affichage se fait en sautant des lignes, en ligne sinon
		*/
		void edit (bool jumpLines = false) const;
	};
}

#include "CList.hxx"

#endif /* __CLIST_H__ */
