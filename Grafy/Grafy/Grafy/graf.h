#pragma once
#include "list.h"
#include "LIFO.h"

class graf
{
public:
	int size = 1;
	bool ** AdjacencyMatrix;
	ListOfSucssesor *ListOfSucessor;
	ListOfArches ListOfArches;
	int ** Labes;
	int * Sorted;
	LIFO stosik;
private:
	void SetSize(int size);
	void RandGraphInMatrix(	float density);
	void FillListOfSucessorFormMatrix();
	void FillListOfArchesFromMatrix();
public:
	graf(int s, float d);
	~graf();
	void PrintListOfArches();
	void PrintAdjacenceyMatrix();
	void PrintListOfSucessor();
	void CheckAdjacencyMatrixDensity();
	bool Sort(int * hel , int i);
	void DFSsort();
	void PrintLabelsArray();
	void PrintTopologyOrder();
	int CountReturnArchForListOfArches();
	int CountReturnArchForAdjacencyMatrix();
	int CountReturnArchForListOfsucessors();
};

