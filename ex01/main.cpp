#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Span.hpp"

int main() {
	srand(time(NULL));

	try {
		std::cout << "==========================================" << std::endl;
		std::cout << "              Big Span Test               " << std::endl;
		std::cout << "==========================================" << std::endl;
		Span span(15000);

		for (unsigned int i = 0; i < span.max_size(); i++)
			span.addNumber(rand() % 1000000);
	
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;	
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "==========================================" << std::endl;
		std::cout << "              Fill Span Test              " << std::endl;
		std::cout << "==========================================" << std::endl;

		Span fill_span(10);
		std::vector<int> vec;
		vec.push_back(27);
		vec.push_back(42);
		vec.push_back(69);
		fill_span.addNumbers(vec.begin(), vec.end());
		std::cout << "Fill Span Max Size: " << fill_span.max_size() << " Fill Span Size: " << fill_span.size() << std::endl;
		std::cout << "Longest span: " << fill_span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << fill_span.shortestSpan() << std::endl;
		std::cout << "Adding 8" << std::endl;
		fill_span.addNumber(8);
		std::cout << "Fill Span Max Size: " << fill_span.max_size() << " Fill Span Size: " << fill_span.size() << std::endl;
		std::cout << "Longest span: " << fill_span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << fill_span.shortestSpan() << std::endl;
		std::cout << "Adding 8 again" << std::endl;
		fill_span.addNumber(8);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "==========================================" << std::endl;
	std::cout << "               Subject test               " << std::endl;
	std::cout << "==========================================" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}