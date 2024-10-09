#include <iostream>
#include <vector>
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "std_sort.h"
#include "merge_sort.h"
#include "bucket_sort.h"
#include "rbtree.h"
#include <random>
#include <chrono>
#include <thread>
void print_Vector(const std::vector<int>& vec)
{
	for (const auto& value : vec)
	{
		std::cout << "value :" << value << std::endl;
	}
}
//����ð������ִ�е�ʱ��
void bubble_sort_test(std::vector<int> vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	bubble_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	long long result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "ð������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//����ѡ�������ִ��ʱ��
void selection_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	selection_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "ѡ������ִ�е�ʱ��Ϊ:" << result <<"ms"<< std::endl;
}
//������������ִ��ʱ��
void insertion_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	insertion_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "��������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//������������ִ��ʱ��
void counting_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	counting_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "��������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//������������ִ��ʱ��
void radix_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	radix_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "��������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//����ϣ�������ִ��ʱ��
void shell_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	shell_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "ϣ������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//������������ִ��ʱ��
void quick_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	quick_sort(vec,0,vec.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "��������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//����������ִ��ʱ��
void heap_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	heap_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//�����׼���std::sort�����ִ��ʱ��
void std_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	std_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "��׼��std::sort����ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//�����׼���std::stable_sort�����ִ��ʱ��
void std_stable_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	std_stable_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "��׼��std::stable_sort����ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//����鲢�����ִ��ʱ��
void merge_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	merge_sort(vec,0,vec.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "�鲢����ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
//��������������ʱ��
void rbtree_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	insert_data_to_set(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "�������������ִ�е�ʱ��Ϊ:" << result << "ms" << std::endl;
}
int main()
{
	std::random_device rd;
	std::mt19937_64 mt(rd());
	std::uniform_int_distribution<int>dist(0, 1000000000);
	std::vector<int>vec;
	for (int i = 0; i < 10000000; i++)
	{
		vec.emplace_back(dist(mt));
	}
#if 1
	std::thread bubble_thread(bubble_sort_test, vec);
	std::thread select_thread(selection_sort_test, vec);
	std::thread insert_thread(insertion_sort_test, vec);
	std::thread counting_thread(counting_sort_test, vec);
	std::thread radix_thread(radix_sort_test, vec);
	std::thread shell_thread(shell_sort_test, vec);
	std::thread quick_thread(quick_sort_test, vec);
	std::thread heap_thread(heap_sort_test, vec);
	std::thread std_sort_thread(std_sort_test, vec);
	std::thread std_stable_sort_thread(std_stable_sort_test, vec);
	std::thread merge_sort_thread(merge_sort_test, vec);
	std::thread rbtree_sort_thread(rbtree_sort_test, vec);
	rbtree_sort_thread.join();
	merge_sort_thread.join();
	std_stable_sort_thread.join();
	std_sort_thread.join();
	heap_thread.join();
	quick_thread.join();
	shell_thread.join();
	radix_thread.join();
	counting_thread.join();
	bubble_thread.join();
	select_thread.join();
	insert_thread.join();
#endif
	return 0;
}