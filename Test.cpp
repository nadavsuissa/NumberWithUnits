#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

// Initialize each Unit with a Random Parameter.
/* UnitTest Key: 
    CHECK_GT -- Greater Than
    CHECK_LT -- Less Than
    CHECK_GE -- Greater or Equal
    CHECK_LE -- Lesser or Equal
    CHECK_EQ -- Equals
*/

// Begin ea

TEST_CASE("Comparison Operator Check")
{
    // Create per Case Obj
    NumberWithUnits km(9, "km");       // 900 000 centimeters
    NumberWithUnits cm(1050000, "cm"); // 10.5 kilometers
    NumberWithUnits hour(6, "hour");   // 21 600 seconds
    NumberWithUnits sec(1.1, "sec");   // 0.000305555556 hours
    NumberWithUnits ton(7.1, "ton");   // 7100 kilograms
    NumberWithUnits kg(2.8, "kg");     // 0.0028 TON
    // Length
    CHECK_GT(cm, km);
    CHECK_LT(km, cm);
    // Weight Check
    CHECK_GT(ton, kg);
    CHECK_LT(kg, ton);
    // Time
    CHECK_GT(hour, sec);
    CHECK_LT(sec, hour);
    // Equals , Less or More
    CHECK_GE(km, km);
    NumberWithUnits km1(9.2, "km");
    CHECK_LE(km, km1);
    NumberWithUnits km2(4, "km");
    CHECK_EQ(km2, NumberWithUnits(4000, "m"));
}

TEST_CASE("Add on or Subtract off(+=,-=)")
{
    // Create per Case Obj
    NumberWithUnits km(11, "km");      // 1 100 000 centimeters
    NumberWithUnits cm(1050000, "cm"); // 10.5 kilometers
    NumberWithUnits hour(6, "hour");   // 21 600 seconds
    NumberWithUnits sec(1.1, "sec");   // 0.000305555556 hours
    NumberWithUnits ton(7.1, "ton");   // 7100 kilograms
    NumberWithUnits kg(2.8, "kg");     // 0.0028 TON
    km += cm;
    CHECK(km == NumberWithUnits(21.5, "km"));
    km -= cm;
    CHECK(km == NumberWithUnits(0.5, "km"));
    hour += sec;
    CHECK(hour == NumberWithUnits(6.00030556, "hour"));
    hour -= sec;
    CHECK(hour == NumberWithUnits(5.99969444, "hour"));
    ton += kg;
    CHECK(ton == NumberWithUnits(7.1028, "ton"));
    ton -= kg;
    CHECK(km == NumberWithUnits(7.0972, "km"));
}

TEST_CASE("Exception(Non Valid Action) Check")
{
    NumberWithUnits km(11, "km");      // 1 100 000 centimeters
    NumberWithUnits cm(1050000, "cm"); // 10.5 kilometers
    NumberWithUnits hour(6, "hour");   // 21 600 seconds
    NumberWithUnits sec(1.1, "sec");   // 0.000305555556 hours
    NumberWithUnits ton(7.1, "ton");   // 7100 kilograms
    NumberWithUnits kg(2.8, "kg");     // 0.0028 TON
    NumberWithUnits USD(3, "USD");
    // RAndom Exception Checks -- Obviously can't add USD and Hours(for example...)
    CHECK_THROWS(km + hour);
    CHECK_THROWS(cm -= sec);
    CHECK_THROWS(USD + ton);
    CHECK_THROWS(sec += USD);
    CHECK_THROWS(hour - kg);
    CHECK_THROWS(USD + km);
}

TEST_CASE("Basic Addition and Subtraction")
{
    NumberWithUnits km(13, "km");      // 1 300 000 centimeters
    NumberWithUnits cm(1120000, "cm"); // 11.2 kilometers
    km = km + cm;
    CHECK(km == NumberWithUnits(24.2, "km"));
    km = km - cm;
    CHECK(km == NumberWithUnits(13, "km"));

    NumberWithUnits km1(11.2, "km");    //   1 120 000 CM
    NumberWithUnits cm1(1300000, "cm"); // 13 kilometers
    cm1 = cm1 + km1;
    CHECK(cm1 == NumberWithUnits(2420000, "cm"));
    cm1 = cm1 - km1;
    CHECK(cm1 == NumberWithUnits(1300000, "cm"));

    NumberWithUnits hour(6, "hour"); // 21 600 seconds
    NumberWithUnits sec(1.1, "sec"); // 0.000305555556 hours
    hour = hour + sec;
    CHECK(hour == NumberWithUnits(6.00030556, "hour"));
    hour = hour - sec;
    CHECK(hour == NumberWithUnits(6, "hour"));

    NumberWithUnits hour1(6, "hour"); // 21 600 seconds
    NumberWithUnits sec1(1.1, "sec"); // 0.000305555556 hours
    hour1 = hour1 + sec1;
    CHECK(hour == NumberWithUnits(6.00030556, "hour"));
    hour1 = hour1 - sec;
    CHECK(hour == NumberWithUnits(5.99969444, "hour"));

    NumberWithUnits ton(7.1, "ton"); // 7100 kilograms
    NumberWithUnits kg(2.8, "kg");   // 0.0028 TON
    ton = ton + kg;
    CHECK(ton == NumberWithUnits(7.1028, "ton"));
    ton = ton - kg;
    CHECK(ton == NumberWithUnits(7, "ton"));

    // from here on
}

TEST_CASE("++,--(Add one or Subtract One)")
{
    // All Work On Same Concept, No need for Complicated Numbers
    NumberWithUnits km(1, "km");
    NumberWithUnits cm(1, "cm");
    NumberWithUnits hour(1, "hour");
    NumberWithUnits sec(1, "sec");
    NumberWithUnits ton(1, "ton");
    NumberWithUnits kg(1, "kg");
    NumberWithUnits USD(1, "USD");
    km++;
    CHECK(km == NumberWithUnits(2, "km"));
    km--;
    CHECK(km == NumberWithUnits(1, "km"));
    cm++;
    CHECK(cm == NumberWithUnits(2, "cm"));
    cm--;
    CHECK(cm == NumberWithUnits(1, "cm"));
    hour++;
    CHECK(hour == NumberWithUnits(2, "hour"));
    hour--;
    CHECK(hour == NumberWithUnits(1, "hour"));
    sec++;
    CHECK(sec == NumberWithUnits(2, "sec"));
    sec--;
    CHECK(sec == NumberWithUnits(1, "sec"));
    ton++;
    CHECK(ton == NumberWithUnits(2, "ton"));
    ton--;
    CHECK(ton == NumberWithUnits(1, "ton"));
    kg++;
    CHECK(kg == NumberWithUnits(2, "kg"));
    kg--;
    CHECK(kg == NumberWithUnits(1, "kg"));
    USD++;
    CHECK(kg == NumberWithUnits(2, "USD"));
    USD--;
    CHECK(USD == NumberWithUnits(1, "USD"));
}
TEST_CASE("*,*=")
{
    // Simple Muliplication Check With Simple Numbers(Validate that Operator Works)
    NumberWithUnits km(1, "km");
    NumberWithUnits cm(1, "cm");
    NumberWithUnits hour(1, "hour");
    NumberWithUnits sec(1, "sec");
    NumberWithUnits ton(1, "ton");
    NumberWithUnits kg(1, "kg");
    NumberWithUnits USD(1, "USD");
    km = km * 4;
    CHECK(km == NumberWithUnits(4, "km"));
    km *= 0.5;
    CHECK(km == NumberWithUnits(2, "km"));

    cm = cm * 6;
    CHECK(cm == NumberWithUnits(6, "cm"));
    cm *= 0.5;
    CHECK(cm == NumberWithUnits(3, "cm"));

    hour = hour * 8;
    CHECK(hour == NumberWithUnits(8, "hour"));
    hour *= 0.5;
    CHECK(hour == NumberWithUnits(4, "hour"));

    sec = sec * 10;
    CHECK(sec == NumberWithUnits(10, "sec"));
    sec *= 0.5;
    CHECK(sec == NumberWithUnits(5, "sec"));

    ton = ton * 12;
    CHECK(ton == NumberWithUnits(12, "ton"));
    ton *= 0.5;
    CHECK(ton == NumberWithUnits(6, "ton"));

    kg = kg * 14;
    CHECK(kg == NumberWithUnits(14, "kg"));
    kg *= 0.5;
    CHECK(kg == NumberWithUnits(7, "kg"));

    USD = USD * 16;
    CHECK(USD == NumberWithUnits(16, "USD"));
    USD *= 0.5;
    CHECK(USD == NumberWithUnits(8, "USD"));
}