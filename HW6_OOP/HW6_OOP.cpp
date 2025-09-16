#include <iostream>
#include "Time.h"
#include "Bus.h"
using namespace std;

int main() {
    cout << "Bus schedule:\n";
    Bus b(Time(6, 0, 0), Time(11, 0, 0), 30, 10); 
    b.printSchedule();

    return 0;
}