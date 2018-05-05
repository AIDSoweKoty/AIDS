#pragma once
#ifndef Lista_h
#define Lista_h

#include	<iostream>

using namespace std;


struct element 
{
	int wartosc;
	element *nastepny;
	element();
};

element::element() {
	nastepny = 0;
}

struct lista{
	lista();
	element *pierwszy;
	element *ostatni;
	void dodajElement(int wartosc);
	bool wyszukajElement(int wartosc);
};

lista::lista() {
	pierwszy = 0;
	ostatni = 0;
}

void lista::dodajElement(int wartosc)
{
	element *nowy = new element;

	nowy->wartosc = wartosc;

	if (pierwszy == 0) {
		pierwszy = nowy;
		ostatni = nowy;
	}
	else {
		ostatni->nastepny = nowy;
		nowy->nastepny = 0;
		ostatni = nowy;
	}
}

bool lista::wyszukajElement(int wartosc)
{
	element *nowy = new element;
	if (pierwszy->wartosc == wartosc)
	{
		return true;
	}
	nowy = pierwszy->nastepny;
	while (nowy->nastepny)
	{
		if (nowy->wartosc == wartosc)
		{
			return true;
		}
		nowy = nowy->nastepny;
	}
	return false;
}

#endif // !Lista_h
