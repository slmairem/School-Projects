#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

void Monster::m_attack(Monster m, Player p)
{
	int damage = m.attack_power - p.defense;
	if (damage < 1)
		damage = 1;
	p.health = p.health - damage;
}
