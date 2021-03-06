#include <iostream>
using namespace std;

void FillRand(int** arr, const int m, const int n);

template<typename T>void Print(T** arr, const int m, const int n);

template<typename T>T** Allocate(const int m, const int n); //Выделяет память под динамический массив
template<typename T>void Clear(T** arr, const int m); //Удаляет динамический массив

template<typename T>T** push_row_back(T** arr, int& m, const int n); //Добавляет строку в конец ДДМ
template<typename T>T** push_row_front(T** arr, int& m, const int n); //Добавляет строку в начало ДДМ
template<typename T>T** insert_row(T** arr, int& m, const int n, int index); // Вставляет строку в двумерный динамический массив по индексу

template<typename T>T** pop_row_back(T** arr, int& m, const int n); //Удаляет строку с конца ДДМ
template<typename T>T** pop_row_front(T** arr, int& m, const int n); //Удаляет строку с начала ДДМ
template <typename T> T** erase_row(T** arr, int& m, const int n, int index);  //Удаляет строку по указанному индексу

template<typename T>T** push_col_back(T** arr, const int m, int& n); //Добавляет столбец в конец ДДМ
template<typename T>T** push_col_front(T** arr, const int m, int& n); // Добавляет столбец в начало ДДМ
template<typename T>T** insert_col(T** arr, const int m, int& n, int index); //Добавляет столбец по указанному индексу

template<typename T>T** pop_col_back(T** arr, const int m, int& n); //Удаляет столбец в конце ДДМ
template<typename T>T** pop_col_front(T** arr, const int m, int& n); //Удаляет столбец в начале ДДМ
template<typename T>T** erase_col(T** arr, const int m, int& n, int index); //Удаляет столбец по указанному индексу

#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "RUS");

#ifdef DYNAMIC_MEMORY_2
	using std::cin;
	using std::cout;
	using std::endl;

	int m;	//Количство строк
	int n;	//Количество столбцов (элементов строки)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	int** arr = Allocate <int>(m, n);
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
	arr = erase_row(arr, m, n, index);
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
template <typename T> T** Allocate(const int m, const int n)
{
	//1) Создаем массив указателей:
	T** arr = new T* [m];
	//2) Выделяем память для строк двумерного динамического массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n] {};
	}
	return arr;
}
template <typename T> void Clear(T** arr, const int m)
{
	//      Удаление двумерного динамического массива:
	//1) Удаляем строки:
	for (int i = 0; i < m; i++)
		delete[] arr[i];
	//2) Удаляем массив указателей:
	delete[] arr;
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

template<typename T>void Print(T** arr, const int m, const int n)
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
template<typename T>T** push_row_back(T** arr, int& m, const int n)
{
	T** buffer = new T* [m + 1];
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

template<typename T>T** push_row_front(T** arr, int& m, const int n)
{
	T** buffer = new T* [m + 1]{};
	for (int i = 0; i < m; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	m++;
	return arr;
}

template <typename T> T** insert_row(T** arr, int& m, const int n, int index)
{
	if (index >= m)return arr;
	T** buffer = new T* [m + 1];
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

template <typename T> T** pop_row_back(T** arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	delete[] arr[m];
	delete[] arr;	
	arr = buffer;	
	return arr;
}

template <typename T> T** pop_row_front(T** arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
	return arr;
}

template <typename T> T** erase_row(T** arr, int& m, const int n, int index)
{
	T** buffer = new T*[m - 1]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index + 1; i < m; i++)
		buffer[i - 1] = arr[i];
	delete[] arr;
	m--;
	return buffer;
}

template <typename T> T** push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
	return arr;
}
template <typename T> T** push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
			buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
	return arr;
}
template <typename T> T** insert_col(T** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
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

template <typename T> T** erase_col(T** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
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
template <typename T> T** pop_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[--n]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
		return arr;
	}
}

template <typename T> T** pop_col_front(T** arr, const int m, int& n)
{
	
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[--n]{};
		for (int j = 0; j < n; j++)
			buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
		return arr;
	}
}