#include "helper.hpp"
using namespace std;
extern Date g_startDate, g_endDate;

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
    
    //gets start date and end date for date range and returns payrollName
    string payrollName = getStartEndDate(g_startDate,g_endDate);
    //Reading the payroll.dat file and exit if failed
    ifstream payrollFile(payrollName);
    if(!payrollFile.is_open()) {
        cout<<"\nUnable to open file \""<<payrollName<<"\""<<endl<<endl;
        exit(1);
    }

    rangeIsValid(g_startDate,g_endDate);
    //inputing data into user.clocked
    while(getline(payrollFile, line)){
        istringstream ss(line);

        getline(ss, sUserNum, '\t');
        userNum = atoi(sUserNum.c_str());

        getline(ss, sYear, '-');
        year = atoi(sYear.c_str());

        getline(ss, sMonth, '-');
        month = atoi(sMonth.c_str());

        getline(ss, sDay, ' ');
        day = atoi(sDay.c_str());

        getline(ss, sHour, ':');
        hour = atoi(sHour.c_str());

        getline(ss, sMinute, ':');
        minute = atoi(sMinute.c_str());

        Date date(year,month,day);
        Time time(hour,minute);
        
        //break out of loop if date is greater or equal to end date
        if(date > g_endDate){
            cout<<"Start date: "<<g_startDate<<" End date: "<<g_endDate<<" currDate: "<<date<<endl;
            break;
        }
        if(date >= g_startDate){
            if((0 < userNum && userNum <= 4) || (6 <= userNum && userNum <=13)){
                users[userNum].addClockedTime(userNum,date,time);
            }
        }
    }
    //closing the file
    payrollFile.close();
}


//gets start date and end date from user for date range
string getStartEndDate(Date& start, Date& end){
    string filename,sBuffer;
    int iBuffer;
    map<string,int> monthMap;
    monthMap["Jan"] = 1;
    monthMap["Feb"] = 2;
    monthMap["Mar"] = 3;
    monthMap["Apr"] = 4;
    monthMap["May"] = 5;
    monthMap["Jun"] = 6;
    monthMap["Jul"] = 7;
    monthMap["Aug"] = 8;
    monthMap["Sep"] = 9;
    monthMap["Oct"] = 10;
    monthMap["Nov"] = 11;
    monthMap["Dec"] = 12;

    //getting filename
    cout<<"File format: MMM dd - MMM dd (YYYY).dat\n";
    cout<<"Enter file name: ";
    getline(cin,filename);
    istringstream ss(filename);
    
    //putting data into start end dates
    //start month
    getline(ss,sBuffer,' ');
    start.setMonth(monthMap[sBuffer]);

    //start day
    getline(ss,sBuffer,' ');
    iBuffer = atoi(sBuffer.c_str());
    start.setDay(iBuffer);

    //end month
    getline(ss,sBuffer,' ');
    getline(ss,sBuffer,' ');
    end.setMonth(monthMap[sBuffer]);

    //end day
    getline(ss,sBuffer,' ');
    iBuffer = atoi(sBuffer.c_str());
    end.setDay(iBuffer);

    //year
    getline(ss,sBuffer,'(');
    getline(ss,sBuffer,')');
    iBuffer = atoi(sBuffer.c_str());
    start.setYear(iBuffer);
    end.setYear(iBuffer);

    return filename;
}

//checks the vadility of start and end dates
void rangeIsValid(Date& start, Date& end){
    //only cheecking dates after oct. 18 2020
    Date oct18(2020,10,18);
    if((end-start) < 0){
        cout<<"Warning(rangeIsValid): Range ("<<start<<" "<<end<<") end date is bigger than start date.\n";
    }
    else if((end-start+24) < 14*24){
        cout<<"Warning(rangeIsValid): Range ("<<start<<" "<<end<<") is less than 14 days.\n";
    }
    else if((end-start+24) > 14*24){
        cout<<"Warning(rangeIsValid): Range ("<<start<<" "<<end<<") is greater than 14 days.\n";
    }
    if(((start-oct18-1)/24)%14 != 0){
        cout<<"Warning(rangeIsValid): Start date does not start as a multiple of 2 weeks from Oct 18, 2020. ("<<start<<" "<<end<<")\n";
    }
}


//prints users clocked vector
void printUsersClocked(vector<User>& users){
    //Horizontal print
    Datetime datetime;
    Datetime zero;
    int size = users[1].getClockedSize();
    for(int i = 1; i < users.size(); i++){
        if(i != 5 && i != 10){
            //printing names horizontally 
            cout<<i<<" "<<users[i].getName()<<"\t\t";
            if(users[i].getName().size() <= 5){
                cout<<"\t";
            }
            if(i > 10 && users[i].getName().size() <= 5){
                cout<<"\b\b\b\b\b\b\b\b";
            }
            
            //determining the largest clocked size
            if(users[i].getClockedSize() > size){
                size = users[i].getClockedSize();
            }
        }
    }
    cout<<"\n\n";
    for(int i = 0; i < size; i++){
        for(int j = 1; j < users.size(); j++){
            if(j != 5 && j != 10){
                datetime = users[j].getDatetime(i);
                if(datetime > zero){
                    cout<<datetime<<"\t";
                }
                else{
                    cout<<"|\t\t\t";
                }
            }
        }
        cout<<"\n";
    }
    //printing total hours worked
    for(int i = 1; i < users.size(); i++){
        if(i != 5 && i != 10){
            cout<<users[i].getHoursWorked() + users[i].getHoursStatutory() + users[i].getHourOvertime()<<" Hrs\t\t";
        }
    }
    cout<<"\n";
    // Vertical Print
    // for(int i = 0; i < users.size(); i++){
    //     if(users[i].getUserNum() != 0){
    //         users[i].clockedPrint();
    //         cout<<endl<<endl;
    //     }
    // }
}


//printis out users vector
void printUsers(vector<User>& users){
    cout<<"\n\t\tHours Worked\t\tVacationPay\tStat Hours\n";
    for(int i = 0; i < users.size(); i++){
        if(users[i].getUserNum() != 0){
            cout<<users[i]<<endl;
        }
    } 
}



//saves user data to file
void save2File(vector<User>& users){
    ofstream oFile;
    oFile.open(g_startDate+"-"+g_endDate+".txt");

}
