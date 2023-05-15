#pragma once
#include <iostream>

class Harl {

    public:
        Harl();
        ~Harl();

        complain();

    private:
        void    _debug();
        void    _info();
        void    _warning();
        void    _error();
}