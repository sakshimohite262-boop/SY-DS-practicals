#include <iostream>
using namespace std;

struct Student {
    int rollNumber;
    char name[50];
    char branch[50];
    float marks;
};

void inputRecords(Student* sPtr, int total) {
    for (int i = 0; i < total; i++) {
        
        Student* current = sPtr + i;

        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Enter Roll Number: ";
        cin >> current->rollNumber;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(current->name, 50);

        cout << "Enter Branch: ";
        cin.getline(current->branch, 50);

        cout << "Enter Marks: ";
        cin >> current->marks;
    }
}


void displayRecords(const Student* sPtr, int total) {
    cout << "\n-------------------------------------------------------------\n";
    cout << "Roll No\t\tName\t\tBranch\t\tMarks\n";
    cout << "-------------------------------------------------------------\n";
    
    for (int i = 0; i < total; i++) {
        const Student* current = sPtr + i;
      
        cout << current->rollNumber << "\t\t"
             << current->name << "\t\t"
             << current->branch << "\t\t"
             << current->marks << "\n";
    }
    cout << "-------------------------------------------------------------\n";
}

int main() {
    int totalStudents;
    cout << "Enter the number of students: ";
    cin >> totalStudents;

    Student studentArray[totalStudents];

    inputRecords(studentArray, totalStudents);
    displayRecords(studentArray, totalStudents);

    return 0;
}

