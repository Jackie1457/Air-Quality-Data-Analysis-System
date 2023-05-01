#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

Date::Date(){
    day=1;
    month=1;
    year=2000;
}
Date::Date(int dd, int mm, int yy){
    day=dd;
    month=mm;
    year=yy;
}
int Date::GetDay() const{
    return day;
}
void Date::SetDay(int dd){
    day=dd;
}
int Date::GetMonth() const{
    return month;
}
void Date::SetMonth(int mm){
    month=mm;
}
int Date::GetYear() const{
    return year;
}
void Date::SetYear(int yy){
    year=yy;
}
void Date::SetDate(int dd, int mm, int yy)
{
	day=dd;
	month=mm;
	year=yy;
}
void Date::printDate()
{
	cout<<"Date: " << day <<" "<< month<<" "<<year<<"   ";
}
istream & operator >>( istream & input, Date & D )
{
	string stringdd, stringmm, stringyy;
	int dd,mm, yy;

	getline(input, stringdd, '/');
	getline(input, stringmm,'/');
	getline(input, stringyy,' ');

	dd=stoi(stringdd);
	mm=stoi(stringmm);
	yy=stoi(stringyy);
	
	D.SetDate(dd, mm, yy);

	return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
	os << "Date:  " << D.GetDay() << D.GetMonth() <<D.GetYear();
  return os;
}
