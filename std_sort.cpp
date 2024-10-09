#include "std_sort.h"
#include <algorithm>
void std_sort(std::vector<int>& vec)
{
	std::sort(vec.begin(), vec.end());
}

void std_stable_sort(std::vector<int>& vec)
{
	std::stable_sort(vec.begin(), vec.end());
}
