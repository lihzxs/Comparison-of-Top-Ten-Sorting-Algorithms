#include "selection_sort.h"

void selection_sort(std::vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		int index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (vec[j] < vec[index])
			{
				index = j;
			}
		}
		int temp = vec[index];
		vec[index] = vec[i];
		vec[i] = temp;
	}
}
