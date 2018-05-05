#pragma once
#ifndef ArrayCrearing_h
#define ArrayCrearing_h

#include <iostream>
#include <ctime>
#include <random>

void garbageSort(int* A, int end_index)
{
	for (int i = end_index; i > 0; i--)
	{
		if (A[i - 1] > A[i])
		{
			int temp = A[i];
			A[i] = A[i - 1];
			A[i - 1] = temp;
		}
		else
		{
			break;
		}
	}
}

bool IsVarInSortedArrayBinary(int* Array, int looking_for, int start_index, int end_index)
{
	if (start_index <= end_index)
	{
		int mid_index = start_index + ((end_index - start_index) / 2);

		if (Array[mid_index] == looking_for)
		{
			return true;
		}

		if (looking_for > Array[mid_index])
		{
			return IsVarInSortedArrayBinary(Array, looking_for, mid_index + 1, end_index);
		}

		if (looking_for < Array[mid_index])
		{
			return IsVarInSortedArrayBinary(Array, looking_for, start_index, mid_index - 1);
		}
	}
	return false;
}


int largeRandomInt(int left_border, int right_border)
{
	int tmp;
	tmp = rand() % (right_border - left_border) + left_border;
	tmp <<= 15;
	tmp = (tmp ^ rand()) % (right_border - left_border) + left_border;
	return tmp;
}
void makeListWithUniqueElements(int *A, int size)
{
	int right_border = size * 100;
	srand(time(NULL));
	int* B;
	B = new int[size];

	A[0] = largeRandomInt(0,right_border);
	B[0] = A[0];

	for (int i = 1; i < size; ++i)
	{
		int tmp = largeRandomInt(0, right_border);
		while (true)
		{
			if (IsVarInSortedArrayBinary(B, tmp, 0, i-1))
			{
				tmp = largeRandomInt(0,right_border);
			}
			else
			{
				A[i] = tmp;
				B[i] = tmp;
				garbageSort(B,i);
				break;
			}

		}

	}
	delete[] B;
}


void CopyArray(int* CopyFrom, int* CopyTo, int size_of_array)
{
	for (int i = 0; i < size_of_array; i++)
	{
		CopyTo[i] = CopyFrom[i];
	}
}

void BinPart(int* ArrayToPartition, int* ArrayTo, int start_index, int end_index,int* index_to_put)
{


	if (start_index <= end_index)
	{
		int mid = (start_index + end_index)/ 2;
		ArrayTo[*index_to_put] = ArrayToPartition[mid];
		*index_to_put += 1;
		BinPart(ArrayToPartition, ArrayTo, start_index, mid - 1, index_to_put);
		BinPart(ArrayToPartition, ArrayTo, mid + 1,end_index, index_to_put);
	}
}
void BinaryPartition(int* ArrayToPartition, int* ArrayTo, int size_of_array)
{
	int *i = NULL ;
	int jan = 0;
	i = &jan;
	BinPart(ArrayToPartition, ArrayTo, 0, size_of_array-1, i);
}


#endif // !ArrayCrearing_h
