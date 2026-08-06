#include <iostream>
#include <string>

using namespace std;

struct EmployeeNode {
    int id;
    string code;
    string name;
    double salary;
    EmployeeNode* next;

    
    EmployeeNode(int empId, string empCode, string empName, double empSalary) {
        id = empId;
        code = empCode;
        name = empName;
        salary = empSalary;
        next = nullptr;
    }
};

class EmployeeManagement {
private:
    EmployeeNode* head;

public:
    EmployeeManagement() {
        head = nullptr;
    }

    
    void insertEmployee(int id, string code, string name, double salary) {
        
        if (searchEmployeeById(id) != nullptr) {
            cout << "\n[Error] Employee with ID " << id << " already exists!\n";
            return;
        }
        
        EmployeeNode* newNode = new EmployeeNode(id, code, name, salary);
        newNode->next = head;
        head = newNode;
        cout << "\n[Success] Employee record inserted successfully.\n";
    }

    
    EmployeeNode* searchEmployeeById(int id) {
        EmployeeNode* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr; 
    }

    
    void deleteEmployee(int id) {
        EmployeeNode* current = head;
        EmployeeNode* prev = nullptr;

        
        if (current != nullptr && current->id == id) {
            head = current->next;
            delete current;
            cout << "\n[Success] Employee with ID " << id << " deleted.\n";
            return;
        }

    
        while (current != nullptr && current->id != id) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "\n[Error] Employee with ID " << id << " not found.\n";
            return;
        }

      
        prev->next = current->next;
        delete current;
        cout << "\n[Success] Employee with ID " << id << " deleted.\n";
    }

    
    void displayEmployees() {
        if (head == nullptr) {
            cout << "\nNo employee records found.\n";
            return;
        }

        EmployeeNode* current = head;
        cout << "\n---------------- EMPLOYEE RECORDS ----------------\n";
        while (current != nullptr) {
            cout << "ID: " << current->id 
                 << " | Code: " << current->code 
                 << " | Name: " << current->name 
                 << " | Salary: $" << current->salary << "\n";
            current = current->next;
        }
        cout << "--------------------------------------------------\n";
    }
};

// 3. User Menu Interface
int main() {
    EmployeeManagement system;
    int choice, id;
    string code, name;
    double salary;

    do {
        cout << "\n=== Employee Management System ===";
        cout << "\n1. Insert Employee";
        cout << "\n2. Delete Employee";
        cout << "\n3. Search Employee by ID";
        cout << "\n4. Display All Employees";
        cout << "\n5. Exit";
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID (integer): ";
                cin >> id;
                cout << "Enter Employee Code (string): ";
                cin >> code;
                cin.ignore(); // Clear remaining newline character
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Salary: ";
                cin >> salary;
                system.insertEmployee(id, code, name, salary);
                break;

            case 2:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                system.deleteEmployee(id);
                break;

            case 3:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                {
                    EmployeeNode* emp = system.searchEmployeeById(id);
                    if (emp != nullptr) {
                        cout << "\n--- Record Found ---";
                        cout << "\nID: " << emp->id;
                        cout << "\nCode: " << emp->code;
                        cout << "\nName: " << emp->name;
                        cout << "\nSalary: $" << emp->salary << "\n";
                    } else {
                        cout << "\n[Error] Employee not found.\n";
                    }
                }
                break;

            case 4:
                system.displayEmployees();
                break;

            case 5:
                cout << "\nExiting Program. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please choose between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
