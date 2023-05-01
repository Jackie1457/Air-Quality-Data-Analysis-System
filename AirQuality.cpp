#include "AirQuality.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

AirQuality::AirQuality()
{
    date=Date(1, 1, 2001);
    time=Time(10, 10);
    temp=10.0;
    absoluteHumidity = 20.0;
    relativeHumidity = 30.0;
}

AirQuality::AirQuality(Date d, Time t, double tp, double aH, double rh)
{
    date=Date(1, 1, 2001);
    time=Time(10, 10);
    temp=0.0;
    absoluteHumidity = 0.0;
    relativeHumidity = 0.0;
}

AirQuality::~AirQuality()
{
//none
}

Date AirQuality::GetDate() const
{
	return date;
}

Time AirQuality::GetTime() const
{
	return time;
}

double AirQuality::GetTemp() const
{
	return temp;
}

double AirQuality::GetAbsoluteHumidity() const
{
	return absoluteHumidity;
}

double AirQuality::GetRelativeHumidity() const
{
	return relativeHumidity;
}

void AirQuality::SetDate(int dd, int mm, int yy)
{
	date=Date(dd, mm, yy);
}

void AirQuality::SetTime(int hh, int mn)
{
	time=Time(hh, mn);
}

void AirQuality::SetTemp(double tp)
{
	temp=tp;
}

void AirQuality::SetAbsoluteHumidity(double ah)
{
	absoluteHumidity=ah;
}

void AirQuality::SetRelativeHumidity(double rh)
{
	relativeHumidity=rh;
}

void AirQuality::printAirQuality()
{
	cout<<"AirQuality: " << date.GetYear()<<"/"<< date.GetMonth()<<"/"<< date.GetDay()<<"/"<<","<<time.GetHour()<<":" << time.GetMin()<<","<<temp<<","<<absoluteHumidity<<","<<relativeHumidity;
}


ostream & operator <<( ostream & os, const AirQuality & AQ )
{
	os << "Date:  " << AQ.GetDate() << "Time: " <<AQ.GetTime() << "Temperature: " <<AQ.GetTemp()<< "Relative Humidity: "<<AQ.GetRelativeHumidity()<< "Absolute Humidity: "<<AQ.GetAbsoluteHumidity();
  return os;
}

