#include <iostream>
#include <fstream>
//#include <iomanip>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add student information to the file
void addStudentInfo() {
    ofstream file("student_info.txt", ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter division: ";
    getline(cin, student.division);
    cout << "Enter address: ";
    getline(cin, student.address);

    file << student.rollNumber << " "
         << student.name << " "
         << student.division << " "
         << student.address << endl;

    file.close();
    cout << "Student information added successfully!" << endl;
}

// Function to delete student information from the file
void deleteStudentInfo() {
    ifstream inputFile("student_info.txt");
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream outputFile("temp.txt");
    if (!outputFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int rollNumber;
    cout << "Enter the roll number of the student to delete: ";
    cin >> rollNumber;

    Student student;
    bool found = false;
    while (inputFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber != rollNumber) {
            outputFile << student.rollNumber << " "
                       << student.name << " "
                       << student.division << " "
                       << student.address << endl;
        } else {
            found = true;
        }
    }

    inputFile.close();
    outputFile.close();

    if (found) {
        remove("student_info.txt");
        rename("temp.txt", "student_info.txt");
        cout << "Student information deleted successfully!" << endl;
    } else {
        remove("temp.txt");
        cout << "Student not found!" << endl;
    }
}

// Function to display student information from the file
void displayStudentInfo() {
    ifstream file("student_info.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    int rollNumber;
    cout << "Enter the roll number of the student to display: ";
    cin >> rollNumber;

    Student student;
    bool found = false;
    while (file >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "----- Student Information System -----" << endl;
        cout << "1. Add Student Information" << endl;
        cout << "2. Delete Student Information" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentInfo();
                break;
            case 2:
                deleteStudentInfo();
                break;
            case 3:
                displayStudentInfo();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
