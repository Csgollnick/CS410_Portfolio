#include <iostream>
#include <math.h>
#include <corecrt_math.h>
#include <corecrt_math_defines.h>

using namespace std;

int main()
{
    double radius;
    double volume;
    double height;

    cout << "Enter Radius:" << endl;
    cin >> radius; 
    cout << endl;

    height = radius;

    volume = M_PI * (radius * radius) * height;

    cout << "The volume is " << volume;

    return 0;
}
