#include "list.h"
#include <iostream>



//Arches

arch::arch() {
	this->next = 0;
}


ListOfArches::ListOfArches()
{
	this->first = 0;
}

ListOfArches::~ListOfArches()
{
}

void ListOfArches::AddElement(int s, int e) {
	arch * nowy = new arch;
	nowy->start = s;
	nowy->end = e;
	if (!this->first){
		first = nowy;
	}
	else {
		arch * tmp = new arch;
		tmp->next = this->first;
		this->first = nowy;
		nowy->next = tmp->next;
	}
}

void ListOfArches::PrintAllElements() {
	arch * tmp = first;
	if (!tmp) {
		std::cout << "none";
	}
	while (tmp) {
		std::cout << tmp->start << " "<<tmp->end<<std::endl;
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

//Sucessors


element::element() {
	this->next = 0;
}

ListOfSucssesor::ListOfSucssesor()
{
	this->first = 0;
}

ListOfSucssesor::~ListOfSucssesor()
{
}

void ListOfSucssesor::AddElement(int val) {
	element * nowy = new element;
	nowy->value = val;
	if (!this->first){
		first = nowy;
	}
	else {
		element * tmp = new element;
		tmp->next = this->first;
		this->first = nowy;
		nowy->next = tmp->next;
	}
}

void ListOfSucssesor::PrintAllElements()
{
	element * tmp = first;
	if (!tmp){
		std::cout << "none";
	}
	while (tmp){
		std::cout << tmp->value<<" ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

