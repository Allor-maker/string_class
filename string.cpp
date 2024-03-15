#include "string.h"
#include <iostream>

void string::print() const
{
	for (int i = 0; i < this->n; i++)
	{
		std::cout << this->data[i];
	}
	std::cout << std::endl;
}
int string::len() const
{
	return this->n;
}

char string::operator[](const int& index) const
{
	return this->data[index];
}
bool string::empty() const
{
	if (this->n == 0)
		return true;
	else
		return false;
}
void string::clear()
{
	delete[] data;
	this->n = 0;
	data = new char[n];
}
void  string::erase(int index, int n_s)
{
	if (index >= this->n) throw 0;
	string c(*this);
	delete[] data;
	this->n = this->n - n_s;
	data = new char[n];
	for (int i = 0; i < index; i++)
	{
		data[i] = c.data[i];
	}
	for (int i = index; i < n; i++)
	{
		data[i] = c.data[i + n_s];
	}
}
void string::insert(int pos, const char* ch, int len)
{
	if (pos >= this->n) throw 0;

	string c(*this);
	delete[] data;

	this->n = this->n + len;
	data = new char[n];

	for (int i = 0; i < pos; i++)
	{
		data[i] = c.data[i];
	}
	for (int i = 0; i < len; i++)
	{
		data[i + pos] = ch[i];
	}
	for (int i = pos; i < (n - len); i++)
	{
		data[i + len] = c.data[i];
	}
}
void string::insert(int pos, const string& str)
{
	if (pos >= this->n) throw 0;

	string c(*this);
	delete[] data;

	this->n = this->n + str.n;
	data = new char[n];

	for (int i = 0; i < pos; i++)
	{
		data[i] = c.data[i];
	}
	for (int i = 0; i < str.n; i++)
	{
		data[i + pos] = str.data[i];
	}
	for (int i = pos; i < (n - str.n); i++)
	{
		data[i + str.n] = c.data[i];
	}
}
string string::substr(int pos, int len) const
{
	string c(len, ' ');
	for (int i = 0; i < len; i++)
	{
		c.data[i] = this->data[i + pos];
	}
	return c;
}

int* string::prefix(const string& v) 
{
	int* pi = new int[v.n];

	for (int i = 0; i < v.n; i++)
		pi[i] = 0;

	for (int i = 1; i < v.n; i++)
	{
		int j = pi[i - 1];

		while (j > 0 && v.data[i] != v.data[j])
			j = pi[j - 1];

		if (v.data[i] == v.data[j])
			pi[i] = j + 1;

		else
			pi[i] = j;

	}
	return pi;
}
int string::find(const string& str) 
{
	int max_num = 6;//максимальное число элемкнтов в подстроке, которое можно обработать с помощью описанного ниже хеша
	int index = -1;
	if (str.n > max_num)//чтобы не переполнять целочисленный тип используем алгоритм К-М-П
	{
		int* data_pi = prefix(*this);
		int k = 0;

		for (int i = 0; i < this->n; i++) {
			while (k > 0 && this->data[i] != str.data[k])
			{
				k = data_pi[k - 1];
			}
			if (this->data[i] == str.data[k])
				k++;
			if (k == str.n)
			{
				index = i - k + 1;
				break;
			}
		}
		delete[] data_pi;
		return index;
	}

	else 
	{
		//используем хеш, если длина подстроки <= 6
		unsigned long long f_value = 0;
		unsigned long long value = 0;
		int pows = 1;
		for (int i = 0; i < str.n; i++)
		{
			f_value = (f_value * pows + int(str.data[i]));
			pows = 1000;//сдвигаем хеш влево на 3 символа и записываем справа новый код числа
		}
		pows = 1;
		unsigned long long k = 1;
		for (int i = 0; i < str.n; i++) {
			k *= 1000;//ищем к для пересчета хэша
		}
		for (int i = 0; i < n; i++)
		{
			value = (value * pows) % k + int(this->data[i]);
			pows = 1000;
			if (value == f_value)
			{
				index = i - (str.n - 1);
				break;
			}
			if (i == n - 1)
			{
				return -1;
			}
		}
		return index;
	}
}
bool string::operator==(const string& str) const
{
	if (this->n != str.n)
		return false;
	else
	{
		int count = 0;
		for (int i = 0; i < this->n; i++)
		{
			if (this->data[i] == str.data[i])
				count += 1;
			else
				break;
		}
		if (count == this->n)
			return true;
		else
			return false;
	}
}
bool string::operator!=(const string& str) const
{
	if (this->n == str.n)
		return false;
	else
		return true;
}
bool string::operator<(const string& str) const
{
	if (this->n < str.n)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (int(this->data[i]) < int(str.data[i]))
				return true;
			if (int(this->data[i]) > int(str.data[i]))
				return false;
		}
		return true;
	}
	if (this->n >= str.n)
	{
		for (int i = 0; i < str.n; i++)
		{
			if (int(this->data[i]) < int(str.data[i]))
				return true;
			if (int(this->data[i]) > int(str.data[i]))
				return false;
		}
		return false;
	}
}
bool string::operator<=(const string& str) const
{
	if (this->n <= str.n)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (int(this->data[i]) < int(str.data[i]))
				return true;
			if (int(this->data[i]) > int(str.data[i]))
				return false;
		}
		return true;
	}
	if (this->n > str.n)
	{
		for (int i = 0; i < str.n; i++)
		{
			if (int(this->data[i]) < int(str.data[i]))
				return true;
			if (int(this->data[i]) > int(str.data[i]))
				return false;
		}
		return false;
	}
}
bool string::operator>(const string& str) const
{
	if (this->n <= str.n)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (int(this->data[i]) > int(str.data[i]))
				return true;
			if (int(this->data[i]) < int(str.data[i]))
				return false;
		}
		return false;
	}
	if (this->n > str.n)
	{
		for (int i = 0; i < str.n; i++)
		{
			if (int(this->data[i]) > int(str.data[i]))
				return true;
			if (int(this->data[i]) < int(str.data[i]))
				return false;
		}
		return true;
	}
}
bool string::operator>=(const string& str) const
{
	if (this->n < str.n)
	{
		for (int i = 0; i < this->n; i++)
		{
			if (int(this->data[i]) > int(str.data[i]))
				return true;
			if (int(this->data[i]) < int(str.data[i]))
				return false;
		}
		return false;
	}
	if (this->n >= str.n)
	{
		for (int i = 0; i < str.n; i++)
		{
			if (int(this->data[i]) > int(str.data[i]))
				return true;
			if (int(this->data[i]) < int(str.data[i]))
				return false;
		}
		return true;
	}
}
string string::operator+(const string& v) const
{
	string c(this->n + v.n, ' ');

	for (int i = 0; i < (this->n); i++)
	{
		c.data[i] = this->data[i];
	}
	for (int i = 0; i < (v.n); i++)
	{
		c.data[i + n] = v.data[i];
	}
	return c;
}
string string::operator+(const char* arr)
{
	string s(arr);
	string c(this->n + s.n, ' ');
	for (int i = 0; i < this->n; i++)
	{
		c.data[i] = this->data[i];
	}
	for (int i = 0; i < s.n; i++)
	{
		c.data[i + this->n] = s.data[i];
	}
	return c;
}
string& string::operator+=(const string& v)
{
	string c(*this);
	this->n = this->n + v.n;
	delete[] data;
	data = new char[n];
	for (int i = 0; i < (c.n); i++)
	{
		this->data[i] = c.data[i];
	}
	for (int i = 0; i < v.n; i++)
	{
		this->data[i + c.n] = v.data[i];
	}
	return *this;
}

string& string::operator=(const string& v)
{
	if (&v == this)
	{
		return *this;
	}

	this->n = v.n;
	delete[] data;
	this->data = new char[n];

	for (int i = 0; i < this->n; i++)
	{
		this->data[i] = v.data[i];
	}
	return *this;
}

