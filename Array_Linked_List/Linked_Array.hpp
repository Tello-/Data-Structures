/* This is a file describing a Linked List built from a built in array. The list expands as needed.
	Note, indexed access makes no sense for this sort of list, so don't implement operator[] 
*/


#pragma once


template <class DT>
struct Indexed_Node
{
	DT m_data{ T{} };
	size_t m_next{ -1 }; // -1 is uninitialized state
};

template<class T>
class LinkedArray
{
public:
					LinkedArray() = default;
					~LinkedArray() = default;

	bool				empty()		const;
	size_t			size()		const;
	size_t			maxSize()		const;


private:
	size_t			m_maxSize		{ 10 };
	size_t			m_size		{ 0 };
	Indexed_Node<T>*	m_pNodeArray	{ new Indexed_Node<T>[m_maxSize] };
	size_t			m_headIdx		{ -1 };
	size_t			m_tailIdx		{ -1 };
	




};

template<class T>
inline bool LinkedArray<T>::empty() const
{
	if (m_headIdx == -1) return true;
	return false;
}

template<class T>
inline size_t LinkedArray<T>::size() const
{
	return size_t();
}

template<class T>
inline size_t LinkedArray<T>::maxSize() const
{
	return m_maxSize;
}
