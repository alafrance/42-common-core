#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 0)
        return (NULL);
    Zombie *allZombie = new Zombie[N];
    for (int i = 0; i < N; i++) {
        allZombie[i].setName(name);
    }
    return (allZombie);
}