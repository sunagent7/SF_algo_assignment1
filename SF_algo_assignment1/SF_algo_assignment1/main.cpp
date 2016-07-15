#include<iostream>
#include<vector>
#include<algorithm>
#include "mergeSort.h"

using namespace std;

#define DATASIZE 100000
#define FILENAME "IntegerArray.txt"

int main()
{
	FILE *fp;
	char *filename = FILENAME;
	int i;
	int data[DATASIZE];

	fopen_s(&fp, filename, "rt");

	for (i = 0; i < DATASIZE; i++)
	{
		fscanf_s(fp, "%d", &data[i]);
	}
	fclose(fp);

	vector<int> vec(data, data + DATASIZE);
	vec = mergeSort(vec);

	/*vector<int>::iterator it;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << "\n";
	}*/

	system("pause");
	return 0;
}