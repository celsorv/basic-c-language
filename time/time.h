/*******************************
 * Class for time representation
 * 
 * UNIVESP University
 * Computer Engineering
 * Data structures discipline
 * 
 */

#ifndef TIME_H      // Include this block only if TIME_H is not defined
#define TIME_H

class Time {

private:
    int hour;       // 0 - 23
    int minute;     // 0 - 59
    int second;     // 0 - 59

public:
    Time(int hour = 0, int minute = 0, int second = 0);
    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);
    int getSecond() const;
    void setSecond(int second);
    void print() const;
    void nextSecond();
};

#endif  // end of " #ifndef "
