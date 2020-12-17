#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include <iomanip>
#include <vector>
#include "user.hpp"
using namespace std;

// int main(){
//     Date test(2020,2,29);
//     cout<<test.dayIsValid(29)<<endl;



// }


int main(){
    
    vector<User> users;
    users.reserve(13);
    users.emplace_back(0,"");
    users.emplace_back(1,"HaeJung");
    users.emplace_back(2,"DingDing");
    users.emplace_back(3,"Erika");
    users.emplace_back(4,"Eliana");
    users.emplace_back(0,"");
    users.emplace_back(6,"Kezia");
    users.emplace_back(7,"Meredith");
    users.emplace_back(8,"Wing");
    users.emplace_back(9,"Zhang");
    users.emplace_back(0,"");
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

    int counter = 1;
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
        
        // cout<<counter<<" "<<userNum<<" "<<date<<" "<<time<<" Size: "<<users[userNum].getClockedSize()<<endl;
        // counter++;

        if((0 < userNum && userNum <= 4) || (6 <= userNum && userNum <=13)){
            users[userNum].addClockedTime(date,time);
        }
    }
    //closing the file
    payrollFile.close();


    for(int i = 0; i < 4; i++){
        users[i].clockedPrint();
        cout<<endl<<endl;
    }




    
}