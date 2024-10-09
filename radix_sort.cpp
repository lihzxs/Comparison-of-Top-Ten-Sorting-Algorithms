#include "radix_sort.h"
#include <iostream>
int find_max_value(std::vector<int>& vec)
{
	int max = -1;
	if (!vec.empty())
	{
		max = vec[0];
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] > max)
			{
				max = vec[i];
			}
		}
	}
	return max;
}

int counting_max_length(int max_value)
{
	int length = 0;
	while (max_value != 0)
	{
		max_value = max_value / 10;
		length++;
	}
	return length;
}

void radix_sort(std::vector<int>& vec)
{
	int max_value = find_max_value(vec);
	int length = counting_max_length(max_value);
	int base = 1;
	std::vector<std::vector<int>>bucket(10);
	while (length--)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			int value = vec[i];
			int index = (value / base) % 10;
			bucket[index].push_back(value);
		}
		vec.clear();
		//遍历每个桶，，先进入桶的元素先输出
		for (auto it = bucket.begin();it != bucket.end();it++)
		{
			std::vector<int>& temp = *it;
			for (int i = 0; i < temp.size(); i++)
			{
				vec.emplace_back(temp[i]);
			}
			temp.clear();
		}
		base = base * 10;
	}
}
