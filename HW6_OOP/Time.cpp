#include "Time.h"
#include <iomanip>
using namespace std;

Time::Time() : hour(0), minutes(0), seconds(0), format(true) {}

Time::Time(int h, int m, int s, bool f) {
    setHour(h);
    setMinutes(m);
    setSeconds(s);
    format = f;
}

Time::Time(const Time& obj) {
    hour = obj.hour;
    minutes = obj.minutes;
    seconds = obj.seconds;
    format = obj.format;
}

Time& Time::operator=(const Time& obj) {
    if (this != &obj) {
        hour = obj.hour;
        minutes = obj.minutes;
        seconds = obj.seconds;
        format = obj.format;
    }
    return *this;
}

Time::~Time() {}

void Time::setHour(int h) { hour = (h >= 0 && h < 24) ? h : 0; }
int Time::getHour() const { return hour; }
void Time::setMinutes(int m) { minutes = (m >= 0 && m < 60) ? m : 0; }
int Time::getMinutes() const { return minutes; }
void Time::setSeconds(int s) { seconds = (s >= 0 && s < 60) ? s : 0; }
int Time::getSeconds() const { return seconds; }
void Time::setFormat(bool f) { format = f; }
bool Time::getFormat() const { return format; }


void Time::tickTime() {
    seconds++;
    if (seconds >= 60) { seconds = 0; minutes++; }
    if (minutes >= 60) { minutes = 0; hour++; }
    if (hour >= 24) hour = 0;
}

void Time::untickTime() {
    seconds--;
    if (seconds < 0) { seconds = 59; minutes--; }
    if (minutes < 0) { minutes = 59; hour--; }
    if (hour < 0) hour = 23;
}


void Time::showTime() const {
    int h = hour;
    if (!format) { 
        h %= 12;
        if (h == 0) h = 12;
    }
    cout << setfill('0') << setw(2) << h << ":"
        << setw(2) << minutes << ":"
        << setw(2) << seconds;
    if (!format) cout << (hour < 12 ? " AM" : " PM");
    cout << endl;
}


bool Time::operator==(const Time& obj) const { return hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds; }
bool Time::operator!=(const Time& obj) const { return !(*this == obj); }
bool Time::operator<(const Time& obj) const {
    if (hour != obj.hour) return hour < obj.hour;
    if (minutes != obj.minutes) return minutes < obj.minutes;
    return seconds < obj.seconds;
}
bool Time::operator>(const Time& obj) const { return obj < *this; }
bool Time::operator>=(const Time& obj) const { return !(*this < obj); }
bool Time::operator<=(const Time& obj) const { return !(*this > obj); }


Time& Time::operator+=(float s) {
    int total = hour * 3600 + minutes * 60 + seconds + (int)s;
    total = (total + 24 * 3600) % (24 * 3600); 
    hour = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
    return *this;
}
Time& Time::operator-=(float s) {
    int total = hour * 3600 + minutes * 60 + seconds + (int)s;
    total = (total + 24 * 3600) % (24 * 3600);
    hour = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
    return *this;
}
Time& Time::operator+=(int m) {
    int total = hour * 3600 + minutes * 60 + seconds + m * 60;
    total = (total + 24 * 3600) % (24 * 3600);  
    hour = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
    return *this;
}
Time& Time::operator-=(int m) { 
    return *this += -m * 60; 
}
Time& Time::operator+=(long h) { 
    int total = hour * 3600 + minutes * 60 + seconds + h * 3600;
    total = (total + 24 * 3600) % (24 * 3600);
    hour = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;
    return *this;
}
Time& Time::operator-=(long h) {
    return *this += -h;
}


Time Time::operator+(float s) const { Time t = *this; t += s; return t; }
Time Time::operator-(float s) const { Time t = *this; t -= s; return t; }
Time Time::operator+(int m) const { Time t = *this; t += m; return t; }
Time Time::operator-(int m) const { Time t = *this; t -= m; return t; }
Time Time::operator+(long h) const { Time t = *this; t += h; return t; }
Time Time::operator-(long h) const { Time t = *this; t -= h; return t; }


Time& Time::operator++() { tickTime(); return *this; }
Time Time::operator++(int) { Time temp = *this; tickTime(); return temp; }
Time& Time::operator--() { untickTime(); return *this; }
Time Time::operator--(int) { Time temp = *this; untickTime(); return temp; }


ostream& operator<<(ostream& os, const Time& t) {
    int h = t.hour;
    if (!t.format) { h %= 12; if (h == 0) h = 12; }
    os << setfill('0') << setw(2) << h << ":"
        << setw(2) << t.minutes << ":"
        << setw(2) << t.seconds;
    if (!t.format) os << (t.hour < 12 ? " AM" : " PM");
    return os;
}

istream& operator>>(istream& is, Time& t) {
    int h, m, s;
    is >> h >> m >> s;
    t.setHour(h);
    t.setMinutes(m);
    t.setSeconds(s);
    return is;
}
