#pragma once
#include <iostream>
using namespace std;

class Time
{
    int hour;
    int minutes;
    int seconds;
    bool format; 

public:
    Time(); 
    Time(int hour, int minutes, int seconds, bool format = true);
    Time(const Time& obj);
    Time& operator=(const Time& obj);
    ~Time();

    void setHour(int hour);
    int getHour() const;
    void setMinutes(int minutes);
    int getMinutes() const;
    void setSeconds(int seconds);
    int getSeconds() const;
    void setFormat(bool format);
    bool getFormat() const;

    void tickTime();   
    void untickTime(); 
    void showTime() const;

   
    bool operator==(const Time& obj) const;
    bool operator!=(const Time& obj) const;
    bool operator>(const Time& obj) const;
    bool operator<(const Time& obj) const;
    bool operator>=(const Time& obj) const;
    bool operator<=(const Time& obj) const;

    
    Time& operator+=(float s);  
    Time& operator-=(float s);
    Time& operator+=(int m);    
    Time& operator-=(int m);
    Time& operator+=(long h);  
    Time& operator-=(long h);

    
    Time operator+(float s) const;
    Time operator-(float s) const;
    Time operator+(int m) const;
    Time operator-(int m) const;
    Time operator+(long h) const;
    Time operator-(long h) const;

    
    Time& operator++();      
    Time operator++(int);    
    Time& operator--();      
    Time operator--(int);    

   
    friend ostream& operator<<(ostream& os, const Time& t);
    friend istream& operator>>(istream& is, Time& t);
};
