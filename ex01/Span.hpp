#ifndef SPAN_HPP
# define SPAN_HPP
# include <set>
# include <stdexcept>

class Span {
	private:
		std::multiset<int> _data;
		unsigned int _max_size;

	public:
		Span();
		Span(const Span &source);
		Span& operator=(const Span &source);
		~Span();

		Span(unsigned int N);

		unsigned int size() const;
		unsigned int max_size() const;
		std::multiset<int>::iterator begin();
		std::multiset<int>::iterator end();
		
		void addNumber(int nb);

		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			for (InputIterator it = begin; it != end; ++it)
				addNumber(*it);
		}

		int shortestSpan();
		int longestSpan();
	
	class SpanFullException: public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class SpanEmptyException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif