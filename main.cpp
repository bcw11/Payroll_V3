#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include <iomanip>
#include "user.hpp"
using namespace std;

int main(){
    // Time t(11,12);
    // Time t2(11,13);
    // cout<<(float)t<<endl;
    // cout<<(float)t2<<endl;
    // cout<<(t-t2)*60<<endl;
    
    // Date d1(2019,12,11);
    // Date d2(2020,12,9);
    // cout<<d1-d2<<endl;
    //setting precision of floats
    cout<<fixed<<setprecision(2);

    
    User Bryan(1,"Bryan");
    Date date(2020,12,16);
    Time time(4,11);
    Date date1(2020,12,16);
    Time time1(4,18);
    Date date2(2020,12,15);
    Time time2(6,23);

    Datetime datetime1(date,time);
    Datetime datetime2(date1,time1);

    Bryan.addClockedTime(date,time);
    Bryan.addClockedTime(date2,time2);
    Bryan.addClockedTime(date1,time1);
    
    
    Bryan.clockedPrint();
}



// int main(){
//   //Reading the payroll.dat file and exit if failed
//   ifstream domesticFile("domestic-stu.txt");
//   if(!domesticFile.is_open()) {
//     cout << "Unable to open file domestic-stu.txt" << endl;
//     return -1;
//   }
//   getline(domesticFile, line);
//   cout << "File format: " << line << endl;

//   //inputing data into domesitcArr
//   while(getline(domesticFile, line)){

//     istringstream ss(line);

//     getline(ss, s_CGPA, ',');
//     CGPA = atof(s_CGPA.c_str());
//     domesticArr[index].setCGPA(CGPA);

//   }
//   //closing the file
//   domesticFile.close();

// }