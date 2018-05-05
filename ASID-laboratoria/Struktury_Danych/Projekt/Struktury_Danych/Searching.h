#pragma once
#ifndef Searching_h
#define Searching_h

int BinarySearch(int* Array, int looking_for, int start_index, int end_index)
//function binary searching in array for element  and return his index, return -1 if not found

{
	if (start_index <= end_index)
	{
		int mid_index = start_index + ((end_index - start_index) / 2);

		if (Array[mid_index] == looking_for)
		{
			return mid_index;
		}

		if (looking_for > Array[mid_index])
		{
			return BinarySearch(Array, looking_for, mid_index + 1, end_index);
		}

		if (looking_for < Array[mid_index])
		{
			return BinarySearch(Array, looking_for, start_index, mid_index - 1);
		}
	}
	return -1;
}


int BruteForce(int* Array, int looking_for, int size_of_array)
//funcion serching for element in array by brute force and return index, return -1 if not found
{
	for (int i = 0; i < size_of_array; i++)
	{
		if (Array[i] == looking_for)
			return i;
	}
	return -1;
}

#endif // !Searching_h
