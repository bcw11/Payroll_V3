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

    payFile2Clocked(users);

    for(int i = 0; i < users.size(); i++){
        users[i].clockedPrint();
        cout<<endl<<endl;
    }






    
}