#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include "helper.hpp"
#include "user.hpp"
using namespace std;
Date g_startDate, g_endDate;


// int main(){
    // Date date(2020,12,18);
    // for(int i = 1; i < 13;i++){
    //     for(int j = 1; j < 32; j++){
    //         date.setDay(j);
    //         date.setMonth(i);
    //         if(date.isHoliday()){
    //             cout<<date<<endl;
    //         }
    //     }
    // }
// }


int main(){
    //all float outputs are now 2 digits after the decimal
    cout<<fixed<<setprecision(2);

    //initializing users
    vector<User> users;
    usersInit(users);

    //puts clocked data from payroll file into users vector
    payFile2Clocked(users);

    //filling in missing times
    for(int i = 0; i < users.size(); i++){
        if(users[i].getUserNum() != 0){
            users[i].fillMissingTime();
        }
    }

    //calculating hoursWorked and hoursOvertime
    for(int i = 0; i < users.size(); i++){
        if(users[i].getUserNum() != 0){
            users[i].calWorkHours();
        }
    }

    //printing out users vector
    printUsers(users);

    // //menu
    while(true){
        string sUserInput;
        int iUserInput;

        cout<<"\n\nP A Y R O L L   M E N U\n";
        cout<<"(1) - Exit the program\n";
        cout<<"(2) - Print hours Worked\n";
        cout<<"(3) - Print user's time table\n";
        cout<<"\nInput: ";
        getline(cin,sUserInput);
        iUserInput = atoi(sUserInput.c_str());

        if(iUserInput == 1){  
            cout<<"(1) Exiting program\n\n";
            return 0;
        }
        else if(iUserInput == 2){
            cout<<"\n\n(2) U S E R S   H O U R S    W O R K E D\n\n";
            printUsers(users);
            cout<<"\n\n";
        }
        else if(iUserInput == 3){
            cout<<"\n\n(3) U S E R S   T I M E   T A B L E\n\n";
            printUsersClocked(users);
        }
        else{
            cout<<"Error: \""<<sUserInput<<"\" is an invalid input\n\n";
        }
    }
}