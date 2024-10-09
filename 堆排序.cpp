#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
void print_vector(const std::vector<int>& heap)
{
	for (const auto& value : heap)
	{
		std::cout << "value:" << value << std::endl;
	}
}

void create_max_heap(std::vector<int>& heap, int root,int len)
{
	int temp = root;
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	if (left < len && heap[left] > heap[temp])
	{
		temp = left;
	}
	if (right < len && heap[right] > heap[temp])
	{
		temp = right;
	}
	if (temp != root)
	{
		std::swap(heap[temp], heap[root]);
		create_max_heap(heap, temp,len);
	}
}

void heap_sort(std::vector<int>& heap)
{
	int len = heap.size();
	for (int i = (len - 1) / 2; i >= 0; i--)
	{
		create_max_heap(heap, i,len);
	}
	for (int i = len - 1; i > 0; i--)
	{
		std::swap(heap[0], heap[i]);
		create_max_heap(heap, 0, i);
	}
	std::cout << "-----------------------------" << std::endl;
	//print_vector(heap);
}

typedef long long LL;
LL heap_sort_time(std::vector<int>&heap)
{
	// ��ȡ��ʼʱ���
	auto start = std::chrono::high_resolution_clock::now();

	// ������Ҫ�����ĺ���
	heap_sort(heap);

	// ��ȡ����ʱ���
	auto end = std::chrono::high_resolution_clock::now();

	// �������ʱ��
	std::chrono::duration<double, std::milli> duration = end - start;

	// ���س���ʱ��ĺ���ֵ
	return static_cast<LL>(duration.count());
}
/*
	������  һǧ��������������Ҫʮ������
*/

int main()
{
	std::random_device rd;
	std::mt19937_64 mt64(rd());
	std::uniform_int_distribution<int>dist(0, 100000000);
	std::vector<int>heap;
	for (int i = 1; i <= 10000000; i++)
	{
		heap.emplace_back(dist(mt64));
	}
	//print_vector(heap);
	LL ms = heap_sort_time(heap);
	std::cout << "������ִ�������ʱ��Ϊ:" << ms << "ms" << std::endl;
	return 0;
}