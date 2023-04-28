#include "Zombie.hpp"

int main() {

    Zombie* zombie = newZombie("Bob");
    zombie->announce();
    randomChump("Bobby");
    
    delete zombie;
}