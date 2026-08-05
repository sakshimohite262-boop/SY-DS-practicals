#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, course;
    int rollNo;
    float marks;

    
    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    cin.ignore(); // Clear input buffer

    cout << "Enter Course: ";
    getline(cin, course);

    cout << "Enter Marks: ";
    cin >> marks;

    cout << "\n--- Student Information ---" << endl;
    cout << "Name       : " << name << endl;
    cout << "Roll No.   : " << rollNo << endl;
    cout << "Course     : " << course << endl;
    cout << "Marks      : " << marks << endl;

    return 0;
}
