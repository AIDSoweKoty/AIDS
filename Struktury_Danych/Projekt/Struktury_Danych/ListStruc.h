#pragma once
#ifndef ListStruc_h
#define ListStruc_h

using namespace std;

struct listStruc {
	int wartosc = -1;
	listStruc *nastepna = 0;
};
void dodajElement(listStruc *tab, int a) {
	listStruc *wsk;
	wsk = tab;
	while (wsk->nastepna) {
		wsk = wsk->nastepna;
	}
	listStruc *ele = new listStruc;
	wsk->nastepna = ele;
	ele->wartosc = a;
	return;
}
void piszElementy(listStruc tab) {
	listStruc *wsk;
	wsk = &tab;
	while (wsk->nastepna) {
		cout << wsk->wartosc << endl;
		wsk = wsk->nastepna;
	}
	cout << wsk->wartosc << endl;
}
bool czyJestElement(listStruc tab, int a) {
	listStruc *wsk;
	wsk = &tab;
	while (wsk->nastepna) {
		if (wsk->wartosc == a)
			return true;
		wsk = wsk->nastepna;
	}
	if (wsk->wartosc == a)
		return true;
	return false;
}
#endif // !ListStruc_h
