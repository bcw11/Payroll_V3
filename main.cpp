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
    // Date date1;
    // Date date2;
    // string input;
    // input = getStartEndDate(date1,date2);
    // rangeIsValid(date1,date2);

    //initializing users
    vector<User> users;
    usersInit(users);

    payFile2Clocked(users);

    for(int i = 0; i < 4; i++){
        users[i].clockedPrint();
        cout<<endl<<endl;
    }






    
}