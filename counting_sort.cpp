#include "counting_sort.h"
#include <iostream>
void find_min_max_value(std::vector<int>& vec, int& min, int& max)
{
	if (!vec.empty())
	{
		min = max = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] < min)
			{
				min = vec[i];
			}
			if (vec[i] > max)
			{
				max = vec[i];
			}
		}
	}
}
void counting_sort(std::vector<int>&vec)
{
	int min;
	int max;
	find_min_max_value(vec, min, max);
	int new_size = max - min + 1;
	std::vector<int>temp(new_size);
	for (int i = 0; i < vec.size(); i++)
	{
		int value = vec[i];
		temp[value - min]++;
	}

	vec.resize(0);
	for (int i = 0; i < temp.size(); i++)
	{
		int cnt = temp[i];
		while (cnt--)
		{
			vec.emplace_back(i + min);
		}
	}
	temp.resize(0);
	temp.shrink_to_fit();
}