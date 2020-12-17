#include "user.hpp"
using namespace std;

//constructors
User::User(int userNum, string name){
    if(userNum < 0){
        cout<<"Warning(User::User): userNum ("<<userNum<<") is less than 0.\n";
    }
    this->userNum = userNum;
    this->name = name;
}
User::User():userNum(-1),name("-No name set-"){}

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
void User::addClockedTime(Date& date, Time& time){
    time.round15();
    Datetime input(date,time);

    for(int i = clocked.size()-1 ; i >= 0 ; i--){
        if(clocked[i] < input){
            clocked.insert(clocked.begin()+i+1, input);
            return;
        }
        else if(clocked[i] == input){
            return;
        }
    }
    clocked.insert(clocked.begin(),input);
}

//print functions
void User::clockedPrint(){
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