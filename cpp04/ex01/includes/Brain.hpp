
#pragma once
#include <iostream>

class Brain {

	public:
			Brain();
			~Brain();
			Brain(const Brain& cpy);
			Brain& operator=(const Brain& rhs);
			std::string ideas[100];
};