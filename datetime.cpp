#include <iostream>
#include <string>
#include "datetime.hpp"
using namespace std;

//constructors
Datetime::Datetime(Date& date, Time& time){
    this->date = date;
    this->time = time;
}
Datetime::Datetime(int year, int month, int day, int hour, int minute){
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);
    time.setHour(hour);
    time.setMinute(minute);
}
Datetime::Datetime(){}

//get set functions
Date Datetime::getDate(){
    return date;
}
Time Datetime::getTime(){
    return time;
}

//operators
float operator-(Datetime& d1, Datetime& d2){
    return ((d1.date - d2.date) + (d1.time - d2.time));
}
bool operator==(Datetime& d1, Datetime& d2){
    return (d1.date == d2.date && d1.time == d2.time);
}
bool operator!=(Datetime& d1, Datetime& d2){
    return (d1.date != d2.date || d1.time != d2.time);
}
bool operator<(Datetime& d1, Datetime& d2){
    if(d1.date < d2.date){
        return true;
    }
    else if (d1.date == d2.date && d1.time < d2.time){
        return true;
    }
    return false;
}
bool operator<=(Datetime& d1, Datetime& d2){
    return ((d1 == d2) || (d1 < d2));
}
bool operator>(Datetime& d1, Datetime& d2){
    if(d1.date > d2.date){
        return true;
    }
    else if (d1.date == d2.date && d1.time > d2.time){
        return true;
    }
    return false;
}
bool operator>=(Datetime& d1, Datetime& d2){
    return ((d1 == d2) || (d1 > d2));
}

//print functions
void Datetime::stringPrint(){
    date.stringPrint();
    cout<<" "<<time;
}
ostream& operator<<(ostream& outs, Datetime& datetime){
    outs<<datetime.date<<" "<<datetime.time;
    return outs;
}