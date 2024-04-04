#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Monster.cpp"
#include "Player.cpp"

using namespace std;

int main() {
	Player p;
	Monster m;

	cout << "Player is entering to the battle arena" << endl;
	cout << "Name: Ronald" << endl;
	cout << "Health: " << p.health << endl;
	cout << "Attack Power: " << p.attack_power << endl;
	cout << "Defense: " << p.defense << endl;

	cout << "Monster is entering to the battle arena" << endl;
	cout << "Name: Forest Troll" << endl;
	cout << "Health: " << m.health << endl;
	cout << "Attack Power: " << m.attack_power << endl;
	cout << "Defense: " << m.defense << endl;

	while (p.health != 0 && m.health != 0) {
		int turn = 1;

		cout << "Turn" << turn << "start" << endl;

		cout << "Player Ronald is attacking the monster Forest Troll" << endl;
		cout << "Player damage: " << p.attack_power << endl;
		cout << "Monster Remaining Health: " << m.health << endl;

		cout << "Monster Forest Troll is attacking the player Ronald" << endl;
		cout << "Player damage: " << m.attack_power << endl;
		cout << "Player Remaining Health: " << p.health << endl;

		turn++;
	}


	cout << "Selma Irem Ozdemir, 21070001028"
}