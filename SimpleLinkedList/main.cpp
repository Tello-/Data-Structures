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
	
		
	dataType& operator[](int idx)
	{
		return traverseTo(idx)->data;
	}
		
		
	int	size() const { return mSize; }
	bool empty() const { return mSize == 0; }

	// insert at front of list
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

	// removes first element in list
	void remove() 
	{
		if (!size()) return;
		Node<dataType>* tempPtr = mHead->next;
		delete mHead;
		mHead = tempPtr;
		--mSize;
	}
	


	// print list members to client provided std::stream
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

	Node<dataType>* traverseTo(int idx)
	{
		if (empty()) return nullptr;
		if (idx < 0 || idx >= mSize) return nullptr;
		if (idx == 0) return mHead;
		int currIdx = 0;
		Node<dataType>* pTraverser = mHead;
		while (currIdx != idx)
		{
			pTraverser = pTraverser->next;
			++currIdx;
		}
		return pTraverser;

	}


	// recursively deallocates list memory
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
	//--------------------Testing list with int-----------------------------
	SimpleLinkedList<int> list;
	list.insert(22);
	list.insert(11);
	list.insert(99);
	list.insert(77);

	list.print(std::cout);

	std::cout << "\n";


	list.remove();

	list.print(std::cout);
	std::cout << "\n";
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


	// ---------------- Testing list with char --------------------
	SimpleLinkedList<char> charList;
	charList.insert('c');
	charList.insert('a');
	charList.insert('t');
	charList.insert('s');
	
	charList.print(std::cout);
	std::cout << "\n";
	int idx = 2;
	std::cout << "This is a test of overloaded [" << idx << "]: " << charList[idx] << "\n";

	charList.remove();

	charList.print(std::cout);
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	return 0;
}