#include <iostream>
#include "includes/PmergeMe.hpp"

int main(int ac, char **av){

    PmergeMe vectorSort;

    if (vectorSort.commandLineError(ac, av[1])) {

        vectorSort.vMakePairs(av[1]);
        std::cout << "Success" << std::endl;
    } else
        std::cout << "Error" << std::endl;
    



}