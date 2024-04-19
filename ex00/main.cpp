#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include "easyfind.hpp"

template <typename T>
void	display_container(const T& container)
{
	size_t i = 0;
	typename T::const_iterator it = container.begin();

	while (it != container.end())
		std::cout << i++ << ": " << *it++ << std::endl;
}

int main()
{
	std::vector<int> vector;
	std::list<int> list;

	std::srand(time(NULL));
	
	for (int i = 0; i < 10; i++) {
		vector.push_back(std::rand() % 10);
		list.push_back(std::rand() % 10);
	}

	std::cout << "Vector content:" << std::endl;
	display_container(vector);
	std::cout << "List content:" << std::endl;
	display_container(list);

	try {
		std::cout << "Trying to find 3 in vector:" << std::endl;
		std::cout << *easyfind(vector, 3) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to find 3 in list:" << std::endl;
		std::cout << *easyfind(list, 3) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to find 150 in vector:" << std::endl;
		std::cout << *easyfind(vector, 150) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to find 150 in list:" << std::endl;
		std::cout << *easyfind(list, 150) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
