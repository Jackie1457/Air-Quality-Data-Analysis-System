#include<iostream>
#include<string>
#include "Time.h"

using namespace std;

Time::Time()
{
	hour=10;
	min=10;
}
Time::Time(int hh, int mm)
{
	hour=hh;
	min=mm;
}
Time::~Time()
{
	//none
}
int Time::GetHour() const
{
	return hour;
}
int Time::GetMin() const
{
	return min;
}
void Time::SetHour(int hh)
{
	hour=hh;
}
void Time::SetMin(int mm)
{
	min=mm;
}
void Time::SetTime(int hh, int mm)
{
	hour=hh;
	min=mm;
}
void Time::printTime()
{
	cout<<"Time: "<<hour<<":"<<min << '\t';
}
istream & operator >>( istream & input, Time & T )
{
	string time,sHH,sMM;
	int position, hh, mm;

	getline(input,sHH,'.');
	getline(input,sMM,'\n');

	hh=stoi(sHH);
	mm=stoi(sMM);

	T.SetHour(hh);
	T.SetMin(mm);
	return input;
}
ostream & operator <<( ostream & os, const Time & T )
{
	os<<"Time: "<<T.GetHour()<<":"<<T.GetMin();
	return os;
}
