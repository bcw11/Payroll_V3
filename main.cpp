#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cmath>
#include "date.hpp"
using namespace std;

int main(){
    Date test(1900,1,1);
    test.stringPrint();
    cout<<"\n"<<test<<endl;
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