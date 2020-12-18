#ifndef USER
#define USER

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream> //formatted string processing
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
        void addClockedTime(int useNum, Date& date, Time& time);
        void fillMissingTime();
        void calWorkHours();
        int getClockedSize();

        //checks if holiday is in range
        bool holidayInRange();

        //print functions
        void clockedPrint();
        friend ostream& operator<<(ostream& outs, User& user);
};

#endif