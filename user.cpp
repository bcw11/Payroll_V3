#include "user.hpp"
using namespace std;



//constructors
User::User(int userNum, string name){
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
User::User():userNum(0),name("-No name set-"){}

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
        else if((rInput - clocked[i]) <= 0.25){
            cout<<"DELETED: ("<<input<<") | User:"<<userNum<<" | Time difference ("<<clocked[i]<<" - "<<input<<") ("<<(input - clocked[i])*60<<" min)\n";
            return;
        }

    }
    clocked.insert(clocked.begin(),input);
}
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
    outs<<user.userNum<<" "<<user.name<<"\t"<<user.hoursWorked;
    if(user.hoursOvertime > 0){
        outs<<"+ "<<user.hoursOvertime<<"OT";
    }
    //check if stat holiday is in date range
    // if(){
    //     outs<<"\t"<<(user.hoursWorked + user.hoursOvertime)/user.clocked.size()<<"(x1.0)";
    //     if(user.hoursStatutory > 0){
    //         outs<<" + "<<user.hoursStatutory<<"(x1.5)";
    //     }
    // }
}