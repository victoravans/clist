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
#include <utility>		//comparators

/*! \namespace nsSdD
 *
 * Espace de nom regroupant des outils 
 * de structures de données
 */
namespace nsSdD
{
	template <class T>
	/*! \class CList 
	* \brief Classe imitant std::list (version 2)
	*
	* La classe CList en version 2, imitant le comportement de list
	* de la std en utilisant des itérateurs et en utilisant la classe privée CNode 
	* en version 2, contenant l'information à stocker de type T
	* (le type utilisé par la liste), et deux shared_ptr vers le CNode suivant 
	* et le CNode précédent.
	*
	* L'ajout d'une méthode edit() permet d'afficher les valeurs de la liste, pour
	* des raisons de facilités de débuguage.

	* Pour se déplacer dans la liste, on crée un itérateur avec begin() ou end(),
	* et on le décremente ou incrémente. 
	*
	* C'est une liste doublement chaînée afin de permettre le déplacement dans les
	* deux sens, ce qui est à nos yeux trop pratique pour s'en dispenser. L'utilisation
	* d'une double sentinelle a permit l'implémentation des fonctions membres sans cas
	* particulier à gérer lors du parcours de la liste, ce qui se traduit par un gain de 
	* performance dans les algorithmes.
	*
	* Presque toutes les fonctions de la std::list ont été implémentées. Celles nécessitant
	* l'utilisation de const_iterator ont soit été ignorées (cbegin, cend), ou ajustées (les emplace)
	* car leur implémentation à été jugée trop difficile.
	*
	* Beaucoup de méthodes modifient directement les shared_ptr des m_Elmt des itérateurs, pour
	* cause d'efficacité de calcul. Toutes les boucles de la version 1 utilisant des shared_ptr
	* ont été transformées en boucles à itérateurs.
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
		public:
			std::shared_ptr <CNode> m_Next; /*!< Pointeur vers l'élément suivant de la liste*/
			std::shared_ptr <CNode> m_Previous; /*!< Pointeur vers l'élément précédent de la liste*/
			T m_Info; /*!< Information contenue dans le CNode*/
			/**
			* \brief Constructeur de CNode
			*
			*/
			CNode (const T & val = T (), std::shared_ptr <CNode> suivant = nullptr, std::shared_ptr <CNode> precedent = nullptr);
		};
		std::shared_ptr <CNode> m_Head;	/*!< Pointeur vers la sentinelle de tête*/
		std::shared_ptr <CNode> m_Tail;	/*!< Pointeur vers la sentinelle de queue*/

	public:
		/*! \class iterator
		* \brief Classe d'itérateurs de CList <T>
		*
		* La classe qui imite le comportement des itérateurs sur une std::list, ici sur une CList.
		* L'itérateur possède un pointeur vers son CNode, et c'est ce dernier qui contient les pointeurs
		* vers les cases d'avant et d'après.
		*
		* C'est une classe d'itérateurs bidirectionnels, ce qui signifie qu'ils peuvent se déplacer dans
		* vers le début et vers la fin de la liste, une case par une case grâce aux opérateurs ++ et --.
		* 
		* L'implémentation d'itérateurs rend l'utilisation de la CList beaucoup plus simple pour l'utilisateur,
		* car cela permet d'utiliser toutes les fonctions génériques de la std utilisant des itérateurs.
		* De plus, le fonctionnement interne des méthodes de CList est parfois optimisé, et plus lisible.
		*/
		class iterator
		{
			friend CList;
		private:
			std::shared_ptr <CNode> m_Elmt;
		public:
			iterator (const iterator & i);
			iterator (std::shared_ptr <CNode> Elmt = nullptr);
			iterator operator= (const iterator & i);
			bool operator== (const iterator & i) const;
			bool operator!= (const iterator & i) const;
			T& operator* ();
			const T& operator* () const;
			T* operator-> ();
			const T* operator-> () const;
			iterator& operator++();
			iterator operator++(int);
			iterator& operator--();
			iterator operator--(int);
		};
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
		* \brief Transforme la CList en une copie de celle passée en paramètre
		*
		* Remplace le contenu actuel de la liste, modifiant sa taille en celle de la liste à copier.
		* Le contenu actuel de la liste est soit réassigné, soit supprimé. Chaque élément est copié,
		* dont au final aucun élément n'est commun aux deux listes.
		*
		* \param l Liste à copier
		* \return La liste modifiée
		*/
		CList& operator= (const CList& l);
		/**
		* \brief Renvoie un itérateur vers le premier élément de la liste
		*
		* Génère un iterator de CList<T> pointant vers le premier élément qui permet de se déplacer dans la liste comme un itérateur classique
		*
		* \return Un itérateur pointant au début de la liste
		*/
		iterator begin ();
		/**
		* \brief Renvoie un itérateur vers le premier élément de la liste
		*
		* Cette fonction est appelée à la place de l'autre begin () si la liste est constante.
		*
		* Génère un iterator de CList<T> pointant vers le premier élément qui permet de se déplacer dans la liste comme un itérateur classique
		*
		* \return Un itérateur pointant au début de la liste
		*/
		const iterator begin () const;
		/**
		* \brief Renvoie un itérateur vers la case après le dernier élément de la liste
		*
		* Génère un iterator de CList<T> pointant vers la case après le dernier élément qui permet de se déplacer dans la liste comme un itérateur classique
		*
		* \return Un itérateur pointant au début de la liste
		*/
		iterator end ();
		/**
		* \brief Renvoie un itérateur vers la case après le dernier élément de la liste
		*
		* Cette fonction est appelée à la place de l'autre begin () si la liste est constante.
		*
		* Génère un iterator de CList<T> pointant vers la case après le dernier élément qui permet de se déplacer dans la liste comme un itérateur classique
		*
		* \return Un itérateur pointant au début de la liste
		*/
		const iterator end () const;
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
		* Si la sentinelle de tête pointe directement vers la sentinelle de queue, la liste est vide,
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
		size_t size () const;
		/**
		* \brief Renvoie le premier élément
		*
		* Renvoie la référence du premier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de queue.
		*
		* \return La référence vers le premier élément de la liste
		*/
		T& front ();
		/**
		* \brief Renvoie le premier élément
		*
		* Cette fonction est appelée à la place de l'autre front () si la liste est constante.
		*
		* Renvoie la référence constante du premier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de queue.
		*
		* \return La référence constante vers le premier élément de la liste
		*/
		const T& front () const;
		/**
		* \brief Renvoie le dernier élément
		*
		* Renvoie la référence dernier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de tête.
		*
		* \return La référence vers le dernier élément de la liste
		*/
		T& back ();
		/**
		* \brief Renvoie le dernier élément
		*
		* Cette fonction est appelée à la place de l'autre back () si la liste est constante.
		*
		* Renvoie la référence constantedu dernier élément de la liste. Sur une liste vide, cette fonction peut avoir
		* un comportement indéfini sur le déroulement du programme car elle renvoie la sentinelle de tête.
		*
		* \return La référence constante vers le dernier élément de la liste
		*/
		const T& back () const;	//const reference to the last element
		/**
		* \brief Rajoute un élément au début
		*
		* Une case est insérée à la suite de la sentinelle de tête, contenant comme information une copie de val.
		*
		* \param val La valeur de l'élément à insérer
		*/
		void push_front (const T& val);	
		/**
		* \brief Rajoute un élément au début par ses arguments de constructeur
		*
		* Un élément est créé au début de la liste en envoyant comme paramètre les arguments nécessaires à un constructeur
		* d'un objet de type T. 
		*
		* \param args Les arguments de construction de l'objet à insérer
		*/
		template <class... Args>
		void emplace_front (Args&&... args);
		/**
		* \brief Rajoute un élément à la fin
		*
		* Une case est insérée avant la sentinelle de queue, contenant comme information une copie de val.
		*
		* \param val La valeur de l'élément à insérer
		*/
		void push_back (const T& val);
		/**
		* \brief Rajoute un élément à la fin par ses arguments de constructeur
		*
		* Un élément est créé à la fin de la liste en envoyant comme paramètre les arguments nécessaires à un constructeur
		* d'un objet de type T.
		*
		* \param args Les arguments de construction de l'objet à insérer
		*/
		template <class... Args>
		void emplace_back (Args&&... args);
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
		* \brief Transfère une liste dans la liste à l'emplacement indiqué
		*
		* Tous les éléments de la liste x sont insérés avant l'élément pointé par position.
		*
		* \param position Itérateur indiquant où doit se faire l'insertion
		* \param x la liste à vider et insérer
		*/
		void splice (iterator position, CList& x);
		/**
		* \brief Transfère un élément d'une liste dans la liste à l'emplacement indiqué
		*
		* L'élément de x pointé par l'itérateur i est inséré dans la liste avant l'élément pointé par position.
		*
		* \param position Itérateur indiquant où doit se faire l'insertion
		* \param x Liste dans laquelle prendre l'élément
		* \param i Itérateur indiquant quel élément on doit bouger
		*/
		void splice (iterator position, CList& x, iterator i);
		/**
		* \brief Transfère une partie d'une liste dans la liste à l'emplacement indiqué
		*
		* Les éléments de la liste x compris entre first et last, first inclus et last exclu, sont transférés dans la liste
		* courante, avant l'élément pointé par position.
		*
		* \param position Itérateur indiquant où doit se faire l'insertion
		* \param x Liste dans laquelle prendre les éléments
		* \param first Itérateur indiquant le début de la chaîne d'élément à transférer
		* \param first Itérateur indiquant le la fin de la chaîne d'élément à transférer
		*/
		void splice (iterator position, CList& x, iterator first, iterator last);
		/**
		* \brief Supprime de la liste tous les éléments égaux à la valeur donnée
		*
		* Tous les éléments de la liste dont l'information est égale à celle passée en paramètre sont supprimés.
		*
		* \param val La valeur des éléments à supprimer
		*/
		void remove (const T& val);
		/**
		* \brief Insère dans la liste un élément à un endroit indiqué
		*
		* Insère l'élément val avant l'élément pointé par position.
		*
		* \param position La position où insérer val
		* \param val L'élément à insérer
		* \return Un iterator pointant vers l'élément inséré
		*/
		iterator insert (iterator position, const T& val);
		/**
		* \brief Insère des éléments dans la liste à un endroit indiqué
		*
		* Insère n éléments de valeur val avant l'élément pointé par position.
		*
		* \param position La position ou insérer les éléments
		* \param n Le nombre d'éléments à insérer
		* \param val La valeur des éléments à insérer
		*/
		void insert (iterator position, size_t n, const T& val);
		template <class InputIterator>
		/**
		* \brief Rajoute un élément à l'endroit indiqué par ses arguments de constructeur
		*
		* Un élément est créé dans la liste à l'endroit indiqué par position en envoyant comme 
		* paramètre les arguments nécessaires à un constructeur d'un objet de type T.
		*
		* \param position La position ou insérer l'élément
		* \param args Les arguments de construction de l'objet à insérer
		*/
		void insert (iterator position, InputIterator first, InputIterator last);
		template <class... Args>
		/**
		* \brief Insère des éléments dans la liste à un endroit indiqué
		*
		* Insère les éléments compris entre les itérateurs first et last, first inclus et last exclu,
		* dans la liste avant l'élément pointé par position. Les éléments sont copiés et donc la liste
		* pointée par first et last est intouchée.
		*
		* \param position La position ou insérer les éléments
		* \param first L'itérateur vers le premier élément à insérer
		* \param last L'itérateur vers la casé après le dernier élément à insérer
		*/
		iterator emplace (const_iterator position, Args&&... args);
		/**
		* \brief Supprime l'élément à la case indiquée
		*
		* Supprime de la liste l'élément pointé par l'itérateur position.
		*
		* \param position L'itérateur pointant vers l'élément à supprimer
		*/
		iterator erase (iterator position);
		/**
		* \brief Supprime une suite d'éléments entre les cases indiquées
		*
		* Supprime de la liste tous les éléments inclus entre first et last, first inclus et last exclu.
		*
		* \param first L'itérateur pointant vers le premier des éléments à supprimer
		* \param last L'itérateur pointant vers la case après le dernier élément à supprimer
		*/
		iterator erase (iterator first, iterator last);
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
#include "CNode.hxx"
#include "iterator.hxx"

#endif /* __CLIST_H__ */
