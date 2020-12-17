#ifndef HELPER
#define HELPER

#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include <iomanip>
#include <vector>
#include "user.hpp"
using namespace std;


//initializing users 
void usersInit(vector<User>& users);


//gets all datetimes from payroll file and puts into user's clocked vector
void payFile2Clocked(vector<User>& users);






#endif 