/*******************************
 * Class for time representation
 * 
 * UNIVESP University
 * Computer Engineering
 * Data structures discipline
 * 
 */

#include <iomanip>
#include <iostream>
#include "time.h"

using namespace std;

// Time::Time(int h, int m, int s) {
//     this->hour = h;
//     this->minute = m;
//     this->second = s;
// }

// Alternative syntax for constructor. A initialize list is placed after the parameters.
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {

    // Optional code executed after parameter initialization.

}

int Time::getHour() const {
    return hour;
}

void Time::setHour(int hour) {
    this->hour = hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::setMinute(int minute) {
    this->minute = minute;
}


int Time::getSecond() const {
    return second;
}

void Time::setSecond(int second) {
    this->second = second;
}

void Time::print() const {

    // setfill is set to the space character by default
    // setw defines the width of the field to be printed
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << endl;
}

void Time::nextSecond() {

    second++;

    if (second >= 60) {
        second = 0;
        minute += 1;
    }

    if (minute >= 60) {
        minute = 0;
        hour += 1;
    }

    if (hour >= 24) {
        hour = 0;
    }

}
