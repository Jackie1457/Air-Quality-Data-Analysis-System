#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include <iostream>
#include "Date.h"
#include "Time.h"

#pragma once

class AirQuality
{
public:
    AirQuality();
    AirQuality(Date d, Time t, double tp, double ah, double rh);
    ~AirQuality();
    void SetDate(int dd, int mm, int yy);
	void SetTime(int hh, int mn);
	void SetTemp(double tp);
    void SetAbsoluteHumidity(double ah);
    void SetRelativeHumidity(double rh);
	void printAirQuality();

	Date GetDate() const;
	Time GetTime() const;
    double GetTemp() const;
    double GetAbsoluteHumidity() const;
    double GetRelativeHumidity() const;

private:
    Date date;
    Time time;
    double temp;
    double absoluteHumidity;
    double relativeHumidity;
};

    ostream & operator <<( ostream & os, const AirQuality & AQ );
	istream & operator >>( istream & input, AirQuality & AQ );

#endif