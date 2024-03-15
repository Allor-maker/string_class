#include <iostream>
#include "string.h"

int main()
{
	string te;

	string f;
	string b("world");
	string a("hello");
	a.print();

	string c;
	c = a + b;
	c.print();

	int p = a.len();
	std::cout << p << std::endl;

	f += a;
	f.print();

	char ch = f[2];
	std::cout << ch << std::endl;

	string d;
	bool i = d.empty();
	bool j = a.empty();
	std::cout << i << " " << j << std::endl;

	a.clear();
	bool a_empt = a.empty();
	std::cout << a_empt << std::endl;

	b.erase(2, 2);
	c.erase(2);
	b.print();
	c.print();

	b.insert(1, "123", 3);
	b.print();
	c.insert(5, "7");
	c.print();

	string str("123");
	c.insert(3, str);
	c.print();

	string subst;
	subst = c.substr(2, 4);
	subst.print();

	string test("7");
	int index1 = c.find(subst);
	std::cout << index1 << std::endl;
	int index2 = c.find(test);
	std::cout << index2 << std::endl;

	//string compare

	//operator <
	string s1("Alice");
	string s2("Tom");
	bool s_comp = s1 < s2;
	std::cout << s_comp << std::endl;
	string s3("Alicen");
	s_comp = s3 < s1;
	std::cout << s_comp << std::endl;
	s_comp = s1 < s3;
	std::cout << s_comp << std::endl;
	string s4("Alice");
	s_comp = s4 < s1;
	std::cout << s_comp << std::endl;

	//operator <=
	s_comp = s1 <= s2;
	std::cout << s_comp << std::endl;
	s_comp = s3 <= s1;
	std::cout << s_comp << std::endl;
	s_comp = s1 <= s3;
	std::cout << s_comp << std::endl;
	s_comp = s4 <= s1;
	std::cout << s_comp << std::endl;

	//operator ==
	s_comp = (s4 == s1);
	std::cout << s_comp << std::endl;
	string s5("alice");
	s_comp = (s5 == s1);
	std::cout << s_comp << std::endl;
	s_comp = (s2 == s1);
	std::cout << s_comp << std::endl;

	//operator!=
	s_comp = (s1 != s4);
	std::cout << s_comp << std::endl;
	s_comp = (s1 != s2);
	std::cout << s_comp << std::endl;

	//opeartor >
	s_comp = (s1 > s2);
	std::cout << s_comp << std::endl;
	s_comp = (s2 > s1);
	std::cout << s_comp << std::endl;
	s_comp = (s1 > s4);
	std::cout << s_comp << std::endl;
	s_comp = (s3 > s1);
	std::cout << s_comp << std::endl;

	//operator >=
	s_comp = (s1 >= s2);
	std::cout << s_comp << std::endl;
	s_comp = (s2 >= s1);
	std::cout << s_comp << std::endl;
	s_comp = (s1 >= s4);
	std::cout << s_comp << std::endl;
	s_comp = (s3 >= s1);
	std::cout << s_comp << std::endl;


	//
	string str1("aaaaa");
	int ind1 = str1.find("aaa");
	std::cout << ind1 << std::endl;

	string str2("aaaab");
	int ind2 = str2.find("aab");
	std::cout << ind2 << std::endl;

	string str3("ababaab");
	int ind3 = str3.find("aab");
	std::cout << ind3 << std::endl;

	//тест на переполнение целочисленного типа
	string str4("hello world!");
	int ind4 = str4.find("ello wo");
	std::cout << ind4 << std::endl;

	string findcmp("abcabcd");
	string abcd("abcd");
	int f_cmp = findcmp.find(abcd);
	std::cout << f_cmp << std::endl;

	//тест на работу алгоритма КМП
	string str_long("ababcdefghiqwert");
	int index_long = str_long.find("abcdefgh");
	std::cout << index_long << std::endl;

}

