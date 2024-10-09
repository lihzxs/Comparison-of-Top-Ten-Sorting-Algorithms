#include "shell_sort.h"

void shell_sort(std::vector<int>& vec)
{
	int size = vec.size();
	int gap = size / 2;
	while (gap >= 1)
	{
		for (int i = gap; i < size; i++)
		{
			int index = i;
			int temp = vec[i];
			while (index - gap >= 0 and vec[index - gap] > temp)
			{
				vec[index] = vec[index - gap];
				index = index - gap;
			}
			vec[index] = temp;
		}
		gap = gap / 2;
	}
}
