#pragma once
#ifndef BST_h
#define BST_h
//pozdrawiam z drzewa (^-^)/)(\(^-^)


class tree {
public:
	int wartosc;
	tree *lewy;
	tree *prawy;
	tree *korzen;
public:
	tree() {
		this->wartosc = -1;
		this->korzen = 0;
		this->lewy = 0;
		this->prawy = 0;
	}
	void dodajElement(int a) {
		//pierwszy i bez przypisu
		if (this->wartosc == -1 && this->korzen == 0) {
			tree *korzen = new tree;
			this->korzen = korzen;
			korzen->wartosc = a;
			return;
		}
		//pierwszy z przypisem
		if (this->wartosc == -1 && this->korzen != 0) {
			this->korzen->dodajElement(a);
			return;
		}
		//lewy pusty
		if (this->wartosc >= a&&this->lewy == 0) {
			tree *korzen = new tree;
			korzen->korzen = this;
			korzen->wartosc = a;
			this->lewy = korzen;
			return;
		}
		//prawy pusty
		if (this->wartosc<a&&this->prawy == 0) {
			tree *korzen = new tree;
			korzen->korzen = this;
			korzen->wartosc = a;
			this->prawy = korzen;
			return;
		}

		//przejdz przez lewy jesli jest mniejszy lub rowny a lewy slot zajety
		if (this->wartosc >= a&&this->lewy != 0) {
			this->lewy->dodajElement(a);
			return;
		}
		//przejdz przez lewy jesli jest mniejszy a prawy slot zajety
		if (this->wartosc<a&&this->prawy != 0) {
			this->prawy->dodajElement(a);
			return;
		}
	}
	int zbadajWysokosc(int wysokosc = 1) {
		//brak drzewa
		if (this->wartosc == -1 && this->korzen == 0) {
			return 0;
		}
		if (this->wartosc == -1) {
			wysokosc = this->korzen->zbadajWysokosc();
			return wysokosc;
		}
		if (this->lewy == 0 && this->prawy == 0) {
			return wysokosc;
		}
		if (this->lewy != 0 && this->prawy != 0) {
			int l = this->lewy->zbadajWysokosc(wysokosc + 1);
			int p = this->prawy->zbadajWysokosc(wysokosc + 1);
			return (l>p) ? l : p;
		}
		if (this->lewy != 0) {
			return this->lewy->zbadajWysokosc(wysokosc + 1);
		}
		if (this->prawy != 0) {
			return this->prawy->zbadajWysokosc(wysokosc + 1);
		}
	}
	bool czyJest(int a) {
		//drzewo jest puste
		if (this->wartosc == -1 && this->korzen == 0) {
			return false;
		}
		//pierwszy element
		if (this->wartosc == -1) {
			return this->korzen->czyJest(a);
		}
		if (this->wartosc == a) {
			return true;
		}
		if (this->wartosc >= a&&this->lewy != 0) {
			return this->lewy->czyJest(a);
		}
		if (this->wartosc<a&&this->prawy != 0) {
			return this->prawy->czyJest(a);
		}
		return false;
	}
};

#endif // !BST_h
