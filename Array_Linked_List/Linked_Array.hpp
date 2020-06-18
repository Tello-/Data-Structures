#pragma once


template <class DT>
struct Indexed_Node
{
	DT m_data{ T{} };
	size_t m_next{ -1 }; // "pointer" to next node where the pointer is an index to another array loc.
};

template<class T>
class LinkedArray
{
public:
					LinkedArray() = default;
					~LinkedArray() = default;


private:
	size_t			m_headIdx{ 0 };
	size_t			m_tailIdx{ 0 };
};