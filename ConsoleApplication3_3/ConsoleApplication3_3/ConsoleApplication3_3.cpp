// ConsoleApplication3_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <fstream>
using namespace std;

int main()
{
	constexpr int nmax = 100;

	ifstream ulazniTok("brojevi.dat");
	if (!ulazniTok)
	{
		cerr << "Ne mogu otvoriti traženu datoteku" << endl;
		return 1;
	}

	double brojevi[nmax];
	int n = 0;
	double broj;

	while (ulazniTok >> broj)
	{
		if (n >= nmax)
		{
			cerr << "Previše podataka!" << endl;
			return 2;
		}
		brojevi[n++] = broj;
	}

	if (n==0)
	{
		cerr << "Nema podataka!" << endl;
		return 3;
	}

	for (int i = n - 1; i > 0; --i)
	{
		bool zamjena = false;
		for (size_t j = 0; j < n; j++)
		{
			if (brojevi[j+1] < brojevi[j])
			{
				auto privremeni = brojevi[j];
				brojevi[j] = brojevi[j + 1];
				brojevi[j + 1] = privremeni;
				zamjena = true;
			}
		}
		if (zamjena == false)
		{
			break;
		}
	}

	cout << "Brojevi slozeni po velicini: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << brojevi[i] << endl;
	}

	system("pause");

    return 0;
}

