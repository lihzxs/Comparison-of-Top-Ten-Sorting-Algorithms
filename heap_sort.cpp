#include "heap_sort.h"
#include <algorithm>
#include <iostream>
void make_heap(std::vector<int>& heap, int root, int len)
{
	int son = root * 2 + 1;  //左孩子
	while (son < len)
	{
		//先判断son + 1是否合法，，，否则这里会数组越界
		if (son + 1 < len && heap[son + 1] > heap[son]) son++;  //如果右孩子此时比左孩子大
		if (heap[son] > heap[root])
		{
			std::swap(heap[son], heap[root]);
			root = son;
			son = root * 2 + 1;
		}
		else//不发生交换，，直接跳出循环，，否则会死循环，，因为son值没有变
		{
			break;
		}
	}
}

void heap_sort(std::vector<int>& heap)
{
	//实现从小到大排序，首先构造一个大根堆
	int size = heap.size();
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		make_heap(heap, i, size);
	}
	for (int i = size - 1; i > 0; i--)
	{
		std::swap(heap[0], heap[i]);
		make_heap(heap, 0, i);
	}
}
