#include "date.hpp"
#include <stdlib.h>
using namespace std;


//constructors
Date::Date(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
    yearIsValid(year);
    monthIsValid(month);
    dayIsValid(day);
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
    if(month > 12){
        cout<<"Error(monthIsValid): Month ("<<month<<") cannot be greator than 12. date("<<*this<<")\n";
        //exit(1);
        return false;
    }
    return true;
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
        return true;
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
int operator-(Date& d1, Date& d2){
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days1 = d1.day, days2 = d2.day, output = 0;
    for(int i = 0; i < 12; i++){
        if(i < d1.month-1){
            days1 = days1 + daysPerMonth[i];
        }
        if(i < d2.month-1){
            days2 = days2 + daysPerMonth[i];
        }
    }
    output = days1 + (d1.year - d2.year)*365 - days2;
    if(d1.isLeapYear() && (d1.month > 2 || (d1.month == 2 && d1.day == 29))){
        output++;
    }
    if(d2.isLeapYear() && (d2.month > 2 || (d2.month == 2 && d2.day == 29))){
        output--;
    }
    return output*24;
}
bool operator==(Date& d1, Date& d2){
    return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}
bool operator!=(Date& d1, Date& d2){
    return (d1.year != d2.year || d1.month != d2.month || d1.day != d2.month);
}
bool operator<(Date& d1, Date& d2){
    if(d1.year < d2.year){
        return true;
    }
    else if(d1.year == d2.year){
        if(d1.month < d2.month){
            return true;
        }
        else if(d1.month == d2.month && d1.day < d2.day){
            return true;
        }
        return false;
    }
    return false;
}
bool operator<=(Date& d1, Date& d2){
    return ((d1 == d2) || (d1 < d2));
}
bool operator>(Date& d1, Date& d2){
    if(d1.year > d2.year){
        return true;
    }
    else if(d1.year == d2.year){
        if(d1.month > d2.month){
            return true;
        }
        else if(d1.month == d2.month && d1.day > d2.day){
            return true;
        }
        return false;
    }
    return false;
}
bool operator>=(Date& d1, Date& d2){
    return ((d1 == d2) || (d1 > d2));
}

//print 
void Date::stringPrint(){
    string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout<<months[month-1]<<" "<<day<<", "<<year;
}
ostream& operator<<(ostream& outs, Date& date){
    outs<<date.year<<"-"<<date.month<<"-"<<date.day;
}