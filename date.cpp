#include "date.hpp"
#include <stdlib.h>
using namespace std;


//constructors
Date::Date(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
    setYear(year);
    setMonth(month);
    setDay(day);
}
Date::Date():year(0),month(0),day(0){}


//get set functions
int Date::getYear(){
    return year;
}
int Date::getMonth(){
    return month;
}
int Date::getDay(){
    return day;
}
void Date::setYear(int year){
    if(yearIsValid(year)){
        this->year = year;
    }
}
void Date::setMonth(int month){
    if(monthIsValid(month)){
        this->month = month;
    }
}
void Date::setDay(int day){
    if(dayIsValid(day)){
        this->day = day;
    }
}

//isValid functions
bool Date::yearIsValid(int year){
    if(year < 2019){
        cout<<"Error(yearIsValid): Year ("<<year<<") cannot be less than 2019. date("<<*this<<")\n";
        //exit(1);
        return false;
    }
    return true;
}
bool Date::monthIsValid(int month){
    if(month < 1){
        cout<<"Error(monthIsValid): Month ("<<month<<") cannot be less than 1. date("<<*this<<")\n";
        //exit(1);
        return false;
    }
    if(year > 12){
        cout<<"Error(monthIsValid): Month ("<<month<<") cannot be greator than 12. date("<<*this<<")\n";
        //exit(1);
        return false;
    }
}
bool Date::dayIsValid(int day){
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(day < 1){
        cout<<"Error(dayIsValid): Day ("<<day<<") cannot be less than 1. date("<<*this<<")\n";
        //exit(1);
        return false;
    }
    //if leap year
    if(month == 2 && isLeapYear()){
        if(day > 29){
            cout<<"Error(dayIsValid): Day ("<<day<<") cannot be greator than 29 on a leap year. date("<<*this<<")\n";
            //exit(1);
            return false;
        }
    }
    if(day > daysPerMonth[month-1]){
        cout<<"Error(dayIsValid): Day ("<<day<<") cannot be greator than ("<<daysPerMonth[month-1]<<"). date("<<*this<<")\n";
        //exit(1);
        return false;
    }
    return true;
}
bool Date::isLeapYear(){
    if((year%400 == 0) || (year%4 == 0 && year%100 != 0)){
        return true;
    }
    return false;
}
bool Date::isHoliday(){

}

//operators
bool operator==(Date& d1, Date& d2){
    return (d1.month == d2.month && d1.day == d2.day);
}
bool operator!=(Date& d1, Date& d2){
    return (d1.month != d2.month || d1.day != d2.month);
}
bool operator<(Date& d1, Date& d2){
    if(d1.month < d2.month){
        return true;
    }
    else if(d1.month == d2.month && d1.day < d2.day){
        return true;
    }
    return false;
}
bool operator<=(Date& d1, Date& d2){
    if(d1.month <= d2.month){
        return true;
    }
    else if(d1.month == d2.month && d1.day <= d2.day){
        return true;
    }
    return false;
}
bool operator>(Date& d1, Date& d2){
    if(d1.month > d2.month){
        return true;
    }
    else if(d1.month == d2.month && d1.day > d2.day){
        return true;
    }
    return false;
}
bool operator>=(Date& d1, Date& d2){
    if(d1.month >= d2.month){
        return true;
    }
    else if(d1.month == d2.month && d1.day >= d2.day){
        return true;
    }
    return false;
}

//print 
void Date::stringPrint(){
    string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
}
ostream& operator<<(ostream& outs, Date& date){

}