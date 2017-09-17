#pragma once


#define DYN_ARRAY_BLOCK_SIZE 16


template<class TYPE> class DynamicArrayTemplate
{
	private:

	TYPE* data;
	unsigned int memory_capacity;
	unsigned int number_of_elements;

	public:

	// Constructors
	DynamicArrayTemplate() : memory_capacity(0), number_of_elements(0), data(NULL)
	{
		Alloc(DYN_ARRAY_BLOCK_SIZE);
	}
	
	DynamicArrayTemplate(unsigned int capacity) : memory_capacity(0), number_of_elements(0), data(NULL)
	{
		Alloc(capacity);
	}


	// Destructor
	~DynamicArrayTemplate()
	{
		delete[] data;
	}

	
	// Operators
	TYPE& operator[](unsigned int index)
	{
		ASSERT(index < number_of_elements);
		return(data[index]);
	}

	const TYPE& operator[](unsigned int index) const
	{
		assert(index < number_of_elements);
		return(data[index]);
	}

	const DynamicArrayTemplate<TYPE>& operator+= (const DynamicArrayTemplate<TYPE>& array)
	{
		if (number_of_elements + array.number_of_elements > memory_capacity)
			Alloc(number_of_elements + array.number_of_elements);

		for (uint i = 0; i < array.number_of_elements; ++i)
			data[number_of_elements++] = array.data[i];

		return(*this);
	}


	// Data Management
	void PushBack(const TYPE& element)
	{
		if (number_of_elements >= memory_capacity)
		{
			Alloc(memory_capacity + DYN_ARRAY_BLOCK_SIZE);
		}

		data[number_of_elements++] = element;
	}

	bool Pop(TYPE& result)
	{
		if (number_of_elements > 0)
		{
			result = data[--number_of_elements];
			return(true);
		}
		return(false);
	}

	void Clear()
	{
		number_of_elements = 0;
	}

	bool Insert(const TYPE& element, unsigned int position)
	{
		if (position > number_of_elements)
			return(false);

		if (position == number_of_elements)
		{
			PushBack(element);
			return(true);
		}

		if (number_of_elements + 1 > memory_capacity)
			Alloc(memory_capacity + DYN_ARRAY_BLOCK_SIZE);

		for (unsigned int i = number_of_elements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		++number_of_elements;

		return(true);
	}

	bool Insert(const DynamicArrayTemplate<TYPE>& array, unsigned int position)
	{
		if (position > number_of_elements)
			return(false);

		if (number_of_elements + array.number_of_elements > memory_capacity)
			Alloc(number_of_elements + array.number_of_elements + 1);

		for (unsigned int i = position; i < position + array.number_of_elements; ++i)
		{
			data[i + array.number_of_elements] = data[i];
			data[i] = array[i - position];
			++number_of_elements;
		}

		return(true);
	}

	TYPE* At(unsigned int index)
	{
		TYPE* result = NULL;

		if (index < number_of_elements)
			return(result = &data[index]);

		return(result);
	}

	const TYPE* At(unsigned int index) const
	{
		TYPE* result = NULL;

		if (index < number_of_elements)
			return(result = &data[index]);

		return(result);
	}

	
	// Utils
	unsigned int GetCapacity() const
	{
		return(memory_capacity);
	}

	unsigned int Count() const
	{
		return(number_of_elements);
	}


	// Sort
	int BubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			for (unsigned int i = 0; i < number_of_elements - 2; ++i)
			{
				++ret;
				if (data[i] > data[i + 1])
				{
					SWAP(data[i], data[i + 1]);
					swapped = true;
				}
			}
		}

		return(ret);
	}

	int BubbleSortOptimized()
	{
		int ret = 0;
		unsigned int count;
		unsigned int last = number_of_elements - 2;

		while (last > 0)
		{
			count = last;
			last = 0;
			for (unsigned int i = 0; i < count; ++i)
			{
				++ret;
				if (data[i] > data[i + 1])
				{
					SWAP(data[i], data[i + 1]);
					last = i;
				}
			}
		}
		return(ret);
	}


	int CombSort()
	{
		int ret = 0;
		bool swapped = true;
		int gap = number_of_elements - 1;
		float shrink = 1.3f;

		while (swapped || gap > 1)
		{
			gap = MAX(1, gap / shrink);

			swapped = false;
			for (unsigned int i = 0; i + gap < number_of_elements - 1; ++i)
			{
				++ret;
				if (data[i] > data[i + gap])
				{
					SWAP(data[i], data[i + gap]);
					swapped = true;
				}
			}
		}

		return(ret);
	}

	void Flip()
	{
		TYPE* start = &data[0];
		TYPE* end = &data[number_of_elements - 1];

		while (start < end)
			SWAP(*start++, *end--);
	}

	private:

	// Private Utils
	void Alloc(unsigned int mem)
	{
		TYPE* tmp = data;

		memory_capacity = mem;
		data = new TYPE[memory_capacity];

		number_of_elements = MIN(memory_capacity, number_of_elements);

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < number_of_elements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}
};
