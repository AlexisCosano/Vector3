#pragma once


template<class TYPE> struct Node
{
	TYPE value;
	Node<TYPE>* next;

	inline Node(const TYPE& _value)
	{
		value = _value;
		next = prev = NULL;
	}

	~Node()
	{}
};

template<class TYPE> class LinkedListTemplate
{
	Node* start;
	LinkedListTemplate() : start(NULL) {}
	void add(TYPE value)
	{
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = NULL;
		Node* tmp = start;

		if (tmp != NULL) {
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
		}
		tmp->next = newNode;
	}

	void del(Node* delNode)
	{
		if (delNode != NULL)
		{
			if (delNode != start && start != NULL)
			{
				Node* tmp = start;
				while (tmp->next != delNode)
				{
					if (tmp == NULL)
					{
						delete delNode;
						return;
					}
					tmp = tmp->next;
				}
				tmp->next = delNode->next;
			}
			else
			{
				start = start->next;
			}
			delete delNode;
		}
	}

	void del(unsigned int x)
	{
		if (start != NULL)
		{
			Node* tmp = start;
			Node* tmp2;
			if (x == 0)
			{
				start = start->next;
				delete tmp;
			}
			for (unsigned int i = 1; i < x; i++)
			{
				if (tmp == NULL)
				{
					return;
				}
				tmp = tmp->next;
			}
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
		}
		delete tmp2;
	}

	void delAll()
	{
		if (start != NULL)
		{
			Node* tmp = start;
			while (start != NULL)
			{
				tmp = start;
				start = start->next;
				delete tmp;
			}
			delete start;
		}
	}

	unsigned int count() const
	{
		unsigned int result = 0;
		Node* tmp = start;
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				result++;
			}
		}
		return (result);
	}

};