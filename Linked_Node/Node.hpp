#pragma once

template<class T>
class Node
{
public:
				Node() = default;			// default ctor
				Node(const Node<T>& rhs);	// copy ctor
				~Node();

	const T&		data() const;
	Node<T>*		next() const;

	void			setData(const T& data);
	void			setNext(Node<T>* next);
private:
	T			m_data{};					// uses T{} default ctor for default construction of node
	Node<T>*		m_next{ nullptr };			// default init node next to nullptr
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

template<class T>
inline const T& Node<T>::data() const
{
	return m_data;
}

template<class T>
inline Node<T>* Node<T>::next() const
{
	return m_next;
}

template<class T>
inline void Node<T>::setData(const T& data)
{
	m_data = data;
}

template<class T>
inline void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}
