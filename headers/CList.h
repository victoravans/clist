#include <cstddef>
#include "CNode.h"

namespace nsSdD
{
template <class T>
class CList
{
	CNode m_Head;
	CNode m_Tail;
	explicit CList ();
	explicit CList (std::size_t n);
	CList (std::size_t n, const T& val);
	CList (const CList& x);
};
}
