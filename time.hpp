#ifndef TIME
#define TIME

#include <iostream>
#include <string> 
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        friend class Datetime;
    public:
        //constructors
        Time(int hour, int minute);
        Time();

        //get set functions
        int getHour();
        int getMinute();
        void setHour(int hour);
        void setMinute(int minute);

        //isValid functions
        bool hourIsValid(int hour);
        bool minuteIsValid(int minute);

        //rounds time to the nearest 15 minute
        void round15();

        //operators
        friend bool operator==(Time& t1, Time& t2);
        friend bool operator!=(Time& t1, Time& t2);
        friend bool operator<(Time& t1, Time& t2);
        friend bool operator<=(Time& t1, Time& t2);
        friend bool operator>(Time& t1, Time& t2);
        friend bool operator>=(Time& t1, Time& t2);

        //print 
        friend ostream& operator<<(ostream& outs, Time& time);

        //overloaded float 
        operator float() const {return (hour + (minute/60.));} 
};

#endif