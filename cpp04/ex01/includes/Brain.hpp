
#pragma once
#include <iostream>
#include <sstream>

class Brain {

	public:
			Brain();
			~Brain();
			Brain(const Brain& cpy);
			Brain& operator=(const Brain& rhs);
			
			std::string ideas[100];
};