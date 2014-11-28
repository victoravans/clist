#include <cstddef>

namespace nsSdD
{
template <class T>
class CList
{
	explicit CList ();
	explicit CList (std::size_t n);
	CList (std::size_t n, const T& val);
	CList (const CList& x);
};
}
