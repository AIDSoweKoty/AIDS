#include "graf.h"
#include "list.h"
#include <random>
#include <ctime>
#include <iostream>
#include "LIFO.h"
#include <math.h>

graf::graf(int s, float d)
{
	SetSize(s);
	RandGraphInMatrix(d);
	FillListOfSucessorFormMatrix();
	FillListOfArchesFromMatrix();

}

graf::~graf()
{
}

int graf::CountReturnArchForListOfArches() {
	int count = 0;
	arch * tmp = new arch;
	tmp = ListOfArches.first;

	while (tmp)
	{
		if (Labes[tmp->end][0] < Labes[tmp->start][0] && Labes[tmp->start][0] < Labes[tmp->start][1] && Labes[tmp->start][1] < Labes[tmp->end][1]) {
			count++;
		}
		tmp = tmp->next;
	}
	return count;
}

void graf::PrintLabelsArray() {
	std::cout << "################" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << Labes[i][0] << " " << Labes[i][1] << std::endl;
	}
}

void graf::DFSsort() {
	int * holder = new int;
	*holder = 0;
	for (int i = 0; i < size; i++)
	{
		if (Labes[i][0] == -1) {
			Sort(holder, i);
		}
	}
	for (int i = 0; i < size; ++i) {
		Sorted[i] = stosik.PULL();
	}
}

void graf::PrintTopologyOrder() {
	std::cout << "################" << std::endl;
	std::cout << "Topology Order" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << Sorted[i] << " ";
	}
}

bool graf::Sort( int * hel,int i) {
	element * tmp = new element;
		if (Labes[i][0] > -1 && Labes[i][1] == -1) {
			return true;
		}
		if (Labes[i][0] > -1 && Labes[i][1] > -1) {
			return true;
		}
		Labes[i][0] = (*hel)++;
		tmp = ListOfSucessor[i].first;
		while (tmp){
			if (!Sort(hel,tmp->value)){
				return false;
			}
			tmp = tmp->next;
		}
		Labes[i][1] = (*hel)++;
		stosik.PUSH(i);
		return true;
}
	


void graf::FillListOfArchesFromMatrix() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (AdjacencyMatrix[j][i] == 1) {
				ListOfArches.AddElement(i, j);
			}
		}
	}
}

void graf::FillListOfSucessorFormMatrix() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (AdjacencyMatrix[j][i] == 1){
				ListOfSucessor[i].AddElement(j);
			}
		}
	}
}

void graf::PrintListOfArches() {
	std::cout << "List of arches" << std::endl;
	ListOfArches.PrintAllElements();
}

int graf::CountReturnArchForListOfsucessors() {
	int count = 0;
	element * tmp = new element;
	for (int i = 0; i < size; i++){
		tmp = ListOfSucessor[i].first;
		while (tmp){
			if (Labes[tmp->value][0] < Labes[i][0] && Labes[i][0]< Labes[i][1] && Labes[i][1] < Labes[tmp->value][1]){
				count++;
			}
			tmp = tmp->next;
		}

	}
	return count;
}

int graf::CountReturnArchForAdjacencyMatrix() {
	int count = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (AdjacencyMatrix[i][j] == 1) {
				if (Labes[i][0] < Labes[j][0] && Labes[j][0] < Labes[j][1] && Labes[j][1] < Labes[i][1]) {
					count++;
				}
			}
		}
	}
	return count;
}

void graf::PrintListOfSucessor() {
	for (int i = 0; i < size; i++)
	{
		std::cout << "Vertex " << i<< ": ";
		ListOfSucessor[i].PrintAllElements();
	}
}

void graf::SetSize(int s)
{
	size = s;

	AdjacencyMatrix = new bool *[size];
	for (int i = 0; i < size; i++)
	{
		AdjacencyMatrix[i] = new bool[size];
	}

	this->ListOfSucessor = new ListOfSucssesor[size];

	Labes = new int*[size];
	for (int i = 0; i < size; ++i) {
		Labes[i] = new int[2];
		Labes[i][0] = -1;
		Labes[i][1] = -1;
	}
	Sorted = new int[size];
}

void graf::CheckAdjacencyMatrixDensity()
{
	int  m = 0;
	for ( int i = 0; i < size; i++)	{
		for (int j = 0; j < size; j++) {
			if (AdjacencyMatrix[j][i] == 1){
				++m;
			}
		}

	}
	float density = (1.0f * m) / (size * (size + 1));
	std::cout <<"Graph density: "<< density << std::endl;
}

void graf::PrintAdjacenceyMatrix() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << AdjacencyMatrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

void graf::RandGraphInMatrix(float density)
{

	srand(time(NULL));

	for ( int i = 0; i < size; i++)
		for (int j = 0; j < size; ++j) {
			AdjacencyMatrix[j][i] = 0;
		}
	
	int m = (int)(density * size * (size + 1) *1.0f);

	int i, j;
	while (m > 0) {
		i = rand() % (size);
		j = rand() % (size);
		if ((i != j) && (AdjacencyMatrix[j][i] == 0)) {
			AdjacencyMatrix[j][i] = 1;
			--m;
		}
	}

}