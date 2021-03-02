/*******************************
 * Instantiating the class
 * 
 * UNIVESP University
 * Computer Engineering
 * Data structures discipline
 * 
 * Compile: g++ time_main.cpp time.cpp -o time
 */

#include <iostream>
#include "time.h"

using namespace std;

int main() {

    Time t1(23, 59, 59);
    t1.print();             // 23:59:59
    t1.setHour(12);         // 23
    t1.setMinute(30);       // 59
    t1.setSecond(15);       // 59

    t1.print();
    cout << "Hour  : " << t1.getHour() << endl;     // Hour  : 23
    cout << "Minute: " << t1.getMinute() << endl;   // Minute: 59
    cout << "Second: " << t1.getSecond() << endl;   // Second: 59

    Time t2(12);
    t2.print();             // 12:00:00

    Time t3(23, 59, 58);
    t3.print();             // 23:59:58

    t3.nextSecond();
    t3.print();             // 23:59:59

    t3.nextSecond();
    t3.print();             // 00:00:00

}
