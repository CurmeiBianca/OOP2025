#pragma once
#include <vector>

using namespace std;

template <typename T>
class myClass
{
public:
	void sortList(vector<T>& list)
	{
		if (list.size() < 1)
		{
			printf("List too small to sort\n");
			return;
		}

		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j] < list[j + 1])
				{
					int temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
			}
		}
	}
};

template<typename T>
bool isSorted(const vector<T>& list)
{
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i] < list[i - 1])
			return false;
	}
}