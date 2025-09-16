#pragma once
#include "Time.h"
#include <iostream>
using namespace std;
class Bus
{
    Time start;
    Time end;
    int routeMinutes;  
    int restMinutes;   

public:
    Bus(Time s, Time e, int route, int rest);

    void printSchedule(); 
};

