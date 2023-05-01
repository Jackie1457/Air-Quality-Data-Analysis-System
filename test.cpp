#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include "AirQuality.h"
#include "AirQuality.cpp"
#include "Date.h"
#include "Date.cpp"
#include "Time.h"
#include "Time.cpp"

using namespace std;

// Test Time, Date, AirQuality class
int main(){
    // Test Time class
    cout << "Test Time class:" << endl;
    Time testTime1;
    Time testTime2;
    Time testTime3;
    testTime3.printTime(); // test constructor
    cout << endl;
    testTime1.SetTime(10, 10);
    testTime2.SetHour(10);
    testTime2.SetMin(10);
    if(testTime1.GetHour() == testTime2.GetHour())
        cout << "Time class SetTime, SetHour and GetHour methods are True!" << endl;
    if(testTime1.GetMin() == testTime2.GetMin())
        cout << "Time class SetTime, SetMin and GetMin methods are True!" << endl;
    testTime1.printTime();
    testTime2.printTime();
    cout << endl;
    cout << endl;

    // Test Date class
    cout << "Test Date class:" << endl;
    Date testDate1;
    Date testDate2;
    Date testDate3;
    testDate3.printDate();// test date constructor
    cout << endl;
    testDate1.SetDate(10, 10, 2004);
    testDate2.SetDay(10);
    testDate2.SetMonth(10);
    testDate2.SetYear(2004);
    if(testDate1.GetDay() == testDate2.GetDay())
        cout << "Date class SetDay, SetDate and GetDay methods are True!" << endl;
    if(testDate1.GetMonth() == testDate2.GetMonth())
        cout << "Date class SetMonth, SetDate and GetMonth methods are True!" << endl;
    if(testDate1.GetYear() == testDate2.GetYear())
        cout << "Date class SetYear, SetDate and GetYear methods are True!" << endl;
    testDate1.printDate();
    testDate2.printDate();
    cout << endl;
    cout << endl;

    cout << "Test AirQuality class:" << endl;
    AirQuality testAQ1;
    AirQuality testAQ2;
    AirQuality testAQ3;
    testAQ3.printAirQuality();
    cout << endl;
    testAQ1.SetDate(10, 10, 2004);
    testAQ2.SetDate(10, 10, 2004);
    testAQ1.SetTime(20, 20);
    testAQ2.SetTime(20, 20);
    testAQ1.SetTemp(18.8);
    testAQ2.SetTemp(18.8);
    testAQ1.SetAbsoluteHumidity(5.5);
    testAQ2.SetAbsoluteHumidity(5.5);
    testAQ1.SetRelativeHumidity(10.1);
    testAQ2.SetRelativeHumidity(10.1);
    if(testAQ1.GetDate().GetDay() == testAQ2.GetDate().GetDay())
        cout << "AirQuality class SetDate, GetDate GetDay methods are True!" << endl;
    if(testAQ1.GetDate().GetMonth() == testAQ2.GetDate().GetMonth())
        cout << "AirQuality class SetDate, GetDate GetMonth methods are True!" << endl;
    if(testAQ1.GetDate().GetYear() == testAQ2.GetDate().GetYear())
        cout << "AirQuality class SetDate, GetDate GetYear methods are True!" << endl;
    if(testAQ1.GetTime().GetHour() == testAQ2.GetTime().GetHour())
        cout << "AirQuality class SetTime, GetTime GetHour methods are True!" << endl;
    if(testAQ1.GetTime().GetMin() == testAQ2.GetTime().GetMin())
        cout << "AirQuality class SetTime, GetTime GetMin methods are True!" << endl;
    if(testAQ1.GetTemp() == testAQ2.GetTemp())
        cout << "AirQuality class SetTemp, GetTemp methods are True!" << endl;
    if(testAQ1.GetAbsoluteHumidity() == testAQ2.GetAbsoluteHumidity())
        cout << "AirQuality class SetAbsoluteHumidity, GetAbsoluteHumidity methods are True!" << endl;
    if(testAQ1.GetRelativeHumidity() == testAQ2.GetRelativeHumidity())
        cout << "AirQuality class SetRelativeHumidity, GetRelativeHumidity methods are True!" << endl;
    cout << endl;
    cout << endl;

    return 0;
}