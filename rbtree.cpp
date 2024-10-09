#include "rbtree.h"
#include <iostream>
void insert_data_to_set(std::vector<int>& vec)
{
	std::set<int>s;
	for (const auto& value : vec)
	{
		s.insert(value);
	}
}
