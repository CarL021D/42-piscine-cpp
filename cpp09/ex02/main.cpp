#include <iostream>
#include "includes/PmergeMe.hpp"

int main(int ac, char **av) {

    PmergeMe vectorSort;

    if (!vectorSort.commandLineError(ac, av)) {

        vectorSort.vMakePairs(av[1]);
        std::cout << "Program: Success" << std::endl;
    } else
        std::cout << "Program: Error" << std::endl;
    



}