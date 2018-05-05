#include "LIFO.h"
#include "list.h"


LIFO::LIFO()
{
	this->first = 0;
}

LIFO::~LIFO()
{
}

void LIFO::PUSH(int val)
{
	element * nowy = new element;
	nowy->value = val;
	if (!first){
		first = nowy;
	}
	else {
		element * tmp = new element;
		tmp->next = this->first;
		this->first = nowy;
		nowy->next = tmp->next;
	}
}
int LIFO::PULL() {
	if (!first) {
		return -1;
	}
	else {
		int wynik = this->first->value;
		this->first = this->first->next;
		return wynik;
	}
}