#include <iostream>
#include <ctime>
#include <cstdlib>

// Задание 1. Общий делитель
int divider(int n1, int n2);

// Задание 2. mirror_number
int mirror_number(int n3);

// Задание 3. 
int search_index_sort(int arr[], const int length, int N);

// Задание 4. Пустой массив.
template <typename T>
void fill_arr(T arr[], const int length, int A, int B);



int main() {
	setlocale(LC_ALL, "Russian");
	int x, y, z, N, B, E;

	// Задание 1. Общий делитель.

	std::cout << "\t\tЗадание 1.\n Общий делитель.\n";
	std::cout << " Введите два числа --> ";
	std::cin >> x >> y;
	std::cout << " Наибольший общий делитель --> " << divider(x, y) << '\n';

	// Задание 2. mirror_number
	std::cout << "\n\t\tЗадание 2.\n Зеркальное число.\n";
	std::cout << " Введите число --> ";
	std::cin >> z;
	std::cout << " Отраженное число --> " << mirror_number(z) << '\n';


	// Задание 3. 
	std::cout << "\n\t\tЗадание 3.\n Сортировка от N.\n";
	const int size3 = 10;
	int arr3[size3]{ 1, 5, 4, 6, 7, 5, 3, 2, 4, 6 };
	std::cout << " Изначальный массив --> ";
	for (int i = 0; i < size3; i++)
		std::cout << arr3[i] << ", ";
	std::cout << "\b\b.";
	std::cout << "\n Введите число N --> ";
	std::cin >> N;
	std::cout << " Позиция числа N в  массиве = " << search_index_sort(arr3, size3, N) << " .\n";
	std::cout << " Отсортированный массив --> ";
	for (int i = 0; i < size3; i++)
		std::cout << arr3[i] << ", ";
	std::cout << "\b\b.\n\n";

	// Задание 4. Пустой массив.
	const int size4 = 10;
	int arr4[size4];
	std::cout << " Введите начало и конец диапазона --> ";
	std::cin >> B >> E;
	if (B == E)
		B++;
	fill_arr(arr4, size4, B, E);
	std::cout << " Массив --> ";
	std::cout << '[';
	for (int i = 0; i < size4; i++)
		std::cout << arr4[i] << ", ";
	std::cout << "\b\b].";


	return 0;
}

// Задание 1. Общий делитель
int divider(int n1, int n2) {
	int nod = 1;
	if (n1 < 0)
		n1 *= -1;
	if (n2 < 0)
		n2 *= -1;
	if (n1 <= n2) {
		for (int i = n1; i > 0; i--)
			if (n1 % i == 0 && n2 % i == 0) {
				nod = i;
				break;
			}
	}
	else {
		for (int i = n2; i > 0; i--)
			if (n1 % i == 0 && n2 % i == 0) {
				nod = i;
				break;
			}
	}
	return nod;

}

// Задание 2. mirror_number
int mirror_number(int n3) {
	int mirror = 0;
	while (n3 > 0) {
		mirror = mirror * 10 + n3 % 10;
		n3 /= 10;
	}
	return mirror;
}

// Задание 3. 
int search_index_sort(int arr[], const int length, int N) {
	int tmp = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == N) {
			tmp = i;
			break;
		}
	for (int i = length - 1; i > 0; i--)
		for (int j = tmp - 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	return tmp;
}

// Задание 4. Пустой массив.
template <typename T>
void fill_arr(T arr[], const int length, int A, int B) {
	if (B > A) {
		srand(time(NULL));
		for (int i = 0; i < length; i++)
			arr[i] = rand() % (B - A) + A;
	}
	else {
		srand(time(NULL));
		for (int i = 0; i < length; i++)
			arr[i] = rand() % (A - B) + B;
	}
}

