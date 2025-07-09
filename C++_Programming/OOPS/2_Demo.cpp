#include <bits/stdc++.h>
using namespace std;

// By default everything is private in Class
class binary
{
    string s;
    void check_binary();// Private function, it can be accessed through only public functions
    // by nesting functions

public:
    void read();
    string getString();
    string ones_compliment();
};

// Reads a binary string
void binary :: read()
{
    cout<<"Enter a binary number: ";
    cin>>s;
    check_binary(); // Nesting of member functions
}

// Checks if entered string is binary or not. If not then takes input again 
void binary :: check_binary()
{
    bool flag=0;
    for(auto &x:s) if(x!='0' && x!='1') flag=1;
    if(flag) 
    {
        cout<<"Not a binary String.\n";
        read(); // Nesting of member functions
    }
}

// Toggles every bit of s and returns it too
string binary :: ones_compliment()
{
    for(auto &x:s) 
    {
        if(x=='0') x='1';
        else x='0';
    }
    return s;
}

// s is private hence we can't just access str.s, we have to make a function for that
string binary :: getString()
{
    return s;
}

int main()
{
    binary str;
    str.read();
    cout<<str.getString()<<'\n';
    cout<<str.ones_compliment()<<'\n';
    return 0;
}