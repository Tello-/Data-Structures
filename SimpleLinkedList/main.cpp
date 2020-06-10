// This is an implementation of a single file, simple linked list
#include <iostream>


template<typename T>
struct Node
{
	Node(const T& _data = T{}, Node* _next = nullptr) : data{ _data }, next{ _next } {}
	T		data;
	Node*	next;
};

template<typename dataType>
class SimpleLinkedList
{
public:
		SimpleLinkedList() {}
		~SimpleLinkedList() { destroy(mHead); }
	int	size() const { return mSize; }
	void	insert(const dataType& _data)
	{
		if (!size())
		{
			mHead = new Node<dataType>{_data, nullptr};
			mTail = mHead;
		}
		else
		{
			mTail->next = new Node<dataType>{_data, nullptr};
			mTail = mTail->next;
		}
		++mSize;
	}
	void remove() // removes first element in list
	{
		if (!size()) return;
		Node<dataType>* tempPtr = mHead->next;
		delete mHead;
		mHead = tempPtr;
		--mSize;
	}

	void	print(std::ostream& _outs)
	{
		Node<dataType>* traverser = mHead;
		while (traverser)
		{
			_outs << traverser->data << ", ";
			traverser = traverser->next;
		}
	}
private: // private methods

	void destroy(Node<dataType>* _currentNode)
	{
		if (!_currentNode) return;
		destroy(_currentNode->next);
		delete _currentNode;
		--mSize;

	}

private: // private data
	int mSize{ 0 };
	Node<dataType>* mHead{ nullptr };
	Node<dataType>* mTail{ nullptr };
};


int main()
{

	SimpleLinkedList<int> list;
	list.insert(22);
	list.insert(11);
	list.insert(99);
	list.insert(77);

	list.print(std::cout);

	std::cout << std::endl;


	list.remove();

	list.print(std::cout);



	return 0;
}