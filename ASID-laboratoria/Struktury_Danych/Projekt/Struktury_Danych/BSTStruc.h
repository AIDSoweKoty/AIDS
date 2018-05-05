#pragma once
#ifndef BSTStruc_h
#define BSTStruc_h

using namespace std;

struct treeS {
	int wartosc=-1;
	treeS *korzen=0;
	treeS *lewy=0;
	treeS *prawy=0;
};
void dodajElement(treeS *tab, int a) {
	treeS *wsk;
	wsk = tab;
	//pierwszy element
	if (wsk->wartosc == -1 && wsk->lewy == 0 && wsk->prawy == 0) {
		//czyste drzewo
		if (wsk->korzen == 0) {
			treeS *ele = new treeS;
			wsk->korzen = ele;
			ele->wartosc = a;
			return;
		}
		else {
			//zaczete drzewo	
			dodajElement(wsk->korzen, a);
			return;
		}
	}
	//lewa pusta
	if (wsk->wartosc >= a&&wsk->lewy == 0) {
		treeS *ele = new treeS;
		wsk->lewy = ele;
		ele->korzen = wsk;
		ele->wartosc = a;
		return;
	}
	//prawa pusta
	if (wsk->wartosc<a&&wsk->prawy == 0) {
		treeS *ele = new treeS;
		wsk->prawy = ele;
		ele->korzen = wsk;
		ele->wartosc = a;
		return;
	}
	//lewy zajecty
	if (wsk->wartosc >= a) {
		dodajElement(wsk->lewy, a);
		return;
	}
	//prawy zajety
	if (wsk->wartosc<a) {
		dodajElement(wsk->prawy, a);
		return;
	}
}

bool czyJestElement(treeS *tab, int a) {
	treeS *wsk;
	wsk = tab;
	if (wsk->wartosc == -1 && wsk->lewy == 0 && wsk->prawy == 0) {
		//czyste drzewo
		if (wsk->korzen == 0) {
			return false;
		}
		else {
			//zaczete drzewo	
			return czyJestElement(wsk->korzen, a);
		}
	}
	if (wsk->wartosc == a) {
		return true;
	}
	if (wsk->wartosc>a&&wsk->lewy != 0) {
		return czyJestElement(wsk->lewy, a);
	}
	if (wsk->wartosc<a&&wsk->prawy != 0) {
		return czyJestElement(wsk->prawy, a);
	}
	return false;
}
int wysokoscDrzewa(treeS *tab, int licznik = 1) {
	treeS *wsk;
	wsk = tab;
	if (wsk->wartosc == -1 && wsk->lewy == 0 && wsk->prawy == 0) {
		//czyste drzewo
		if (wsk->korzen == 0) {
			return 0;
		}
		else {
			//zaczete drzewo	
			return wysokoscDrzewa(wsk->korzen);
		}
	}
	if (wsk->lewy == 0 && wsk->prawy == 0) {
		return licznik;
	}
	if (wsk->lewy != 0 && wsk->prawy == 0) {
		return wysokoscDrzewa(wsk->lewy, licznik + 1);
	}
	if (wsk->lewy == 0 && wsk->prawy != 0) {
		return wysokoscDrzewa(wsk->prawy, licznik + 1);
	}
	if (wsk->lewy != 0 && wsk->prawy != 0) {
		int a = wysokoscDrzewa(wsk->lewy, licznik + 1);
		int b = wysokoscDrzewa(wsk->prawy, licznik + 1);
		return (a>b) ? a : b;
	}
}
#endif // !BSTStruc_h
