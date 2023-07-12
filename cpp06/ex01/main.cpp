#include <iostream>
#include "includes/Serializer.hpp"

int main() {
	Data*	dataPtr;
	Data	data;

	data.nbr = 3; 
	dataPtr = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << dataPtr->nbr << std::endl;
}