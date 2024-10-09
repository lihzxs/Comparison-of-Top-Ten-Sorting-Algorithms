#include "quick_sort.h"

void quick_sort(std::vector<int>& vec, int left, int right)
{
	if (left >= right) return;
	int l = left;
	int r = right;
	int pivot = vec[l];
	while (l < r)
	{
		while (l < r && vec[r] >= pivot) r--;
		if (l < r) vec[l] = vec[r];
		while (l < r && vec[l] <= pivot) l++;
		if (l < r) vec[r] = vec[l];
	}
	vec[l] = pivot;
	quick_sort(vec, left, l - 1);
	quick_sort(vec, l + 1, right);
}
