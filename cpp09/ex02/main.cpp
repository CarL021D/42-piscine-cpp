#include <iostream>
#include <chrono>
#include "includes/PmergeMe.hpp"

int main(int ac, char **av) {

    PmergeMe vectorSort;

    if (!vectorSort.commandLineError(ac, av))
        vectorSort.vSort(av[1]);

}