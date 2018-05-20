#pragma once
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class element {
public:
	element * n;
	int *w;
};

class glowa {
public:
	int ilosc;
	int r;
	element *w;

	glowa() {
		this->ilosc = 0;
		this->w = 0;
	}

	void dodajElement(int *tab) {
		element *a = new element;
		a->w = new int[this->r];
		//cout<<"***********"<<endl;
		for (int i = 0; i<this->r; i++) {
			a->w[i] = tab[i];

			//cout<<a->w[i]<<endl;
		}
		//cout<<"***********"<<endl;
		this->ilosc++;
		a->n = this->w;
		this->w = a;
		//cout<<this->w<<endl;
	}
	void wypiszElementy() {
		element *wk = this->w;
		cout << "**************";
		if (this->ilosc == 0) {
			cout << "Brak cyklu Hamiltona!" << endl;
			cout << "**************" << endl;
			return;
		}
		cout << "Cykl Hamiltona:" << endl;
		while (wk->n) {
			//cout<<wk->n;
			for (int i = 0; i<this->r; i++) {
				cout << wk->w[i];
			}
			cout << endl;
			wk = wk->n;
		}
		for (int i = 0; i<this->r; i++) {
			cout << wk->w[i];
		}
		cout << endl;
		cout << "**************" << endl;
	}

};




class graf {
public:
	int r; //rozmiar
	bool **w;
	glowa hamilton;
	int *pom;

	int iloscKrawedzi;
	int *obwEul;
	int *stos;
	bool **obwEulTmp;

	int *pojCyklHam;
	bool czyZna;



public:
	graf(int r);
	void pisz();
	void cyklHamiltona(int a = 0);
	void obwodEulera();
	void wypiszObwodEulera();
	void pojedynczyCyklHamiltona(int a = 0);
	void wylosujgrafEulera(float d);
};

