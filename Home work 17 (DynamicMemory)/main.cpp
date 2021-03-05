﻿#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);

void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);	//Вставляет значение в массив по указанному индексу

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);	//Удаляет значение из массива по указанному индексу

int** Allocate(const int m, const int n);
void Clear(int** arr, const int m);

int** push_row_back(int** arr, int& m, const int n);
int** push_row_front(int** arr, int& m, const int n);
int** insert_row(int** arr, int& m, const int n, int index); // Вставляет строку в двумерный динамический массив по индексу
int** pop_row_back(int** arr, int& m, const int n);
int** pop_row_front(int** arr, int& m, const int n);
int** erase_row(int** arr, int& m, int index);  //Удаляет строку по указанному индексу

int** push_col_back(int** arr, const int m, int& n);
int** push_col_front(int** arr, const int m, int& n);
int** insert_col(int** arr, const int m, int& n, int index); //Удаляет строку по указанному индексу

int** pop_col_back(int** arr, const int m, int& n);
int** pop_col_front(int** arr, const int m, int& n);
int** erase_col(int** arr, const int m, int& n, int index); //Удаляет столбец по указанному индексу

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "RUS");
#ifdef DYNAMIC_MEMORY_1
	int n; //Размер массива
	cout << "Введите размер массива"; cin >> n;
	//Объявление динамического массива:
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение"; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Удаление последнего элемента из массива"; cin >> value;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Удаление первого элемента из массива"; cin >> value;
	arr = pop_front(arr, n);
	Print(arr, n);
	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "Введите удаляемое значение по индексу: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	using std::cin;
	using std::cout;
	using std::endl;

	int m;	//Количство строк
	int n;	//Количество столбцов (элементов строки)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	int** arr = Allocate(m, n);

	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем строку в конец:\n";
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем строку в начало:\n";
	arr = push_row_front(arr, m, n);
	Print(arr, m, n);

	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = insert_row(arr, m, n, index);
	Print(arr, m, n);

	cout << "Введите индекс удаляемой строки : "; cin >> index;
	arr = erase_row(arr, m, index);
	Print(arr, m, n);

	cout << "Добавление столбца в конец массива:\n";
	arr = push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца в начало массива:\n";
	arr = push_col_front(arr, m, n);
	Print(arr, m, n);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	arr = insert_col(arr, m, n, index);
	Print(arr, m, n);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	arr = erase_col(arr, m, n, index);
	Print(arr, m, n);

	cout << "Удаление последней строки:\n";
	arr = pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление нулевой строки:\n";
	arr = pop_row_front(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление последнего столбца:\n";
	arr = pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление нулевого столбца:\n";
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	
	Clear(arr, m);
#endif // DYNAMIC_MEMORY_2
}

int** Allocate(const int m, const int n)
{
	//1) Создаем массив указателей:
	int** arr = new int* [m];
	//2) Выделяем память для строк двумерного динамического массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}
void Clear(int** arr, const int m)
{
	//      Удаление двумерного динамического массива:
	//1) Удаляем строки:
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	//2) Удаляем массив указателей:
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}

	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


int* push_back(int arr[], int& n, int value)
{
	//1) Создаем буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	//2) Копируем значения из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	// 4) Подменяем адрес старого массива адресом нового массива
	arr = buffer;
	// 5) Записываем значение в конец массива
	arr[n] = value;
	// 6) После добавления значения, размер массива увеличивается на 1
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* insert(int arr[], int& n, int value, int index)
{
	if (index >= n) return arr;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;
}

int** push_row_back(int** arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[m] = new int[n] {};
	m++;
	return arr;
}

int** push_row_front(int** arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	m++;
	return arr;
}

int** insert_row(int** arr, int& m, const int n, int index)
{
	if (index >= m)return arr;
	int** buffer = new int* [m + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new int[n] {};
	m++;
	return arr;
}

int** pop_row_back(int** arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	delete[] arr[m];
	delete[] arr;	
	arr = buffer;	
	return arr;
}
int** pop_row_front(int** arr, int& m, const int n)
{
	int** buffer = new int* [--m];
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
	return arr;
}
int** erase_row(int** arr, int& m, int index)
{
	int** buffer = new int*[m - 1]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index + 1; i < m; i++)
		buffer[i - 1] = arr[i];
	delete[] arr;
	m--;
	return buffer;
}

int** push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
	return arr;
}

int** push_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
	return arr;
}

int** insert_col(int** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < index; j++)
			buffer[j] = arr[i][j];
		for (int j = index; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
	return arr;
}

int** erase_col(int** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n - 1]{};
		for (int j = 0; j < index; j++)
			buffer[j] = arr[i][j];
		for (int j = index + 1; j < n; j++)
			buffer[j - 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
	return arr;
}
int** pop_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[--n]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
		return arr;
	}
}
int** pop_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[--n]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
		return arr;
	} 
}