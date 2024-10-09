#include "bubble_sort.h"

void bubble_sort(std::vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)  //����
	{
		bool swap_flag = false;
		for (int j = 0; j < size - i - 1; j++)  //����ıȽ�����
		{
			if (vec[j] > vec[j + 1])
			{
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
				swap_flag = true;   //�����˽���
			}
		}
		if (!swap_flag)
		{
			break;
		}
	}
}