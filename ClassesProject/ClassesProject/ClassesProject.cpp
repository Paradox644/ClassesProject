// ClassesProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Header.h"
#include <vector>
#include <cstdlib>
/*
template <class TELEM>
class TContainer
{
protected:
	TELEM* elem; // массив хранимых элементов
	int size; // размер массива
	int count; // к-во реально хранимых элементов
	const static int sizestep = 10; // шаг наращивания размера массива
public:
	TContainer() {
		size = 10;
	}
		
	TContainer(const TContainer& _cnt);
	~TContainer();
	const int& Сount() const { return count; }
	int& Сount() { return count; }
	const int& Sizestep() const { return sizestep; }
	void Add(TELEM _elm); // добавить элемент
	void Del(TELEM _elm); // удалить элемент по его значению
	void Del(int index); // удалить элемент по его номеру
	TELEM& operator[](int index); // индексация по номеру
		TELEM& operator[](const TELEM& _elm); // индексация по содержанию
		const TELEM& operator[](int index) const; //индексация по номеру
		const TELEM& operator[](const TELEM& _elm) const; //индексация по содержанию
		TContainer& operator=(const TContainer& _cnt); //присваивание контейнеров
		TContainer operator+(const TContainer& _cnt); // объединение контейнеров
		TContainer operator*(const TContainer& _cnt); // пересечение контейнеров
		TContainer operator-(const TContainer& _cnt); // разность контейнеров
protected:
	void resize(int dsize = 0); // увеличить длину контейнера
		int _find(const TELEM& _elm) const; // найти элемент
};
*/
int main()
{
	Player protag,protagfriend;
	Enemy orc;
	std::vector <Player> vec;
	vec.push_back(protag);
	vec.push_back(protagfriend);
	std::cout << vec.size();
	vec.pop_back();
	std::cout << vec.size();

	//std::cout << protag;
	//protag.print_playercount();
	//std::cout << protag;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
