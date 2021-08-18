#include"mystring.h"

mystring::mystring()
{
	ptr = NULL;
}

mystring::mystring(const char* p)
{
	int i;
	for (i = 0; p[i]; i++);
	ptr = new char[i + 1];
	for (i = 0; p[i]; i++)
		ptr[i] = p[i];
	ptr[i] = '\0';
}

mystring::mystring(const mystring& s)
{
	int i, size;
	size = s.capacity();
	ptr = new char[size + 1];
	for (i = 0; s.ptr[i]; i++)
		ptr[i] = s.ptr[i];
	ptr[i] = '\0';
}

mystring::mystring(const char* p, int len)
{
	ptr = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		ptr[i] = p[i];
	ptr[i] = '\0';
}

mystring::mystring(char ch, int len)
{
	ptr = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		ptr[i] = ch;
	ptr[i] = '\0';
}

mystring::mystring(const mystring& s, int start, int len)
{
	ptr = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		ptr[i] = s.ptr[start + i];
	ptr[i] = '\0';
}

mystring mystring::operator=(const mystring& s)
{
	if (this != &s)
	{
		if (ptr != NULL)
			delete[]ptr;
		int i;
		for (i = 0; s.ptr[i]; i++);
		ptr = new char[i];
		for (i = 0; s.ptr[i]; i++)
			ptr[i] = s.ptr[i];
		ptr[i] = '\0';
	}
	return *this;
}

void mystring::operator+=(const mystring& s)
{

	mystring temp(*this);
	int i, j, size1, size2;
	size1 = (*this).capacity();
	size2 = s.capacity();
	if (ptr != NULL)
		delete[]ptr;
	ptr = new char[size1 + size2 + 1];
	for (i = 0; temp.ptr[i]; i++)
		ptr[i] = temp.ptr[i];
	if (this != &s)
	{
		for (j = 0; s.ptr[j]; j++, i++)
			ptr[i] = s.ptr[j];
		ptr[i] = '\0';
	}
	else
	{
		for (j = 0; temp.ptr[j]; j++, i++)
			ptr[i] = temp.ptr[j];
		ptr[i] = '\0';
	}
}

mystring mystring::operator+(const mystring& s)
{
	mystring temp;
	int i, j, len1, len2;
	len1 = (*this).capacity();
	len2 = s.capacity();
	temp.ptr = new char[len1 + len2 + 1];
	for (i = 0; ptr[i]; i++)
		temp.ptr[i] = ptr[i];
	for (j = 0; s.ptr[j]; j++, i++)
		temp.ptr[i] = s.ptr[j];
	temp.ptr[i] = '\0';
	return temp;
}

bool mystring::operator<(const mystring& s)
{
	int i = 0;
	while (ptr[i] || s.ptr[i])
	{
		if (ptr[i] >= s.ptr[i])
			return false;
		i++;
	}
	return true;
}

bool mystring::operator>=(const mystring& s)
{
	return !((*this) < s);
}

bool mystring::operator>(const mystring& s)
{
	int i = 0;
	while (ptr[i] || s.ptr[i])
	{
		if (ptr[i] <= s.ptr[i])
			return false;
		i++;
	}
	return true;
}

bool mystring::operator<=(const mystring& s)
{
	return !((*this) > s);
}

bool mystring::operator==(const mystring& s)
{
	int i = 0;
	while (ptr[i] || s.ptr[i])
	{
		if (ptr[i] > s.ptr[i])
			return false;
		if (ptr[i] < s.ptr[i])
			return false;
		i++;
	}
	return true;
}

bool mystring::operator!=(const mystring& s)
{
	return !((*this) == s);
}

char mystring::operator[](int loc) const
{
	int i, len = 0;
	for (i = 0; ptr[i]; i++)
		len++;
	if (loc<0 || loc>len)
	{
		cout << "ERROR! Location not found.";
		system("pause");
		exit(0);
	}
	return ptr[loc];
}

char& mystring::operator[](int loc)
{
	int i, len = 0;
	for (i = 0; ptr[i]; i++)
		len++;
	if (loc<0 || loc>len)
	{
		cout << "ERROR! Location not found.";
		system("pause");
		exit(0);
	}
	return ptr[loc];
}

void mystring::append(int len, char ch)
{

	mystring temp(*this);
	int size = (*this).capacity();
	int i, j;
	if (ptr != NULL)
		delete[] ptr;
	ptr = new char[size + len + 1];

	for (i = 0; temp.ptr[i]; i++)
		ptr[i] = temp.ptr[i];
	for (j = 1; j <= len; j++, i++)
		ptr[i] = ch;
	ptr[i] = '\0';
}
void mystring::append(const mystring& s)
{
	mystring temp(*this);
	int size1, size2;
	size1 = this->capacity();
	size2 = s.capacity();
	int i, j;
	//delete[] ptr;
	ptr = new char[size1 + size2 + 1];
	for (i = 0; temp.ptr[i]; i++)
		ptr[i] = temp.ptr[i];
	if (this != &s)
	{
		for (j = 1; s.ptr[j]; j++, i++)
			ptr[i] = s.ptr[j];
		ptr[i] = '\0';
	}
	else
	{
		for (j = 1; temp.ptr[j]; j++, i++)
			ptr[i] = temp.ptr[j];
		ptr[i] = '\0';
	}
}
void mystring::append(const mystring& str, int len)
{
	int size, i, j;
	size = (*this).capacity();
	char *temp = new char[size + 1];
	for (i = 0; ptr[i]; i++)
		temp[i] = ptr[i];
	temp[i] = '\0';
	delete[]ptr;
	ptr = new char[size + len + 1];
	for (i = 0; temp[i]; i++)
		ptr[i] = temp[i];
	if (this != &str)
	{
		for (j = 0; j < len; j++, i++)
			ptr[i] = str[j];
		ptr[i] = '\0';
	}
	else
	{
		for (j = 0; j < len; j++, i++)
			ptr[i] = temp[j];
		ptr[i] = '\0';
	}
	delete[]temp;
}
void mystring::append(const mystring& s, int start, int len)
{
	int size, i, j;
	mystring temp(*this);
	size = (*this).capacity();
	delete[]ptr;
	ptr = new char[size + len + 1];
	for (i = 0; temp.ptr[i]; i++)
		ptr[i] = temp.ptr[i];
	if (this != &s)
	{
		for (j = 0; j < len; j++, i++)
			ptr[i] = s.ptr[start + j];
		ptr[i] = '\0';
	}
	else
	{
		for (j = 0; j < len; j++, i++)
			ptr[i] = temp.ptr[start + j];
		ptr[i] = '\0';

	}
}
void mystring::assign(int len, char ch)
{
	if (ptr != NULL)
		delete[] ptr;
	ptr = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		ptr[i] = ch;
	ptr[i] = '\0';
}
void mystring::assign(const mystring& s)
{
	if (this != &s)
	{
		if (ptr != NULL)
			delete[]ptr;
		int size, i;
		size = s.capacity();
		ptr = new char[size + 1];
		for (i = 0; s.ptr[i]; i++)
			ptr[i] = s.ptr[i];
		ptr[i] = '\0';
	}
}

void mystring::assign(const mystring& str, int len)
{
	if (this != &str)
	{
		if (ptr != NULL)
			delete[]ptr;
		int i;
		ptr = new char[len + 1];
		for (i = 0; i < len; i++)
			ptr[i] = str.ptr[i];
		ptr[i] = '\0';
	}
	else
	{
		mystring temp(*this);
		if (ptr != NULL)
			delete[]ptr;
		int i;
		for (i = 0; i < len; i++)
			ptr[i] = temp.ptr[i];
		ptr[i] = '\0';
	}
}
void mystring::assign(const mystring& s, int start, int len)
{
	if (this != &s)
	{
		if (ptr != NULL)
			delete[]ptr;
		ptr = new char[len + 1];
		int i;
		for (i = 0; i < len; i++)
			ptr[i] = s.ptr[start + i];
		ptr[i] = '\0';
	}
	else
	{
		mystring temp(*this);
		if (ptr != NULL)
			delete[]ptr;
		int i;
		for (i = 0; i < len; i++)
			ptr[i] = temp.ptr[start + i];
		ptr[i] = '\0';
	}
}
int mystring::capacity() const
{
	int index = 0;
	while (ptr[index++]);
	return index;
}

char* mystring::begin() const
{
	return &ptr[0];
}

char* mystring::c_str() const
{
	return ptr;
}

void mystring::clear()
{
	if (ptr != NULL)
	{
		delete[]ptr;
		ptr = NULL;
	}
}
int mystring::compare(const mystring& s)
{
	int i;
	for (i = 0; ptr[i] || s.ptr[i]; i++)
	{
		if (ptr[i] < s.ptr[i])
			return -1;
		else if (ptr[i] > s.ptr[i])
			return 1;
	}
	return 0;
}
int mystring::compare(int start, int len, const mystring& s)
{
	int i;
	for (i = 0; (ptr[i] || s.ptr[start + i]) && i < len; i++)
	{
		if (ptr[i] < s.ptr[start + i])
			return -1;
		else if (ptr[i] > s.ptr[start + i])
			return 1;
	}
	return 0;
}
void mystring::copy(const mystring& s, int start, int len)
{
	int i;
	if (this != &s)
	{
		if (ptr != NULL)
			delete[]ptr;
		ptr = new char[len + 1];
		for (i = 0; i < len; i++)
			ptr[i] = s.ptr[start + i];
		ptr[i] = '\0';
	}
	else
	{
		mystring temp(*this);
		if (ptr != NULL)
			delete[]ptr;
		ptr = new char[len + 1];
		for (i = 0; i < len; i++)
			ptr[i] = temp.ptr[start + i];
		ptr[i] = '\0';
	}
}
bool mystring::empty() const
{
	return !(ptr == NULL);
}
char* mystring::end() const
{
	int size = (*this).capacity();
	return &ptr[size - 1];
}
void mystring::erase(int start, int len)
{
	mystring temp(*this);
	int size = (*this).capacity();
	if (ptr != NULL)
		delete[]ptr;
	ptr = new char[size - len + 1];
	int i = 0, j = 0;
	while (temp.ptr[i])
	{
		if (i == start)
			while (i < (start + len))
				i++;
		ptr[j] = temp.ptr[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
}

void mystring::insert(int start, int len, char ch)
{
	int size = (*this).capacity();
	mystring temp(*this);
	if (ptr != NULL)
		delete[]ptr;
	ptr = new char[size + len + 1];
	int i = 0, j = 0;
	while (temp.ptr[i])
	{
		if (i == start)
			while (j < (start + len))
			{
				ptr[j] = ch;
				j++;
			}
		ptr[j] = temp.ptr[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
}

void mystring::insert(int start, const mystring& s)
{
	mystring temp(*this);
	int size1, size2;
	size1 = (*this).capacity();
	size2 = s.capacity();
	if (ptr != NULL)
		delete[]ptr;
	ptr = new char[size1 + size2 + 1];
	int i = 0, j = 0;
	while (temp.ptr[i])
	{
		if (i == start)
			while (s.ptr[j - start]) {
				ptr[j] = s.ptr[j - start];
				j++;
			}
		ptr[j] = temp.ptr[i];
		i++;
		j++;
	}
	ptr[j] = '\0';

}
void mystring::replace(int start, int len, const mystring& s)
{
	int i;
	int size = (*this).capacity();
	if (start < 0 || start >= size)
	{
		cout << "ERROR!Beginning position out of range.";
		system("pause");
		exit(0);
	}
	if ((start + len) >= size)
	{
		cout << "Error! Invalid length.";
		system("pause");
		exit(0);
	}
	for (i = 0; i < len; i++)
		ptr[start + i] = s.ptr[i];
}

void mystring::resize(int len, char ch)
{
	mystring temp(*this);
	int size = (*this).capacity();
	if (ptr != NULL)
		delete[]ptr;
	ptr = new char[len + 1];
	int i = 0;
	while (temp.ptr[i] && i < len)
	{
		ptr[i] = temp.ptr[i];
		i++;
	}
	if (size < len)
		while (i < len)
		{
			ptr[i] = ch;
			i++;
		}
	ptr[i] = '\0';
}
mystring mystring::substr(int start, int len)
{
	int size = (*this).capacity();
	if (start < 0 || start >= size)
	{
		cout << "ERROR!Beginning position out of range.";
		system("pause");
		exit(0);
	}
	if (start + len >= size)
	{
		cout << "Error! Invalid length.";
		system("pause");
		exit(0);
	}
	mystring temp;
	temp.ptr = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		temp.ptr[i] = ptr[start + i];
	temp.ptr[i] = '\0';
	return temp;
}
void mystring::swap(mystring& s)
{
	int size;
	if (ptr == NULL)
	{
		size = s.capacity();
		(*this).copy(s, 0, size);
		delete[]s.ptr;
		s.ptr = NULL;
	}
	if (s.ptr == NULL)
	{
		size = (*this).capacity();
		s.copy((*this), 0, size);
		delete[]ptr;
		ptr = NULL;
	}
	if (ptr != NULL && s.ptr != NULL)
	{
		mystring temp(*this);
		size = s.capacity();
		(*this).copy(s, 0, size);
		size = temp.capacity();
		s.copy(temp, 0, size);
	}
}
int mystring::find(char ch, int index)
{
	int i, size;
	size = (*this).capacity();
	if (index < 0 || index >= size)
	{
		cout << "Error!!! given index is out of range.";
		system("pause");
		exit(0);
	}
	for (i = index; ptr[i]; i++)
		if (ptr[i] == ch)
			return i;
	return -1;
}
int mystring::find(const mystring& s, int index)
{
	bool flag;
	int i, j, size;
	size = (*this).capacity();
	if (index < 0 || index >= size)
	{
		cout << "Error!!! given index is out of range.";
		system("pause");
		exit(0);
	}
	for (i = index; ptr[i]; i++)
	{
		if (ptr[i] == s.ptr[0])
		{
			flag = true;
			j = 0;
			while (s.ptr[j] && ptr[i + j])
			{
				if (ptr[i + j] != s.ptr[j])
				{
					flag = false;
					break;
				}
				j++;
			}
			if (flag)
				return i;
		}
	}
	return -1;
}
mystring::~mystring()
{
	if (!ptr)
		delete[]ptr;
}
