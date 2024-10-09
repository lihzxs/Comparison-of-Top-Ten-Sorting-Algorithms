#include "insertion_sort.h"

void insertion_sort(std::vector<int>& vec)
{
	int size = vec.size();
	for (int i = 1; i < size; i++)
	{
		int temp = vec[i];
		int index = i;
		while (index - 1 >= 0 and vec[index - 1] > temp)
		{
			vec[index] = vec[index - 1];
			index--;
		}
		vec[index] = temp;
	}
}
