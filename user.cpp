#include "user.hpp"
using namespace std;
extern Date g_startDate, g_endDate;


//constructors
User::User(int userNum, string name):hoursWorked(0),hoursOvertime(0),hoursStatutory(0),daysWorked(0){
    if(userNum < 0){
        cout<<"Warning(User::User): userNum ("<<userNum<<") is less than 0.\n";
    }
    if(userNum == 0){
        this->userNum = 0;
        this->name = "-No name set-";
    }
    else{
        this->userNum = userNum;
        this->name = name;
        clocked.emplace_back(9999,1,1,1,1);
    }
}
User::User():userNum(0),name("-No name set-"),hoursWorked(0),hoursOvertime(0),hoursStatutory(0),daysWorked(0){}


//get set functions
int User::getUserNum(){
    return userNum;
}
string User::getName(){
    return name;
}
float User::getHoursWorked(){
    return hoursWorked;
}
float User::getHourOvertime(){
    return hoursOvertime;
}   
float User::getHoursStatutory(){
    return hoursStatutory;
}   


//rounds time and inserts into the correct order. Doesn't insert if time difference is 0.
void User::addClockedTime(int userNum, Date& date, Time& time){
    //input as datetime
    Datetime input(date,time);

    //rounded input
    Time rTime(time);
    rTime.round15();
    Datetime rInput(date,rTime);

    for(int i = clocked.size()-2 ; i >= 0 ; i--){
        if(clocked[i] < rInput){
            clocked.insert(clocked.begin()+i+1, rInput);
            return;
        }
        else if(abs(float(rInput - clocked[i])) <= 0.25){
            cout<<"DELETED: ("<<input<<") | User:"<<userNum<<" | Time difference ("<<clocked[i]<<" - "<<input<<") ("<<(input - clocked[i])*60<<" min)\n";
            return;
        }
    }
    clocked.insert(clocked.begin(),rInput);
}

//asks user to fill in missing time
void User::fillMissingTime(){
    Date date = clocked[0].getDate();
    Date currDate;
    Time time;
    int i = 0,counter = 0,iHour,iMinute;
    string sHour,sMinute,input;
    
    while(i<clocked.size()){
        currDate = clocked[i].getDate();
        if(date.getYear() == 9999){
            break;
        }
        if(date == currDate){
            counter++;
            //cout<<"== date: "<<date<<"  currDate: "<<currDate<<"  i: "<<i<<"  counter: "<<counter<<"  end: "<<clocked.size()-1<<endl;
        }
        if(date != currDate || i == (clocked.size()-1)){
            //cout<<"!= date: "<<date<<"  currDate: "<<currDate<<"  i: "<<i<<"  counter: "<<counter<<"  end: "<<clocked.size()-1<<endl;
            if(counter%2 == 1){
                while(true){
                    cout<<"\n"<<userNum<<" "<<name<<endl;
                    
                    //printing times that day
                    for(int j = i-counter; j < i ; j++){
                        cout<<clocked[j]<<endl;
                    }

                    //getting input from user
                    cout<<"Enter the missing time(HH mm): ";
                    getline(cin,input);
                    cout<<"\n";

                    //if input is \n end while loop
                    if(input == ""){
                        if(counter%2 == 1){
                            cout<<"Warning(User::fillMissingTime): Odd amount of times ("<<counter<<") for date("<<date<<").\n";
                        }
                        break;
                    }

                    //adding time to clocked vector
                    istringstream ss(input);
                    getline(ss,sHour,' ');
                    iHour = atoi(sHour.c_str());
                    getline(ss,sMinute);
                    iMinute = atoi(sMinute.c_str());
                    time.setHour(iHour);
                    time.setMinute(iMinute);
                    addClockedTime(userNum,date,time);
                    counter++;
                    i++;
                }
            }
            date = currDate;
            counter = 0;
            i--;
        }
        i++;
    }
    //error checking
    if((clocked.size()-1)%2 == 1){
        cout<<"Error(User::fillMissingTime): Program ended with odd elements ("<<clocked.size()-1<<").\n";
    }
}

//calculating hoursWorked and hoursOvertime
void User::calWorkHours(){
    //error checking
    if((clocked.size()-1)%2 == 1){
        cout<<"Error(User::calWorkHours): Clocked vector has odd elements ("<<clocked.size()-1<<").\n";
        return;
    }
    
    Date date = clocked[0].getDate();
    Date currDate;
    float hours = 0;
    for(int i = 0; i < (clocked.size()-1) ; i++){
        currDate = clocked[i].getDate();
        if(date == currDate && i%2 == 1){
            hours = hours + (clocked[i] - clocked[i-1]);
        }
        if(date != currDate || i == clocked.size()-2){
            //if user is Wing deduct his break (30min)
            if(userNum == 8){
                hours = hours - 0.5;
            }
            //if at end of list getting correct date for stat holiday check
            if(i == clocked.size()-2){
                date = currDate;
            }
            //checking for stat holiday
            if(date.isHoliday()){
                hoursStatutory = hoursStatutory + hours;
                hours = 0;
            }
            //checking for daily overtime
            if((hours - 8) > 0){
                hoursOvertime = hoursOvertime + hours - 8;
                hours = 8;
            }
            daysWorked++;
            hoursWorked = hoursWorked + hours;
            hours = 0;
            date = currDate;
        }
    }
    //checking for weekly overtime
    if(hoursWorked > 80){
        hoursOvertime = hoursOvertime + hoursWorked - 80;
        hoursWorked = 80;
    }
}
//returns size of clocked vector
int User::getClockedSize(){
    return (clocked.size()-1);
}


//checks if holiday is in range of clocked times
bool User::holidayInRange(){
    vector<Date> holidays = g_startDate.holidayList();
    
    for(int i = 0; i < holidays.size(); i++){
        if(g_startDate <= holidays[i] && holidays[i] <= g_endDate){
            return true;
        }
    }
    
    //edge case: if date range is inbetween two years
    if(g_startDate.getYear() != g_endDate.getYear()){
        vector<Date> nextHolidays = g_endDate.holidayList();
        for(int j = 0; j < nextHolidays.size(); j++){
            if(g_startDate <= nextHolidays[j] && nextHolidays[j] <= g_endDate){
                return true;
            }
        }
    }
    return false;
}


//print functions
void User::clockedPrint(){
    cout<<userNum<<" "<<name<<endl<<endl;
    for(int i = 0; i < (clocked.size()-1); i++){
        cout<<clocked[i]<<endl;
    }
}
ostream& operator<<(ostream& outs, User& user){
    outs<<user.userNum<<" "<<user.name;
    //printing tabs for short names
    if(user.userNum < 10){
        outs<<" ";
    }
    if(user.name.size() < 5){
        outs<<"\t";
    }
    //printing hours worked + OT
    if(user.hoursWorked > 0){
        outs<<"\t"<<user.hoursWorked;
    }
    if(user.hoursOvertime > 0){
        outs<<" + "<<user.hoursOvertime<<" OT";
    }
    else{
        outs<<"\t";
    }
    if(user.hoursOvertime <= 10){
        outs<<"\t";
    }
    if(user.hoursWorked > 0){
        outs<<"\t"<<(user.hoursWorked + user.hoursOvertime + user.hoursStatutory)*0.04;
    }
    //check if stat holiday is in date range
    if(user.holidayInRange() && user.hoursWorked > 0){
        outs<<"\t\t"<<(user.hoursWorked + user.hoursOvertime + user.hoursStatutory)/user.daysWorked<<"(x1.0)";
        if(user.hoursStatutory > 0){
            outs<<" + "<<user.hoursStatutory<<"(x1.5)";
        }
    }
    return outs;
}
