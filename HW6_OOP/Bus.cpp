#include "Bus.h"

Bus::Bus(Time s, Time e, int route, int rest)
    : start(s), end(e), routeMinutes(route), restMinutes(rest) {
}

// --- Вивід розкладу ---
void Bus::printSchedule() {
    Time current = start;
    int safety = 0;
    while (current < end && safety < 1000) {
        Time arrival = current + routeMinutes;
        if (arrival > end) break; 
        cout << current << " " << arrival << endl;
        current = arrival + restMinutes;
        safety++;
    }
}
