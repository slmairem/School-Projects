#include <iostream>
using namespace std;

class Monster
{
public:
    int health;
    int attack_power;
    int defense;

    Monster() {
        this->health = rand() % 150 + 100;
        this->attack_power = rand() % 40 + 10;
        this->defense = rand() % 20 + 10;
    }

    void m_attack(Monster m, Player p);
};
