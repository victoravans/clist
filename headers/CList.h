#ifndef __CLIST_H__
#define __CLIST_H__

/**
* \CList.h
* \brief Déclaration CList
* \author Mathieu Mérino
* \date 30/11/14
*
* Déclaration de la classe CList
*
*/

#include <cstddef>		//size_t
#include <memory>		//shared_ptr
#include <ostream>		//ostream
#include <iostream>		// A  SUPPRIMER A LA FIN

namespace nsSdD
{
	template <class T>
	class CList
	{
	private:
		class CNode
		{
			friend CList;
		private:
			std::shared_ptr <CNode> m_Next;
			std::shared_ptr <CNode> m_Previous;

		public:
			T m_Info;

			bool HasNext () const { return (m_Next->m_Next != nullptr); } 
			bool HasPrevious () const { return (m_Previous->m_Previous != nullptr); }
			CNode& GetNext (){ if (!HasNext ()) return *this; return *m_Next; }
			CNode& GetPrevious () { if (!HasPrevious ()) return *this; return *m_Previous; }

			operator T() { return m_Info; }
			T& GetInfo () { return m_Info; }

			CNode (const T & val = T(), std::shared_ptr <CNode> suivant = nullptr, std::shared_ptr <CNode> precedent = nullptr)
				:m_Info (val), m_Next (suivant), m_Previous (precedent) {}
			virtual ~CNode () {}
		};

		std::shared_ptr <CNode> m_Head;	//head sentinel
		std::shared_ptr <CNode> m_Tail;	//tail sentinel

	public:
		/**
		* \fn explicit CList ();
		* \brief Constructeur par défaut de CList
		*
		*/
		explicit CList ();
		/**
		* \fn explicit CList (std::size_t n);
		* \brief Constructeur de CList créant une liste de taille n (type_valeur construit par défaut)
		*
		* \param n Taille de la liste
		*/
		explicit CList (std::size_t n);				//list of n empty elements
		CList (std::size_t n, const T& val);		//list of n elements of value val
		CList (const CList& l);			//list copied of another list

		CList& operator= (const CList& l);			//duplicates every element of list l to create another one
		void assign (std::size_t n, const T& val);	//fills the list with n elements, each a copy of val

		bool empty () const;		//returns true if the list is empty
		size_t size () const;		//returns the number of elements of the list

		CNode&	front ();		//reference to the first element
		const CNode&	front () const;		//const reference to the first element

		CNode&	back ();				//reference to the last element
		const CNode&	back () const;	//const reference to the last element

		CNode&	operator[] (std::size_t position) const;

		void push_front (const T& val);		//inserts an element at the beginning of the list (after the head sentinel)
		void push_back (const T& val);		//inserts an element at the end of the list (before the tail sentinel)
		void pop_front();	//deletes the first element of the list
		void pop_back();	//deletes the last element of the list

		void swap (CList& l);	//exchanges the content of the list with l's
		void resize (std::size_t n, T val = T());	//resizes the list to n elements. Delete or create cnodes
		void clear();	//sets list's size to 0

		void remove (const T& val);	//removes list's elements of value val
		bool insert (const T & position, const T & val);
		bool erase (const T & position);
		void unique();	//removes all but the first element of consecutive group of equal elements

		void merge (CList& l); //transfers all of l's elements in the list, requieres ordered lists. l then becomes empty
		void sort();	//sorts the list using operator<
		void reverse();	//reverse the order of the elements in the list
		void edit (bool jumpLines = false);

		void test () { m_Head->m_Next = nullptr; }
	};
}

#include "CList.hxx"

#endif /* __CLIST_H__ */
