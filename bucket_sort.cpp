#include "bucket_sort.h"
void insertion_sort_(std::vector<int>& vec)
{
	int size = vec.size();
	for (int i = 1; i < size; i++)
	{
		int index = i;
		int temp = vec[i];
		while (index - 1 >= 0 && vec[index - 1] > temp)
		{
			vec[index] = vec[index - 1];
			index--;
		}
		vec[index] = temp;
	}
}

void bucket_sort(std::vector<int>& vec)
{
	std::vector<std::vector<int>>bucket(4);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] >= 0 && vec[i] <= 1000000)
		{
			bucket[0].emplace_back(vec[i]);
		}
		else if (vec[i] >= 1000001 && vec[i] <= 10000000)
		{
			bucket[1].emplace_back(vec[i]);
		}
		else if (vec[i] >= 10000001 && vec[i] <= 100000000)
		{
			bucket[2].emplace_back(vec[i]);
		}
		else
		{
			bucket[3].emplace_back(vec[i]);
		}
	}
	for (int i = 0; i < bucket.size(); i++)
	{
		std::vector<int>& temp = bucket[i];
		insertion_sort_(temp);
	}
	vec.clear();
	for (int i = 0; i < bucket.size(); i++)
	{
		std::vector<int>& temp = bucket[i];
		for (const int& value : temp)
		{
			vec.emplace_back(value);
		}
	}
}
