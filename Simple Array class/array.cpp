

template<typename Type>
Array<Type>::Array(int n)
{
	size = n;
	arr = new Type[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = Type();
	}
}

template<typename Type>
Array<Type>::Array(Type a[], int n)
{
	size = n;
	arr = new Type[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a[i];
	}
}

template<typename Type>
Array<Type>::Array(Array<Type> &a)
{
	size = a.size;
	arr = new Type[size];
	for (int i = 0; i < size; i++)
		arr[i] = a.arr[i];
}

template<typename Type>
void Array<Type>::setval(Type val, int index)
{
	arr[index] = val;
}

template<typename Type>
int Array<Type>::getsize() const
{
	return size;
}

template<typename Type>
Type Array<Type>::getval(int index) const
{
	return arr[index];
}

template<typename Type>
Array<Type>::~Array()
{
	delete[]arr;
}