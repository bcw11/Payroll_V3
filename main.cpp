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
    // Date date1(2020,10,18);
    // Date date2(2020,10,17);
    // cout<<(date2>=date1)<<endl;
    // string input;
    // input = getStartEndDate(date1,date2);
    // rangeIsValid(date1,date2);

    
    //all float outputs are now 2 digits after the decimal
    cout<<fixed<<setprecision(2);

    //initializing users
    vector<User> users;
    usersInit(users);

    //puts clocked data from payroll file into users vector
    payFile2Clocked(users);

    printUsers(users);

    for(int i = 0; i < users.size(); i++){
        if(users[i].getUserNum() != 0){
            if(users[i].getClockedSize()%2 == 1){
                cout<<users[i]<<" Clocked size: "<<users[i].getClockedSize()<<endl;
            }
        }
    }

    






    
}