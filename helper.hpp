#ifndef HELPER
#define HELPER

#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include "user.hpp"
using namespace std;
//extern Date g_startDate, g_endDate;

//initializing users 
void usersInit(vector<User>& users);

//gets all datetimes from payroll file and puts into user's clocked vector
void payFile2Clocked(vector<User>& users);

//gets start date and end date from user for date range and returns payrollName
string getStartEndDate(Date& start, Date& end);

//checks the vadility of start and end dates
void rangeIsValid(Date& start, Date& end);

//prints users vector
void printUsersClocked(vector<User>& users);

//prints out users vector
void printUsers(vector<User>& users);




#endif 