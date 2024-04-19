#include <iterator>
#include <algorithm>
#include "Span.hpp"

Span::Span() : _max_size(0) {}

Span::Span(const Span &source) : _data(source._data), _max_size(source._max_size) {}

Span& Span::operator=(const Span &source) {
	if (this == &source)
		return *this;

	_max_size = source._max_size;
	_data = source._data;
	return *this;
}

Span::~Span() {}

Span::Span(unsigned int N) : _max_size(N) {}

unsigned int Span::size() const { return _data.size(); }
unsigned int Span::max_size() const { return _max_size; }

void Span::addNumber(int nb) {
	if (size() >= _max_size)
		throw Span::SpanFullException();
	
	_data.insert(nb);
}

int Span::shortestSpan() {
	if (size() < 2)
		throw Span::SpanEmptyException();

	std::multiset<int>::const_iterator it = _data.begin();
	int previous = *it++;
	unsigned int min_span = *it - previous;

	while (it != _data.end()) {
		unsigned int span = *it - previous;
		if (span < min_span)
			min_span = span;
		previous = *it;
		it++;
	}

	return min_span;
}

int Span::longestSpan() {
	if (size() < 2)
		throw Span::SpanEmptyException();

	return *_data.rbegin() - *_data.begin();
}

std::multiset<int>::iterator Span::begin() { return _data.begin(); }

std::multiset<int>::iterator Span::end() { return _data.end(); }

const char *Span::SpanFullException::what() const throw() { return "Span is full! Can't add an extra number"; }

const char *Span::SpanEmptyException::what() const throw() { return "Span doesn't contain enough elements to calculate a...span."; }
