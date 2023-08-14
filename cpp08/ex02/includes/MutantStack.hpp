#pragma once
#include <iostream>
#include <stack>
#include <iterator>

// Custom exception class for no occurrence
class NoOccurrenceException : public std::exception {
public:
	const char* what() const throw() {
		return "Value not found in the container.";
	}
};

template <typename T>
class MutantStack : public std::stack<T> {
public:
	using typename std::stack<T>::stack;

	// Custom iterator class
	class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
		private:
				typename std::stack<T>::container_type::iterator iter;
		public:
				explicit iterator(typename std::stack<T>::container_type::iterator it) : iter(it) {}

				T& operator*() {
					return *iter;
				}

				iterator& operator++() {
					++iter;
					return *this;
				}

				iterator operator++(int) {
					iterator temp = *this;
					++iter;
					return temp;
				}

				iterator& operator--() {
					--iter;
					return *this;
				}

				iterator operator--(int) {
					iterator temp = *this;
					--iter;
					return temp;
				}

				bool operator==(const iterator& rhs) const {
					return iter == rhs.iter;
				}

				bool operator!=(const iterator& rhs) const {
					return iter != rhs.iter;
				}
	};

	iterator begin() {
		return iterator(std::stack<T>::c.begin());
	}

	iterator end() {
		return iterator(std::stack<T>::c.end());
	}
};
