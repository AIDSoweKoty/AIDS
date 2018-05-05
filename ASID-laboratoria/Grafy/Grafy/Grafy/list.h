#pragma once

//Arches

struct arch
{
	int start;
	int end;
	arch * next = 0;
	arch();
};

class ListOfArches
{
private:

public:
	arch * first;
	void AddElement(int s, int e);
	void PrintAllElements();
	ListOfArches();
	~ListOfArches();
};

//Sucessors

struct element
{
	int value;
	element * next = 0;
	element();
};

class ListOfSucssesor
{
private:

public:
	element * first;
	void AddElement(int val);
	void PrintAllElements();
	ListOfSucssesor();
	~ListOfSucssesor();
};

