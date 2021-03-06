/*
Завдання 1.
Створити шаблон функції, яка приймає список ініціалізації(std::initalizer_list<>) 
як параметр і повертає найменший та найбільший  елементи  списку ініціалізації. 
Результат повертати у вигляді шаблонної структури з двох полів(minimum, maximum).
template<typename T>
struct result
{
T minimum, maximum;
};
template <typename T>
result<T> max_min(const std::initializer_list<T> &list)
{
//your code
}
Перевірити роботу шаблону функції.

*/


#include "stdafx.h"
#include <iostream> 
#include <string>


using namespace std;

template<typename T>
struct result
{
	T minimum, maximum;
};

template <typename T>
result<T> max_min(const initializer_list<T> &list);

int main()
{
	initializer_list<string>listSt = { "one", "two", "three" };
	initializer_list<int>listInt = { 1, 7, 5, 3 };

	cout << "List Int:\t";
	for (auto elem : listInt)
		cout << elem << " ";
	cout << "\nMax: " << max_min(listInt).maximum << "\nMin: " << max_min(listInt).minimum << endl << endl;

	cout << "List Double:\t1.0 2.5 -3.7";
	cout << "\nMax: " << max_min({1.0, 2.5, -3.7}).maximum << "\nMin: " << max_min({ 1.0, 2.5, -3.7 }).minimum << endl << endl;

	cout << "List String:\t";
	for (auto elem : listSt)
		cout << elem << " ";
	cout << "\nMax: " << max_min<string>(listSt).maximum << "\nMin: " << max_min(listSt).minimum << endl;


	cout << endl;
	system("pause");
	return 0;
}

template <typename T>
result<T> max_min(const initializer_list<T> &list)
{
	result <T> tmp;
	tmp.minimum = *list.begin();
	tmp.maximum = *list.begin();
	for (auto elem : list)
	{
		if (elem > tmp.maximum)
			tmp.maximum = elem;
		if (elem < tmp.minimum)
			tmp.minimum = elem;
	}
	return tmp;
}

