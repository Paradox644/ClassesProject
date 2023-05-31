// ClassesProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Header.h"
#include <vector>
#include <cstdlib>
#include<string>

template <class Type, class Type2>
Type returnlesser(Type& a, Type2& b) {
	if (a<b)
		return a;
	else return a;
}
//template <class Type, class Type2>
//Type2 returnlesser(Type& a, Type2& b) {
//	if (a < b)
//		return a;
//	else return b;
//}
template<class Type>
Type returnlesser(Type& a, Type& b) {
	if (a < b)
		return a;
	else return b;
}
int main()
{
	Player hero,hero2;
	Enemy orc;
	Player result(returnlesser(hero, orc));
	hero.print_playercount();
	std::cout << result<<"///";
	std::cout << orc<<"///\n";
	

	//вектор
	std::vector <Player> vec;
	vec.push_back(hero);
	vec.push_back(hero2);
	std::cout <<"Vector size: " << vec.size()<<"\n";
	vec.pop_back();
	std::cout <<"Vector size: "<< vec.size()<<"\n";

	//
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
