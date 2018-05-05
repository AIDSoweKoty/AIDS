#pragma once
#ifndef QuickSort_h
#define QuickSort_h


int PatitionRight(int* Array, int start_index, int end_index)
{
	int pivot = end_index, left_index = start_index, right_index = end_index - 1;

	while (true)
	{
		while (Array[left_index] <= Array[end_index] && left_index < end_index)
		{
			left_index++;
		}

		while (Array[right_index] >= Array[end_index] && right_index >= 0)
		{
			right_index--;
		}
		if (left_index < right_index)
		{
			int tmp = Array[left_index];
			Array[left_index] = Array[right_index];
			Array[right_index] = tmp;
		}
		else
		{
			break;
		}

	}
	int tmp = Array[left_index];
	Array[left_index] = Array[end_index];
	Array[end_index] = tmp;
	return left_index;
}



void QuickSortR(int * Array, int start_index, int end_index)
{
	if (start_index < end_index)
	{
		int part = PatitionRight(Array, start_index, end_index);
		QuickSortR(Array, start_index, part - 1);
		QuickSortR(Array, part + 1, end_index);
	}
}

int PatitionRightRev(int* Array, int start_index, int end_index)
{
	int pivot = end_index, left_index = start_index, right_index = end_index - 1;

	while (true)
	{
		while (Array[left_index] >= Array[end_index] && left_index < end_index)
		{
			left_index++;
		}

		while (Array[right_index] <= Array[end_index] && right_index >= 0)
		{
			right_index--;
		}
		if (left_index < right_index)
		{
			int tmp = Array[left_index];
			Array[left_index] = Array[right_index];
			Array[right_index] = tmp;
		}
		else
		{
			break;
		}

	}
	int tmp = Array[left_index];
	Array[left_index] = Array[end_index];
	Array[end_index] = tmp;
	return left_index;
}

void QuickSortRRev(int * Array, int start_index, int end_index)
{
	if (start_index < end_index)
	{
		int part = PatitionRightRev(Array, start_index, end_index);
		QuickSortRRev(Array, start_index, part - 1);
		QuickSortRRev(Array, part + 1, end_index);
	}
}

void QuickSortRight(int* Array, int size_of_array, bool reverse = false)
{
	if (reverse == false)
	{
		QuickSortR(Array, 0, size_of_array - 1);
	}
	else
	{
		QuickSortRRev(Array, 0, size_of_array - 1);
	}
}

/////////////////////////////////////////////////////////////////MID



int PatitionMid(int* Array, int start_index, int end_index)
{
	int pivot = (start_index + end_index) / 2, left_index = start_index, right_index = end_index - 1;
	int tmp = Array[pivot];
	Array[pivot] = Array[end_index];
	Array[end_index] = tmp;
	while (true)
	{
		while (Array[left_index] <= Array[end_index] && left_index < end_index)
		{
			left_index++;
		}

		while (Array[right_index] >= Array[end_index] && right_index >= 0)
		{
			right_index--;
		}
		if (left_index < right_index)
		{
			int tmp = Array[left_index];
			Array[left_index] = Array[right_index];
			Array[right_index] = tmp;
		}
		else
		{
			break;
		}

	}
	int tmpr = Array[left_index];
	Array[left_index] = Array[end_index];
	Array[end_index] = tmpr;
	return left_index;
}



void QuickSortM(int * Array, int start_index, int end_index)
{
	if (start_index < end_index)
	{
		int part = PatitionMid(Array, start_index, end_index);
		QuickSortM(Array, start_index, part - 1);
		QuickSortM(Array, part + 1, end_index);
	}
}





int PatitionMidRev(int* Array, int start_index, int end_index)
{
	int pivot = (start_index + end_index) / 2, left_index = start_index, right_index = end_index - 1;
	int tmp = Array[pivot];
	Array[pivot] = Array[end_index];
	Array[end_index] = tmp;
	while (true)
	{
		while (Array[left_index] >= Array[end_index] && left_index < end_index)
		{
			left_index++;
		}

		while (Array[right_index] <= Array[end_index] && right_index >= 0)
		{
			right_index--;
		}
		if (left_index < right_index)
		{
			int tmp = Array[left_index];
			Array[left_index] = Array[right_index];
			Array[right_index] = tmp;
		}
		else
		{
			break;
		}

	}
	int tmpr = Array[left_index];
	Array[left_index] = Array[end_index];
	Array[end_index] = tmpr;

	return left_index;
}



void QuickSortMRev(int * Array, int start_index, int end_index)
{
	if (start_index < end_index)
	{
		int part = PatitionMidRev(Array, start_index, end_index);
		QuickSortMRev(Array, start_index, part - 1);
		QuickSortMRev(Array, part + 1, end_index);
	}
}


void QuickSortMid(int* Array, int size_of_array, bool reverse = false)
{
	if (reverse == false)
	{
		QuickSortM(Array, 0, size_of_array - 1);
	}
	else
	{
		QuickSortMRev(Array, 0, size_of_array - 1);
	}
}
#endif // !QuickSort_h
