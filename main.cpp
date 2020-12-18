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

// int main(){
//     Date test(2020,2,29);
//     cout<<test.dayIsValid(29)<<endl;
// }


int main(){
    // Datetime datetime1(2020,12,11,20,0);
    // Datetime datetime2(2020,12,1,21,0);
    // cout<<(datetime1<datetime2)<<endl;
    // Date date1(2020,10,5);
    // Date date2(2020,10,5);
    // cout<<(date1==date2)<<endl;
    // cout<<(date1!=date2)<<endl;
    // cout<<(1!=1)<<endl;
    
    //all float outputs are now 2 digits after the decimal
    cout<<fixed<<setprecision(2);

    //initializing users
    vector<User> users;
    usersInit(users);

    //puts clocked data from payroll file into users vector
    payFile2Clocked(users);

    //
    printUsersClocked(users);

    //filling in missing times
    cout<<"\n";
    for(int i = 0; i < users.size(); i++){
        if(users[i].getUserNum() != 0){
            cout<<users[i]<<" Clocked size: "<<users[i].getClockedSize()<<endl;
            users[i].fillMissingTime();
        }
    }

    //calculating hoursWorked and hoursOvertime
    cout<<"\n";
    for(int i = 0; i < users.size(); i++){
        if(users[i].getUserNum() != 0){
            cout<<users[i]<<" Clocked size: "<<users[i].getClockedSize()<<endl;
            users[i].calWorkHours();
        }
    }

    //printing out users vector
    cout<<"\n\t\tHours Worked\t\tVacationPay\n";
    for(int i = 0; i < users.size(); i++){
        if(users[i].getUserNum() != 0){
            cout<<users[i]<<endl;
        }
    }

    

    






    
}