#include "pch.h"
#include <iostream>
#include<fstream>
using namespace std;
int main()
{
	int n;
	cout << "n= ";
	cin >> n;
	bool otr;
	int sum = 0;
	int **matrica = new int*[n];
	for (int i = 0; i < n; i++)
		matrica[i] = new int[n];
	ifstream matrix;
	matrix.open("input.txt");
	for (int i = 0; i < n; i++)
		for (int g = 0; g < n; g++)
			matrix>>matrica[i][g];
	matrix.close();
	for (int i = 0; i < n; i++) {
		for (int g = 0; g < n; g++)
			if (matrica[i][g] == matrica[g][i] && g == n-1)
				cout << i << endl;
			else if (!(matrica[i][g] == matrica[g][i]))
				break;
	}
	for (int i = 0; i < n; i++)
	{
		otr = false;
		for (int g = 0; g < n; g++)
		{

			for (int j = 0; j < n; j++)
				if (matrica[i][j] < 0)
				{
					otr = true;
					break;
				}
			if (otr)
				sum += matrica[i][g];
		}
	}
	cout <<"Sum= "<< sum;
	for (int i = 0; i < n; i++)
		delete[]matrica[i];
	return 0;
}

