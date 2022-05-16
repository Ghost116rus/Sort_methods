// Методы сортировки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>

void Buble_sort(int* arr, int n, int& count_of_comparison, int& count_of_exchanges, int& overhead_costs)
{
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = n-1; j >= i; j--)
		{
			if (arr[j - 1] > arr[j]) 
			{ 
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				count_of_exchanges++;
				overhead_costs += 2;
			}
			count_of_comparison++;
		}

	}
}

void Insertion_sort(int* arr, int n, int& count_of_comparison, int& count_of_exchanges, int& overhead_costs)
{
	for (size_t i = 1; i < n; i++)
	{
		int temp = arr[i]; int j = i - 1;

		while ((++count_of_comparison) && (j>=0) && (temp < arr[j]))
		{
			arr[j + 1] = arr[j]; j--;
			count_of_exchanges++;
		}
		arr[j + 1] = temp;
		overhead_costs += 3;
	}
}

void Selection_sort(int* arr, int n, int& count_of_comparison, int& count_of_exchanges, int& overhead_costs)
{
	for (size_t i = 0; i < n-1; i++)
	{
		int k = i; int temp = arr[i];
		for (size_t j= i+1; j < n; j++)
		{
			count_of_comparison++;
			if (arr[j] < temp) { k = j, temp = arr[j]; count_of_exchanges++; overhead_costs++; }
		}
		arr[k] = arr[i]; arr[i] = temp;
		overhead_costs += 4;

	}
}


int main()
{
	// { 15, 33, 42, 7, 12, 19 }
	// { 88, 55, 44, 22, 11, 2}
	// { 2, 4, 8, 9, 10, 16}

	const int size = 6;

	int arr1[size] = { 88, 55, 44, 22, 11, 2 };
	int count_of_comparison1 = 0;
	int count_of_exchanges1 = 0;
	int overhead_costs1 = 0;


	int arr2[size] = { 88, 55, 44, 22, 11, 2 };
	int count_of_comparison2 = 0;
	int count_of_exchanges2 = 0;
	int overhead_costs2 = 0;

	int arr3[size] = { 88, 55, 44, 22, 11, 2 };
	int count_of_comparison3 = 0;
	int count_of_exchanges3 = 0;
	int overhead_costs3 = 0;

	Buble_sort(arr1, size, count_of_comparison1, count_of_exchanges1, overhead_costs1);
	Insertion_sort(arr2, size, count_of_comparison2, count_of_exchanges2, overhead_costs2);
	Selection_sort(arr3, size, count_of_comparison3, count_of_exchanges3, overhead_costs3);

	std::cout << "First Arr:  " << "count of comparison - " << count_of_comparison1 << "\tcount of exchanges - " << count_of_exchanges1 << "\toverhead costs - " << overhead_costs1 << std::endl;
	std::cout << "Second Arr: " << "count of comparison - " << count_of_comparison2 << "\tcount of exchanges - " << count_of_exchanges2 << "\toverhead costs - " << overhead_costs2 << std::endl;
	std::cout << "Third Arr:  " << "count of comparison - " << count_of_comparison3 << "\tcount of exchanges - " << count_of_exchanges3 << "\toverhead costs - " << overhead_costs3 << std::endl;

}
