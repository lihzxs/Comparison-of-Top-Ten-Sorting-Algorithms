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
//计算冒泡排序执行的时间
void bubble_sort_test(std::vector<int> vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	bubble_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	long long result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "冒泡排序执行的时间为:" << result << "ms" << std::endl;
}
//计算选择排序的执行时间
void selection_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	selection_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "选择排序执行的时间为:" << result <<"ms"<< std::endl;
}
//计算插入排序的执行时长
void insertion_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	insertion_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "插入排序执行的时间为:" << result << "ms" << std::endl;
}
//计算计数排序的执行时长
void counting_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	counting_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "计数排序执行的时间为:" << result << "ms" << std::endl;
}
//计算基数排序的执行时长
void radix_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	radix_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "基数排序执行的时间为:" << result << "ms" << std::endl;
}
//计算希尔排序的执行时长
void shell_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	shell_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "希尔排序执行的时间为:" << result << "ms" << std::endl;
}
//计算快速排序的执行时长
void quick_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	quick_sort(vec,0,vec.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "快速排序执行的时间为:" << result << "ms" << std::endl;
}
//计算堆排序的执行时长
void heap_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	heap_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "堆排序执行的时间为:" << result << "ms" << std::endl;
}
//计算标准库的std::sort排序的执行时长
void std_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	std_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "标准库std::sort排序执行的时间为:" << result << "ms" << std::endl;
}
//计算标准库的std::stable_sort排序的执行时长
void std_stable_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	std_stable_sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "标准库std::stable_sort排序执行的时间为:" << result << "ms" << std::endl;
}
//计算归并排序的执行时长
void merge_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	merge_sort(vec,0,vec.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "归并排序执行的时间为:" << result << "ms" << std::endl;
}
//红黑树排序数组的时长
void rbtree_sort_test(std::vector<int>vec)
{
	auto begin = std::chrono::high_resolution_clock::now();
	insert_data_to_set(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "红黑树排序数组执行的时长为:" << result << "ms" << std::endl;
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