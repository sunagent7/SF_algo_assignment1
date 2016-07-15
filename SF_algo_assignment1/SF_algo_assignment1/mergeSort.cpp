#include "mergeSort.h"
#include<iostream>

//how to pass count to main


vector<int> merge(vector<int> a, vector<int> b)
{
	static long long int count = 0;
	int i;
	vector<int> c;
	vector<int>::iterator it_a = a.begin(), it_b = b.begin();

	for (i = 0; i < a.size() + b.size(); i++)
	{
		if (it_a != a.end() && it_b != b.end() && *it_a < *it_b)
		{
			c.push_back(*it_a);
			it_a++;
		}
		else if (it_a != a.end() && it_b != b.end() && *it_a > *it_b)
		{
			c.push_back(*it_b);
			it_b++;
			count += distance(it_a, a.end());
			cout << count << "\n";
		}
		else if (it_a != a.end())
		{
			c.push_back(*it_a);
			it_a++;
		}
		else
		{
			c.push_back(*it_b);
			it_b++;
		}
	}
	return c;
}

vector<int> mergeSort(vector<int> c)
{
	int size = c.size();
	if (size == 1)
	{
		return c;
	}
	else
	{
		int i, j;
		int size_a = size / 2 + size % 2;
		int size_b = size / 2;
		vector<int> a(c.begin(), c.begin() + size_a);
		vector<int> b(c.begin() + size_a, c.end());
		a = mergeSort(a);
		b = mergeSort(b);
		return merge(a, b);
	}
}