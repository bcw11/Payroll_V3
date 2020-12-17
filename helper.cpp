#include "helper.hpp"


//initializing users 
void usersInit(vector<User>& users){
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
}

//gets all datetimes from payroll file and puts into user's clocked vector
void payFile2Clocked(vector<User>& users){

    //variables
    string sUserNum, sYear, sMonth, sDay, sHour, sMinute, line;
    int userNum, year, month, day, hour, minute, counter = 1;

    //Reading the payroll.dat file and exit if failed
    string payrollName = "Oct 5 - Oct 18.dat";

    //getline()


    ifstream payrollFile(payrollName);
    if(!payrollFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        exit(1);
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
        
        // cout<<counter<<" "<<userNum<<" "<<date<<" "<<time<<" Size: "<<users[userNum].getClockedSize()<<endl;
        // counter++;

        if((0 < userNum && userNum <= 4) || (6 <= userNum && userNum <=13)){
            users[userNum].addClockedTime(date,time);
        }
    }
    //closing the file
    payrollFile.close();
}