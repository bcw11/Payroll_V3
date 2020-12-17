#include "time.hpp"
#include <cmath>
#include <stdlib.h>
using namespace std;
    
    
//constructors
Time::Time(int hour, int minute){
    this->hour = hour;
    this->minute = minute;
    setHour(hour);
    setMinute(minute);
}
Time::Time():hour(0),minute(0){}

//get set functions
int Time::getHour(){
    return hour;
}
int Time::getMinute(){
    return minute;
}
void Time::setHour(int hour){
    if(hourIsValid(hour)){
        this->hour = hour;
    }
}
void Time::setMinute(int minute){
    if(minuteIsValid(minute)){
        this->minute = minute;
    }
}

//isValid functions
bool Time::hourIsValid(int hour){
    if(hour < 1){
        cout<<"Error(Time::hourIsValid): Hour ("<<hour<<") cannot be less than 1. Time("<<*this<<")\n";
        //exit(1);
        return false;
    }
    if(hour > 24){
        cout<<"Error(Time::hourIsValid): Hour ("<<hour<<") cannot be greator than 24. Time("<<*this<<")\n";
        //exit(1);
        return false;
    }
    return true;
}
bool Time::minuteIsValid(int minute){
    if(minute < 0){
        cout<<"Error(Time::minuteIsValid): Minute ("<<minute<<") cannot be less than 0. Time("<<*this<<")\n";
        //exit(1);
        return false;
    }
    if(minute > 59){
        cout<<"Error(Time::minuteIsValid): Minute ("<<minute<<") cannot be greator than 59. Time("<<*this<<")\n";
        //exit(1);
        return false;
    }
    return true;
}

//rounds time to the nearest 15 minute
void Time::round15(){
    minute = round((float)minute/15)*15;
    if(minute == 60){
        hour++;
        minute = 0;
        if(hour > 24){
            hour = hour - 24;
        }
    }
}

//operators
bool operator-(Time& t1, Time& t2){
    return ((float)t1 - (float)t2);
}
bool operator==(Time& t1, Time& t2){
    return ((float)t1 == (float)t2);
}
bool operator!=(Time& t1, Time& t2){
    return ((float)t1 != (float)t2);
}
bool operator<(Time& t1, Time& t2){
    return ((float)t1 < (float)t2);
}
bool operator<=(Time& t1, Time& t2){
    return ((float)t1 <= (float)t2);
}
bool operator>(Time& t1, Time& t2){
    return ((float)t1 > (float)t2);
}
bool operator>=(Time& t1, Time& t2){
    return ((float)t1 >= (float)t2);
}

//print 
ostream& operator<<(ostream& outs, Time& time){
    outs<<time.hour<<":";
    if(time.minute < 10){
        outs<<"0";
    }
    outs<<time.minute;
    return outs;
}