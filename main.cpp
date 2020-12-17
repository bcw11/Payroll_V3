#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include "user.hpp"
using namespace std;

int main(){
    User Bryan(1,"Bryan");
    Date date(2020,12,16);
    Time time(4,0);
    Date date1(2020,12,16);
    Time time1(5,0);
    Date date2(2020,12,16);
    Time time2(6,0);

    Bryan.addClockedTime(date,time);
    Bryan.addClockedTime(date1,time1);
    Bryan.addClockedTime(date2,time2);
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