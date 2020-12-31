#ifndef DATETIME
#define DATETIME

#include <iostream>
#include <fstream>
#include <string>
#include "date.hpp"
#include "time.hpp"
using namespace std;

class Datetime{
    private:
        Date date;
        Time time;
    public:
        //constructors
        Datetime(Date& date, Time& time);
        Datetime(int year, int month, int day, int hour, int minute);
        Datetime();

        //get set functions
        Date getDate();
        Time getTime();

        //operators
        friend float operator-(Datetime& d1, Datetime& d2);
        friend bool operator==(Datetime& d1, Datetime& d2);
        friend bool operator!=(Datetime& d1, Datetime& d2);
        friend bool operator<(Datetime& d1, Datetime& d2);
        friend bool operator<=(Datetime& d1, Datetime& d2);
        friend bool operator>(Datetime& d1, Datetime& d2);
        friend bool operator>=(Datetime& d1, Datetime& d2);

        //print functions
        void stringPrint();
        friend ostream& operator<<(ostream& outs, Datetime& datetime);

};

#endif