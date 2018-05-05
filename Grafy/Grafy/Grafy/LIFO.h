#pragma once
#include "list.h"
class LIFO
{
private:
	element * first;
public:
	LIFO();
	~LIFO();
	void PUSH(int val);
	int PULL();
};

