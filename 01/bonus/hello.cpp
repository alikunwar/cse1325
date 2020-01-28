#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string name;
    cout << " Please enter your name : "; 
    
    getline(cin, name);
    
    cout << "Hello, " << name <<"!" << endl;
}