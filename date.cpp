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


//returns an int for the day of the week. 0-Sunday, 1-Monday, 2-Tuesday...
//(alogrithm I found online; Sakomoto's method)
int Date::dayOfWeek(){
    int y = year, m = month, d = day;
    int t[12] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if(m < 3){
        y -= 1;
    }
    return (y + (y / 4) - (y / 100) +  (y / 400) + t[m - 1] + d) % 7;      
    //string w[7] = {"Sunday","Monday","Tuesday","Wednesday","Thrusday","Friday","Saturday"};
}

//checks if date is a holiday
bool Date::isHoliday(){
    vector<Date> holidays = holidayList();
    for(int i = 0; i < holidays.size(); i++){
        if(*this == holidays[i]){
            return true;
        }
    }
    return false;
}
//returns a vector of holidays that year
vector<Date> Date::holidayList(){
    vector<Date> holidays;
    holidays.reserve(10);
    int hDay;

    //New Year's
    holidays.emplace_back(year,1,1);

    //Family Day (3rd monday in feb) (x+(5-2(x-2))+14 => -x+9+14)
    Date feb(year,2,1);
    if(feb.dayOfWeek() > 1){
        hDay = -feb.dayOfWeek() + 9 + 14;
    }
    else{
        hDay = 2 - feb.dayOfWeek() + 14;
    }
    holidays.emplace_back(year,2,hDay);

    //Good Friday
    int a = year%19;
    int b = year/100;
    int c = year%100;
    int d = b/4;
    int e = b%4;
    int f = (b+8)/25;
    int g = (b-f+1)/3;
    int h = ((19*a)+b-d-g+15)%30;
    int i = c/4;
    int j = c%4;
    int k = (32+(2*e)+(2*i)-h-j)%7;
    int m = (a+(11*h)+(22*k))/451;
    int hMonth = (h+k-(7*m)+114)/31;
    int p = (h+k-(7*m)+114)%31;
    hDay = p-1;
    holidays.emplace_back(year,hMonth,hDay);

    //Victoria Day (2nd last monday in may)
    Date may(year,5,31);
    if(may.dayOfWeek() > 1){
        hDay = 31 - (may.dayOfWeek()-1) - 7;
    }
    else{
        hDay = 31 - 6*(1-may.dayOfWeek()) - 7;
    }
    holidays.emplace_back(year,5,hDay);

    //Canada Day
    holidays.emplace_back(year,7,1);

    //British Columbia Day (1st monday in aug)
    Date aug(year,8,1);
    if(aug.dayOfWeek() > 1){
        hDay = -aug.dayOfWeek() + 9;
    }
    else{
        hDay = 2 - aug.dayOfWeek();
    }
    holidays.emplace_back(year,8,hDay);

    //Labour Day (1st monday in sept)
    Date sept(year,9,1);
    if(sept.dayOfWeek() > 1){
        hDay = -sept.dayOfWeek() + 9;
    }
    else{
        hDay = 2 - sept.dayOfWeek();
    }
    holidays.emplace_back(year,9,hDay);

    //Thanksgiving (2nd monday in oct)
    Date oct(year,10,1);
    if(oct.dayOfWeek() > 1){
        hDay = -oct.dayOfWeek() + 9 + 7;
    }
    else{
        hDay = 2 - oct.dayOfWeek() + 7;
    }
    holidays.emplace_back(year,10,hDay);

    //Remembrance Day
    holidays.emplace_back(year,11,11);

    //Christmas Day
    holidays.emplace_back(year,12,25);

    return holidays;
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
    return (d1.year != d2.year || d1.month != d2.month || d1.day != d2.day);
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
    return outs;
}