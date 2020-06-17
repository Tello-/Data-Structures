#pragma once

template<class T>
class Node
{
public:
				Node() = default;			// default ctor
				Node(const Node<T>& rhs);	// copy ctor
				~Node();
private:
	T			m_data{};
	Node<T>*		m_next{ nullptr };
};

template<class T>
inline Node<T>::Node(const Node<T>& rhs)
{
	m_data = rhs.m_data; // only copy rhs nodes data not its next link....
}

template<class T>
inline Node<T>::~Node()
{
}
