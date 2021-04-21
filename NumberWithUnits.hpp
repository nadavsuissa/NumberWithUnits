#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel
{
    class NumberWithUnits
    {
    private:
        // Class variable definitions
        double quantityofUnit; // Will be double because of needed use of Decimels
        string typeofUnit;     // km,cm,ton....

    public:
        // Construct...
        NumberWithUnits(double givenQuantity, string givenType)
        {
            quantityofUnit = givenQuantity;
            typeofUnit = givenType;
        }

        static void read_units(ifstream &textunit); // Func Header - Read Units from Given File(Erel...)
        // Friend attribute is must in order to Reach Private or Protected members
        //Operator override Func Headers -- Like in Readme: Arguments shall be Digit a && Digit b
        // Input/Output Represented - c

        friend NumberWithUnits &operator-(const NumberWithUnits &a);
        friend NumberWithUnits &operator-(const NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits &operator+(const NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits &operator+(const NumberWithUnits &a);
        friend NumberWithUnits &operator+=(NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits &operator-=(NumberWithUnits &a, const NumberWithUnits &b);
        // From Here Until line 40 are Compare Operators, hence must return type Bool
        friend bool operator>(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator<(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator==(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b);
        friend int comp(const NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits &operator*=(NumberWithUnits &b, double a);
        friend NumberWithUnits &operator*=(double a, NumberWithUnits &b);
        friend NumberWithUnits &operator*(NumberWithUnits &b, double a);
        friend NumberWithUnits &operator*(double a, NumberWithUnits &b);
        friend NumberWithUnits &operator++(NumberWithUnits &a);
        friend NumberWithUnits &operator++(NumberWithUnits &a, int);
        friend NumberWithUnits &operator--(NumberWithUnits &a);
        friend NumberWithUnits &operator--(NumberWithUnits &a, int);

        //Input Output Override
        friend std::ostream &operator<<(std::ostream &output, const NumberWithUnits &c);
        friend std::istream &operator>>(std::istream &input, NumberWithUnits &c);
    };

}