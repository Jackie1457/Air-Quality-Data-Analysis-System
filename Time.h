#ifndef Time_h
#define Time_h

#include <iostream>
#include <string>

using namespace std;

class Time{
public:
	Time();
	Time(int hh, int mm);
	virtual ~Time();

	void SetHour(int hh);
	void SetMin(int mm);
	void SetTime(int hh, int mm);
	void printTime();

	int GetHour() const;
	int GetMin() const;

private:
	int hour;
	int min;
};
	ostream & operator <<( ostream & os, const Time & T );
	istream & operator >>( istream & input, Time & T );

#endif