#include "merge_sort.h"

void merge_value(std::vector<int>& vec, int left, int mid,int right)
{
	std::vector<int>temp;
	int l = left;
	int r = mid + 1;
	while (l <= mid && r <= right)
	{
		if (vec[l] <= vec[r])
		{
			temp.emplace_back(vec[l]);
			l++;
		}
		else
		{
			temp.emplace_back(vec[r]);
			r++;
		}
	}
	while (l <= mid)
	{
		temp.emplace_back(vec[l++]);
	}
	while (r <= right)
	{
		temp.emplace_back(vec[r++]);
	}
	for (int i = 0; i < temp.size(); i++)
	{
		vec[left + i] = temp[i];
	}
}

void merge_sort(std::vector<int>& vec,int left,int right)
{
	if (left == right) return;
	int mid = (left + right) / 2;
	merge_sort(vec,left, mid);
	merge_sort(vec, mid + 1, right);
	merge_value(vec, left, mid, right);
}
