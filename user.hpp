#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include "datetime.hpp"
using namespace std;

class User{
    private:
        int userNum;
        string name;
        vector<Datetime> clocked;
        float hoursWorked;
        float hoursOvertime;
        float hoursStatutory;
    public:
        //constructors
        User(int userNum, string name);
        User();

        //get set functions
        int getUserNum();
        string getName();
        float getHoursWorked();
        float getHourOvertime();
        float getHoursStatutory();

        //clocked functions
        void addClockedTime(Date& date, Time& time);
        int getClockedSize();

        //print functions
        void clockedPrint();
        friend ostream& operator<<(ostream& outs, User& user);


};

#endif