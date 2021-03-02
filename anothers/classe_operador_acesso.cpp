// Demonstrating operators of access to class members with . and ->

#include <iostream>
using namespace std;

// Count class definition
class Count
{
private:
    int x;

public:

    void setX(int value)
    {
        x = value;
    }

    void print()
    {
        cout << x << endl;
    }

};

// main method

int main()
{
    Count counter;                  // creates counter object
    Count *counterPtr = &counter;   // creates pointer to counter
    Count &counterRef = counter;    // creates reference to counter

    cout << endl;

    cout << "Set x to 1 and print using the object's name       : ";
    counter.setX(1);
    counter.print();

    cout << "Set x to 2 and print using a reference to an object: ";
    counterRef.setX(2);
    counterRef.print();

    cout << "Set x to 3 and print using a pointer to an object  : ";
    counterPtr->setX(3);
    counterPtr->print();

    cout << endl;

    return 0;
}
