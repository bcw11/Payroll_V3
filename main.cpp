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

int main(){
    //all float outputs are now 2 digits after the decimal
    cout<<fixed<<setprecision(2)<<"\n\n\n";

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
    cout<<"\n\nU S E R S   H O U R S    W O R K E D";
    printUsers(users);

    // //menu
    while(true){
        string sUserInput;
        int iUserInput;

        cout<<"\n\nP A Y R O L L   M E N U\n";
        cout<<"(1) - Print hours Worked\n";
        cout<<"(2) - Print user's time table\n";
        cout<<"(3) - Save data to file\n";
        cout<<"Press enter to exit\n";
        cout<<"\nInput: ";
        getline(cin,sUserInput);
        if(sUserInput == ""){
            cout<<"Exiting program\n\n";
            return 0;
        }
        iUserInput = atoi(sUserInput.c_str());

        if(iUserInput == 1){
            cout<<"\n\n\n\n(1) U S E R S   H O U R S    W O R K E D\n";
            printUsers(users);
            cout<<"\n\n";
        }
        else if(iUserInput == 2){
            cout<<"\n\n\n\n(2) U S E R S   T I M E   T A B L E\n";
            printUsersClocked(users);
        }
        else if(iUserInput == 3){
            cout<<"\n\n(3) D A T A   S A V E D   T O   F I L E\n";
            save2File(users);
        }
        else{
            cout<<"Error: \""<<sUserInput<<"\" is an invalid input\n\n";
        }
    }
}