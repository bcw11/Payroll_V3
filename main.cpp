#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include <iomanip>
#include <vector>
#include "helper.hpp"
#include "user.hpp"
using namespace std;

// int main(){
//     Date test(2020,2,29);
//     cout<<test.dayIsValid(29)<<endl;
// }


int main(){

    string month1;
    string month2;
    string day1;
    string day2;
    string input;
    int imonth1;
    int imonth2;
    int iday1;
    int iday2;

    cin>>input;
    istringstream ss(input);
    getline(ss,month1,' ');
    month1 = aotf(month1.cstr());
    getline(ss,day1,' ');
    getline(ss,month2,' ');
    getline(ss,day2,'.');
    
    
    //initializing users
    // vector<User> users;
    // usersInit(users);

    // payFile2Clocked(users);

    // for(int i = 0; i < 4; i++){
    //     users[i].clockedPrint();
    //     cout<<endl<<endl;
    // }






    
}