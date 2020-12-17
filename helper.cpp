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
    Date startDate, endDate;
    
    //gets start date and end date for date range and returns payrollName
    string payrollName = getStartEndDate(startDate,endDate);
    
    //Reading the payroll.dat file and exit if failed
    ifstream payrollFile(payrollName);
    if(!payrollFile.is_open()) {
        cout<<"\nUnable to open file \""<<payrollName<<"\""<<endl<<endl;
        exit(1);
    }

    rangeIsValid(startDate,endDate);
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
        if(date > endDate){
            cout<<"Start date: "<<startDate<<" End date: "<<endDate<<" currDate: "<<date<<endl;
            break;
        }
        if(date >= startDate){
            if((0 < userNum && userNum <= 4) || (6 <= userNum && userNum <=13)){
                users[userNum].addClockedTime(userNum,date,time);
            }
        }
    }
    //closing the file
    payrollFile.close();
}


//gets start date and end date for date range
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
    Date oct18(2020,10,18);
    if((end-start) < 0){
        cout<<"Warning(rangeIsValid): Range ("<<start<<" "<<end<<") end date is bigger than start date.\n";
    }
    else if((end-start+24) < 14*24){
        cout<<"Warning(rangeIsValid): Range ("<<(end - start + 1)/24<<") is less than 14 days.\n";
    }
    else if((end-start+24) > 14*24){
        cout<<"Warning(rangeIsValid): Range ("<<(end - start + 1)/24<<") is greater than 14 days.\n";
    }
    if(((start-oct18-1)/24)%14 != 0){
        cout<<"Warning(rangeIsValid): Start date does not start as a multiple of 2 weeks from Oct 18, 2020. ("<<(start-oct18-1)/24<<")\n";
    }
}









