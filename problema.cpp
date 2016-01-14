#include "stdafx.h"
#include<iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int compar(const void *x, const void *y)
{
	return (strcmp(*(char **)x, *(char **)y));
}

void sort_a(void *array, unsigned n)
{
	qsort(array, n, sizeof(const char *), cmp);
}
int main()
{

	char *line_array[1000];
	char line[1024];
	int i = 0, j = 0;
	ifstream in("fisier1.txt");

		while (!in.eof())
		{
			in >> line;
			line[strcspn(line, "\n")] = '\0';
            if (i < sizeof line_array / sizeof *line_array)
			{
				line_array[i++] = _strdup(line);
			}
			else
			{
				break;
			}
		}
		in.close();
		sort_a(line_array, i);

		for (j = 0; j < i; j++)
		{
			cout << line_array[j] << ' ';
			cout << '\n';
		}
	system("pause");
	return 0;

}
