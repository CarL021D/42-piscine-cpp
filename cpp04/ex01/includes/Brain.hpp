
#pragma once
#include <iostream>
#include <sstream>

class Brain {

	public:
			Brain();
			~Brain();
			Brain(const Brain& cpy);
			Brain& operator=(const Brain& rhs);
			
			// void	setNewIdea(short i, std::string new_idea);

			std::string ideas[100];
};