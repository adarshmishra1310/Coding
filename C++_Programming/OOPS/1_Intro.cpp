#include <bits/stdc++.h>
using namespace std;

// A class(a data type) -> extension of structure(in C)
// Structures has limitation -> members are public and No methods
// Classes -> few members can be made as private and few as public 
class Employee
{
private:
    // If something is made or declared here then only functions in this class can access these
    int date, month, year; // DOB of Employee

public:
    int married, kids;

    void setData(int date, int month, int year); // Declaration
    void getData()
    {
        cout << "The value of date is " << date << '\n';
        cout << "The value of month is " << month << '\n';
        cout << "The value of year is " << year << '\n';
        cout << "The value of married is " << married << '\n';
        cout << "The value of kids is " << kids << '\n';
    }
}Jane; // we can declare variables here too

// :: -> Scope resolution operator
void Employee :: setData(int x, int y, int z)
{
    date = x;
    month = y;
    year = z;
}

int main()
{
    Employee John;
    // We can't directly access date, month, year 
    // John.date = 24;  Not Allowed as date(along with month and year) is private
    // Hence we have to access private variables with the help of functions
    John.setData(24, 10, 1998);
    John.married = true;
    John.kids = 3;
    John.getData();
    return 0;
}