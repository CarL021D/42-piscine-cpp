#pragma once
#include <iostream>
#include <stack>
#include <iterator>

class NoOccurrenceException : public std::exception {
public:
	const char* what() const throw() {
		return "Value not found in the container.";
	}
};

template <typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T, U> {

	public:
			typedef typename std::stack<T, U>::container_type::iterator iter;
			typedef typename std::stack<T, U>::container_type::const_iterator const_iter;

			iter begin() { return this->c.begin(); }
			iter end() { return this->c.end(); }
			const_iter begin() const { return this->c.begin(); }
			const_iter end() const { return this->c.end(); }
};
