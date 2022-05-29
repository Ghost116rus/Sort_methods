// Методы сортировки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>


int getValue(int condition, const char* string)
{
	while (true)													// цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "Ошибка! Пожалуйста, повторите ввод! \n";
			std::cin.clear();										// то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');							// и удаляем значения предыдущего ввода из входного буфера
			std::cout << string;
		}
		else // если всё хорошо и выполнятся условия, то возвращаем a
		{
			switch (condition)
			{
			case 15:
				if ((a > 0)&&(a < 100000)) { return a; }

				std::cout << "Вы должны ввести натуральное число, меньше 100000\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case 16:												// На будущее

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "Вы должны ввести либо 0, либо 1\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;
			case 17:

				if (((int)a > 0) && ((int)a < 6)) { return a; }

				std::cout << "У меню всего 4 функции! Повторите ввод: ";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			default:
				return a;
			}

		}

	}
}


void Bubble_sort(int* arr, int n, unsigned long long& count_of_comparison, unsigned long long& count_of_exchanges)
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
			}
			count_of_comparison++;
		}

	}
}

void Insertion_sort(int* arr, int n, unsigned long long& count_of_comparison, unsigned long long& count_of_exchanges)
{
	for (size_t i = 1; i < n; i++)
	{
		int j = i - 1; 

		while ((++count_of_comparison)&&(j >= 0)&&(arr[i] < arr[j]))
		{
			j--;
		}

		if ((j + 1) != i)
		{
			int temp = arr[i];	int l = i - 1; count_of_exchanges++;
			while (l >= j + 1)
			{
				arr[l + 1] = arr[l]; l--;
				count_of_exchanges++;
			}
			arr[j + 1] = temp;
			count_of_exchanges++;
		}

	}
	count_of_exchanges = count_of_exchanges / 3;
}

void Selection_sort(int* arr, int n, unsigned long long& count_of_comparison, unsigned long long& count_of_exchanges)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		int min = i; 
		for (size_t j = i + 1; j < n; j++)
		{
			count_of_comparison++;
			if (arr[j] < arr[min]) 
			{ 
				min = j; 
			}
		}
		if (i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
			count_of_exchanges++;
		}
	}
}


int* Make_arr(int size)
{
	int* temp = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = rand() % 100000;
	}
	return temp;
}

void menu()
{
	std::cout << "\n\nФункционал программы:\n"
		<< "1. Метод обмена\n"
		<< "2. Метод Вставок\n"
		<< "3. Метод Выбора\n"
		<< "4. Вывести меню\n"
		<< "5. Завершить работу\n";
}

int* Copy(int* arr, int size)
{
	int* temp = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	return temp;
}
void Show_arr(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (!(i % 15)) { std::cout << std::endl; }
		std::cout << arr[i] << "\t";
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int* arr = nullptr;

	std::cout << "Введите размер массива: "; int size = getValue(15, "Введите размер массива: ");
	
	arr = Make_arr(size);
	std::cout << "\nИсходный массив:\n"; Show_arr(arr, size);

	int user_choice = -1;

	menu(); std::cout << "\nВыберите действие: ";
	user_choice = getValue(17, "Выберите действие: ");

	while (user_choice != 5)
	{
		int* copy = nullptr;
		int temp = 0;
		unsigned long long count_of_comparison = 0;
		unsigned long long count_of_exchanges = 0;


		if (user_choice != 4)
		{
			std::cout << "\nВыводить отсортированный массив? 0 - нет, 1 - да\nВведите: ";
			temp = getValue(16, "Выводить отсортированный массив? 0 - нет, 1 - да\nВведите: ");

			copy = Copy(arr, size);
		}

		switch (user_choice)
		{
		case 1:

			Bubble_sort(copy, size, count_of_comparison, count_of_exchanges);
			std::cout << "\n  Метод обмена ";
			break;
		case 2:

			Insertion_sort(copy, size, count_of_comparison, count_of_exchanges);
			std::cout << "\n  Метод Вставок ";
			break;
		case 3:

			Selection_sort(copy, size, count_of_comparison, count_of_exchanges);
			std::cout << "\n  Метод Выбора ";
			break;
		case 4:
			menu();
			break;
		default:
			break;
		}

		if (user_choice != 4)
		{

			std::cout << "Анализ:\n" << "1. Количество сравнений - " << count_of_comparison
				<< "\n2. Количество перестановок - " << count_of_exchanges << std::endl;

		}

		if (temp)
		{
			std::cout << "Исходный массив:\n"; Show_arr(arr, size);
			std::cout << "\n\nОтсортированный массив:\n"; Show_arr(copy, size);
		}


		delete copy; copy = nullptr;

	std::cout << "\nВыберите действие: ";
		user_choice = getValue(17, "Выберите действие: ");
	}

	delete arr;
}
