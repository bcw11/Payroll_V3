#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include <iomanip>
#include <vector>
#include "user.hpp"
using namespace std;

int main(){
    
    vector<User> users;
    users.reserve(13);
    users.emplace_back(0,"");
    users.emplace_back(1,"HaeJung");
    users.emplace_back(2,"DingDing");
    users.emplace_back(3,"Erika");
    users.emplace_back(4,"Eliana");
    users.emplace_back(5,"");
    users.emplace_back(6,"Kezia");
    users.emplace_back(7,"Meredith");
    users.emplace_back(8,"Wing");
    users.emplace_back(9,"Zhang");
    users.emplace_back(10,"");
    users.emplace_back(11,"Irena");
    users.emplace_back(12,"Annalie");
    users.emplace_back(13,"John");

    //Reading the payroll.dat file and exit if failed
    string sUserNum, sYear, sMonth, sDay, sHour, sMinute, line;
    int userNum, year, month, day, hour, minute;

    ifstream payrollFile("Oct 5 - Oct 18.dat");
    if(!payrollFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    //inputing data into user.clocked
    while(getline(payrollFile, line)){
        istringstream ss(line);

        getline(ss, sUserNum, '\t');
        userNum = atof(sUserNum.c_str());

        getline(ss, sYear, '-');
        year = atof(sYear.c_str());

        getline(ss, sMonth, '-');
        month = atof(sMonth.c_str());

        getline(ss, sDay, ' ');
        day = atof(sDay.c_str());

        getline(ss, sHour, ':');
        hour = atof(sHour.c_str());

        getline(ss, sMinute, ':');
        minute = atof(sMinute.c_str());

        Date date(year,month,day);
        Time time(hour,minute);
        
        users[userNum].addClockedTime(date,time);
    }
    //closing the file
    payrollFile.close();


    //users[1].clockedPrint();
    // for(int i = 0; i < users.size(); i++){
    //     users[i].clockedPrint();
    // }

}