#ifndef DATE
#define DATE

#include <iostream>
#include <string> 
#include <vector>
using namespace std;

class Date{
    private:
        int year;
        int month;
        int day;
        friend class Datetime;
    public:
        //constructors
        Date(int year, int month, int day);
        Date();

        //get set functions
        int getYear();
        int getMonth();
        int getDay();
        void setYear(int year);
        void setMonth(int month);
        void setDay(int day);

        //isValid functions
        bool yearIsValid(int year);
        bool monthIsValid(int month);
        bool dayIsValid(int day);
        bool isLeapYear();
        int dayOfWeek();
        void stringDayOfWeek();
        bool isHoliday();
        vector<Date> holidayList();

        //operators
        friend int operator-(Date& d1, Date& d2);
        friend bool operator==(Date& d1, Date& d2);
        friend bool operator!=(Date& d1, Date& d2);
        friend bool operator<(Date& d1, Date& d2);
        friend bool operator<=(Date& d1, Date& d2);
        friend bool operator>(Date& d1, Date& d2);
        friend bool operator>=(Date& d1, Date& d2);

        //print 
        void stringPrint();
        friend ostream& operator<<(ostream& outs, Date& date);

        //overloaded string 
        operator string() const {
            string months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
            return months[month-1]+" "+to_string(day);
            } 
};

#endif