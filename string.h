#pragma once

class string 
{
private:
	char* data = nullptr;
	int n = 0;
public:
	string()
	{

	}
	string(int n, const char a) :n(n)
	{
		data = new char[n];
		for (int i = 0; i < this->n; i++)
		{
			this->data[i] = a;
		}
	}
	string(const char* arr)
	{
		int k = 0;
		while (arr[k] != '\0')
		{
			k++;
		}
		this->n = k;
		this->data = new char[k];
		for (int i = 0; i < this->n; i++)
		{
			data[i] = arr[i];
		}
	}
	string(const string& v) :n(v.n)
	{
		data = new char[v.n];
		for (int i = 0; i < v.n; i++)
		{
			this->data[i] = v.data[i];
		}
	}
	void print() const;
	
	int len() const;

	char& operator[](const int& index) const;

	bool empty() const;

	void clear();

	void  erase(int index, int n_s = 1);

	void insert(int pos, const char* ch, int len = 1);

	void insert(int pos, const string& str);

	string substr(int pos, int len) const;

	int find(const string& str);

	int* prefix(const string& v);
	
	bool operator==(const string& str) const;

	bool operator!=(const string& str) const;

	bool operator<(const string& str) const;

	bool operator<=(const string& str) const;

	bool operator>(const string& str) const;

	bool operator>=(const string& str) const;

	string operator+(const string& v) const;

	string operator+(const char* arr);

	string& operator+=(const string& v);

	string& operator=(const string& v);
	
	~string()
	{
		delete[] data;
	}
};