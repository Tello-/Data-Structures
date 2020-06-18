// This is an implementation of a single file, simple linked list
/* Current Operations include:
Insertion at front
Removal at front
Destruction
Print linked representation
Print data only
Overloaded index operator
*/

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
	
		
	// allows indexed access to list
	dataType& operator[](std::size_t idx)
	{
		return traverseTo(idx)->data;
	}

	// concatinates rhs to the end of "this"
	SimpleLinkedList<dataType>& operator+(SimpleLinkedList<dataType>& rhs)
	{
		for (int i = 0; i < rhs.size(); ++i)
		{
			this->append(rhs[i]);
			++mSize;
		}
		return *this;

	}

	SimpleLinkedList<dataType>& operator=(SimpleLinkedList<dataType>& rhs)
	{
		if (this == &rhs) return *this; // handle self assignment
		destroy(mHead);					// destroy current list
		mHead = nullptr;					// cap off 
		if (rhs.empty()) return *this;
		Node<dataType>* rhsTraverser = rhs.mHead;
		while (rhsTraverser)
		{
			this->append(rhsTraverser->data);
			rhsTraverser = rhsTraverser->next;
		}
		this->mSize = rhs.mSize;
	}
		
		
	int	size() const { return mSize; }
	bool empty() const { return !size(); }

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
	void append(const dataType& data)
	{
		if (empty())
		{
			this->insert(data);
		}
		else
		{
			Node<dataType>* temp = new Node<dataType>{ data, nullptr };
			mTail->next = temp;
			mTail = temp;
			temp = nullptr;
		}
	}
	// removes first element in list
	bool remove() 
	{
		if (empty()) return false;
		Node<dataType>* tempPtr = mHead->next;
		delete mHead;
		mHead = tempPtr;
		--mSize;
	}
	

	// Print delegates to 1 of 2 differnt private print methods depending on what the flag parameter is set to
	void print(std::ostream& outs, bool printAsVisual = false)
	{
		if (printAsVisual) printVisualList(outs);
		else printData(outs);
	}


private: // private methods

	Node<dataType>* traverseTo(std::size_t idx) const
	{
		if (empty()) return nullptr;
		if (idx < 0 || idx >= size()) return nullptr;
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

	// print list members to client provided std::stream
	void	printData(std::ostream& outs)
	{
		Node<dataType>* traverser = mHead;
		while (traverser)
		{
			outs << traverser->data;
			if(traverser->next) outs << ", ";
			traverser = traverser->next;
		}
	}

	void printVisualList(std::ostream& outs) const
	{
		if (empty()) return;
		Node<dataType>* traverser = mHead;
		std::cout << "[" << traverser->data << " | " << traverser->next << "]";
		traverser = traverser->next;
		while (traverser)
		{
			std::cout << " -> " << "[" << traverser->data << " | " << traverser->next << "]";
			traverser = traverser->next;
		}
		return;
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



void print(std::string text)
{
	std::cout << text;
}
int main()
{
	//--------------------Testing list with int-----------------------------
	/*SimpleLinkedList<int> list;
	list.insert(22);
	list.insert(11);
	list.insert(99);
	list.insert(77);

	
	print("Int List Demo");
	print("\n");
	list.print(std::cout);
	print("\n");
	list.print(std::cout, true);
	print("\n");
	list.remove();
	list.print(std::cout);
	print("\n");
	print("Int List Demo End");
	print("\n");*/
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


	// ---------------- Testing list with char --------------------
	SimpleLinkedList<char> charList;
	charList.insert('c');
	charList.insert('a');
	charList.insert('t');
	charList.insert('s');
	
	print("\n");
	print("Char List Demo");
	print("\n");

	charList.print(std::cout);
	print("\n");


	charList.print(std::cout, true);
	print("\n");

	int idx = 2;
	print("This is a test of overloaded []: ");
	print("\n");

	std::cout << charList[0];
	print("\n");
	print("Test removal:");
	charList.remove();
	print("\n");

	charList.print(std::cout);
	print("\n");
	print("Char List Demo End");
	print("\n");
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



	// -------------Testing String list to file-------------------------------
	/*SimpleLinkedList<std::string> stringList;
	stringList.insert("Josh");
	stringList.insert("is");
	stringList.insert("cool");

	print("\n");

	print("String List Demo");
	print("\n");
	stringList.print(std::cout);
	print("\n");
	stringList.print(std::cout, true);
	print("\n");
	stringList.append("as");
	stringList.append("heck");
	print("\n");
	stringList.print(std::cout);
	print("\n");
	stringList.print(std::cout, true);
	print("\n");


	print("String List Demo End");
	print("\n");
	print("\n");*/
	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


	//-------------------Test for overloaded +-------------------------------
	print("\n");
	print("Char List2 Demo");
	print("\n");
	SimpleLinkedList<char> charList2;
	charList2.insert('8');
	charList2.insert('8');
	charList2.insert('8');
	charList2.print(std::cout, false);
	print("\n");
	charList2.print(std::cout, true);
	print("\n");
	print("Using assignment to set new list equal to old list:");
	print("\n");
	charList2 = charList;
	print("\n");
	charList2.print(std::cout, true);
	print("\n");


	print("Char List2 Demo End");
	print("\n");
	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	return 0;
}