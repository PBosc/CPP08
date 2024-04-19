#include <list>
#include <iostream>
#include <algorithm>
#include "MutantStack.hpp"

int main() {
	srand(time(NULL));

	MutantStack<int> mutant_stack;

	for (int i = 0; i < 150; i++)
		mutant_stack.push(rand() % 1000);

	std::cout << "Size of mutant stack: " << mutant_stack.size() << std::endl;
	std::cout << "Stack filled with 150 random numbers" << std::endl;
	
	for (size_t i = 0; i < mutant_stack.size(); i++) {
		std::cout << mutant_stack.top() << std::endl;
		mutant_stack.pop();
	}

	MutantStack<int>::iterator iterator_begin = mutant_stack.begin();
	MutantStack<int>::container_type::iterator iterator_end = mutant_stack.end();
	MutantStack<int>::container_type::reverse_iterator rev_iterator_begin = mutant_stack.rbegin();
	MutantStack<int>::container_type::reverse_iterator rev_iterator_end = mutant_stack.rend();
	const MutantStack<int>::container_type::const_iterator const_iterator_begin = mutant_stack.cbegin();
	const MutantStack<int>::container_type::const_iterator const_iterator_end = mutant_stack.cend();
	const MutantStack<int>::container_type::const_reverse_iterator const_rev_iterator_begin = mutant_stack.crbegin();
	const MutantStack<int>::container_type::const_reverse_iterator const_rev_iterator_end = mutant_stack.crend();

	std::fill(iterator_begin, iterator_end, 1);
	std::cout << "Stack filled with 150 1" << std::endl;

	for (size_t i = 0; i < mutant_stack.size(); i++) {
		std::cout << mutant_stack.top() << std::endl;
		mutant_stack.pop();
	}

	for (; iterator_begin != iterator_end; iterator_begin++)
		mutant_stack.push(rand() % 1000);

	std::cout << "Stack filled with 150 random numbers using iterators" << std::endl;
	
	for (size_t i = 0; i < mutant_stack.size(); i++) {
		std::cout << mutant_stack.top() << std::endl;
		mutant_stack.pop();
	}

	(void) iterator_begin;
	(void) iterator_end;
	(void) rev_iterator_begin;
	(void) rev_iterator_end;
	(void) const_iterator_begin;
	(void) const_iterator_end;
	(void) const_rev_iterator_begin;
	(void) const_rev_iterator_end;

	std::cout << "==========================================" << std::endl;
	std::cout << "               Subject Tests              " << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "Tests with a stack" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::container_type::iterator it = mstack.begin();
	MutantStack<int>::container_type::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		it++;
	}
	std::stack<int> s(mstack);

	std::cout << "Tests with a list" << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it_list = lst.begin();
	std::list<int>::iterator ite_list = lst.end();

	++it_list;
	--it_list;

	while (it_list != ite_list) {
		std::cout << *it_list << std::endl;
		++it_list;
	}

	std::deque<int> d_list(lst.begin(), lst.end());
	std::stack<int> s_list(d_list);

	return 0;
}
