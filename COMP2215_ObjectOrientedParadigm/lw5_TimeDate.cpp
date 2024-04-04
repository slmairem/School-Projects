#include <iostream>
using namespace std;

int small_room_rate = 25;
int large_room_rate = 40;
double tax_rate = 0.18;


int main()
{
    int NumberOfSmallRooms, NumberOfLargeRooms;

    cout << "Number of small rooms: ";
    cin >> NumberOfSmallRooms;
    cout << "Number of large rooms: ";
    cin >> NumberOfLargeRooms;

    int cost = NumberOfSmallRooms * small_room_rate + NumberOfLargeRooms * large_room_rate;
    double tax = cost * tax_rate;
    double total_cost = cost + tax;

    cout << "Estimate House Cleaning service:" << endl;
    cout << "Number of Small Rooms:" << NumberOfSmallRooms << endl;
    cout << "Number of Large Rooms:" << NumberOfLargeRooms << endl;
    cout << "Price per small Room: $" << ::small_room_rate << endl;
    cout << "Price per large Room: $" << ::large_room_rate << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total Cost: $" << total_cost << endl;

    int small_room_rate = 20;
    int large_room_rate = 32;
    double tax_rate = 0.08;
    
    int cost2 = NumberOfSmallRooms * small_room_rate + NumberOfLargeRooms * large_room_rate;
    double tax2 = cost2 * tax_rate;
    double total_cost2 = cost2 + tax2;

    cout << "Estimate House Cleaning service:" << endl;
    cout << "Number of Small Rooms:" << NumberOfSmallRooms << endl;
    cout << "Number of Large Rooms:" << NumberOfLargeRooms << endl;
    cout << "Price per small Room discounted from $25 to $" << small_room_rate << endl;
    cout << "Price per large Room discounted from $40 to $" << large_room_rate << endl;
    cout << "Cost: $" << cost2 << endl;
    cout << "Tax: $" << tax2 << endl;
    cout << "Tax being lowered from 18% to 8%: " << tax2 << endl;
    cout << "Total Cost: $" << total_cost2 << endl;

    return 0;
}

