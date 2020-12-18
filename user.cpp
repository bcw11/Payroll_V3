#include "user.hpp"
using namespace std;



//constructors
User::User(int userNum, string name):hoursWorked(0),hoursOvertime(0),hoursStatutory(0){
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
    }
}
User::User():userNum(0),name("-No name set-"),hoursWorked(0),hoursOvertime(0),hoursStatutory(0){}


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

    for(int i = clocked.size()-1 ; i >= 0 ; i--){
        if(clocked[i] < rInput){
            clocked.insert(clocked.begin()+i+1, rInput);
            return;
        }
        else if(abs(float(rInput - clocked[i])) <= 0.25){
            cout<<"DELETED: ("<<input<<") | User:"<<userNum<<" | Time difference ("<<clocked[i]<<" - "<<input<<") ("<<(input - clocked[i])*60<<" min)\n";
            return;
        }
    }
    clocked.insert(clocked.begin(),input);
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
        if(date == currDate){
            counter++;
        }
        if(date != currDate || i == clocked.size()-1){
            if(counter%2 == 1){
                while(true){
                    //printing times that day
                    if(i == clocked.size()-1){
                        i++;
                    }
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
            counter = 1;
        }
        i++;
    }
    //error checking
    if(clocked.size()%2 == 1){
        cout<<"Error(User::fillMissingTime): Program ended with odd elements ("<<clocked.size()<<").\n";
        return;
    }
}

//calculating hoursWorked and hoursOvertime
void User::calWorkHours(){
    Date date = clocked[0].getDate();
    Date currDate;
    Time time;
    int counter = 0;
    for(int i = 0; i < clocked.size() ; i++){
        currDate = clocked[i].getDate();
        if(date == currDate){
            counter++;
        }
        if(date != currDate || i == clocked.size()-1){
            if(counter%2 == 1){

            }
            date = currDate;
            counter = 1;
        }
    }
}
//returns size of clocked vector
int User::getClockedSize(){
    return clocked.size();
}


//print functions
void User::clockedPrint(){
    cout<<userNum<<" "<<name<<endl<<endl;
    for(Datetime& i : clocked){
        cout<<i<<endl;
    }
}
ostream& operator<<(ostream& outs, User& user){
    outs<<user.userNum<<" "<<user.name;
    if(user.hoursWorked > 0){
        outs<<"\t"<<user.hoursWorked;
    }
    if(user.hoursOvertime > 0){
        outs<<" + "<<user.hoursOvertime<<"OT";
    }
    //check if stat holiday is in date range
    // if(){
    //     outs<<"\t"<<(user.hoursWorked + user.hoursOvertime)/user.clocked.size()<<"(x1.0)";
    //     if(user.hoursStatutory > 0){
    //         outs<<" + "<<user.hoursStatutory<<"(x1.5)";
    //     }
    // }
    return outs;
}
