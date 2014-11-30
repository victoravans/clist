#ifndef __CLIST_H__
#define __CLIST_H__


#include <cstddef>		//size_t
#include <memory>		//shared_ptr

namespace nsSdD
{
	template <class T>
	class CList
	{
	private:
		class CNode
		{
			T m_Info;
			std::shared_ptr <CNode> m_Next;
			std::shared_ptr <CNode> m_Previous;


			CNode(T info, std::shared_ptr <CNode> suivant, std::shared_ptr <CNode> precedent)
				:m_Info(info), m_Next(suivant), m_Previous(precedent){}
			~CNode();
		};


		std::shared_ptr <CNode> m_Head;	//head sentinel
		std::shared_ptr <CNode> m_Tail;	//tail sentinel

		CList split (CList l);

	public:
		explicit CList ();							//empty list
		explicit CList (std::size_t n);				//list of n empty elements
		CList (std::size_t n, const T& val);		//list of n elements of value val
		CList (const CList& x);						//list copied of another list

		CList& operator= (const CList& l);			//duplicates every element of list l to create another one
		void assign (std::size_t n, const T& val);	//fills the list with n elements, each a copy of val

		bool empty ();		//returns true if the list is empty
		size_t size ();		//returns the number of elements of the list

		CNode&	front ();				//reference to the first element
		const CNode&	front () const;		//const reference to the first element

		CNode&	back ();				//reference to the last element
		const CNode&	back() const;		//const reference to the last element

		void push_front (const T& val);		//inserts an element at the beginning of the list (after the head sentinel)
		void push_back (const T& val);		//inserts an element at the end of the list (before the tail sentinel)
		void pop_front();	//deletes the first element of the list
		void pop_back();	//deletes the last element of the list

		void swap (CList& l);	//exchanges the content of the list with l's
		void resize (std::size_t n, T val = T());	//resizes the list to n elements. Delete or create cnodes
		void clear();	//sets list's size to 0

		void remove (const T& val);	//removes list's elements of value val
		void unique();	//removes all but the first element of consecutive group of equal elements

		void merge (CList& l); //transfers all of l's elements in the list, requieres ordered lists. l then becomes empty
		void sort();	//sorts the list using operator<
		void reverse();	//reverse the order of the elements in the list


	};
}

#endif /* __CLIST_H__ */
