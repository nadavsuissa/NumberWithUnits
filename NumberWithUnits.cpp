#include <iostream>            // INPUT/OUTPUT
#include <fstream>             // Read Text
#include <map>                 // For Map that shall Represent Unit Table
#include "NumberWithUnits.hpp" // Obvious Include
using namespace std;
namespace ariel
{    
    NumberWithUnits helpObj(0, "notrelivantnow"); // Created for Function -- ( Have Something to return according to Func return Type..)
    std::map<string, std::map<string, double>> unitTable;
    void NumberWithUnits::read_units(ifstream &textunit)
    {
    }

    NumberWithUnits &operator+(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return helpObj;
    }
    NumberWithUnits &operator+(const NumberWithUnits &a)
    {
        return helpObj;
    }
    NumberWithUnits &operator-(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return helpObj;
    }
    // Needed func for 1 Argument - As shown by Erel Example in Readme -6==-6KM....
    // Many more like these in the Class.....(Shown above and below)
    NumberWithUnits &operator-(const NumberWithUnits &a)
    {
        return helpObj;
    }
    NumberWithUnits &operator+=(NumberWithUnits &a, const NumberWithUnits &b)
    {
        return helpObj;
    }
    NumberWithUnits &operator-=(NumberWithUnits &a, const NumberWithUnits &b)
    {
        return helpObj;
    }

    //From here until line 67 must return boolean because this is a Comparison operator
    bool operator>(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }
    bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }

    bool operator<(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }

    bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }

    bool operator==(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }
    bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }
    NumberWithUnits &operator*=(NumberWithUnits &b, double a)
    {
        return helpObj;
    }
    NumberWithUnits &operator*=(double a, NumberWithUnits &b)
    {
        return helpObj;
    }
    NumberWithUnits &operator*(NumberWithUnits &b, double a)
    {
        return helpObj;
    }

    NumberWithUnits &operator*(double a, NumberWithUnits &b)
    {
        return helpObj;
    }

    NumberWithUnits &operator++(NumberWithUnits &a)
    {
        return helpObj;
    }
    NumberWithUnits &operator++(NumberWithUnits &a, int)
    {
        return helpObj;
    }
    NumberWithUnits &operator--(NumberWithUnits &a)
    {
        return helpObj;
    }

    NumberWithUnits &operator--(NumberWithUnits &a, int)
    {
        return helpObj;
    }

    int comp(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return INT8_MAX; // Will change later, Just for return Int...
    }
    //Input/Output    
    std::istream &operator>>(std::istream &in, NumberWithUnits &c)
    {
        return in;
    }
    std::ostream &operator<<(std::ostream &out, const NumberWithUnits &c)
    {
        return out;
    }


}
