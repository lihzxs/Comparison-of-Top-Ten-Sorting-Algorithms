#include "heap_sort.h"
#include <algorithm>
#include <iostream>
void make_heap(std::vector<int>& heap, int root, int len)
{
	int son = root * 2 + 1;  //����
	while (son < len)
	{
		//���ж�son + 1�Ƿ�Ϸ��������������������Խ��
		if (son + 1 < len && heap[son + 1] > heap[son]) son++;  //����Һ��Ӵ�ʱ�����Ӵ�
		if (heap[son] > heap[root])
		{
			std::swap(heap[son], heap[root]);
			root = son;
			son = root * 2 + 1;
		}
		else//��������������ֱ������ѭ�������������ѭ��������Ϊsonֵû�б�
		{
			break;
		}
	}
}

void heap_sort(std::vector<int>& heap)
{
	//ʵ�ִ�С�����������ȹ���һ�������
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
