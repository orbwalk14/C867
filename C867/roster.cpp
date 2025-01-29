#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include "degree.h"
#include "student.h"
#include "roster.h"

// Import necessary standard library components
using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::setprecision;

// Adds a new student to the roster
void roster::add(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    degreeProgramEnum degreeprogram) {

    // Create an array of days to complete courses
    int addDaysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    // Find the first empty slot in the array
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] == nullptr) {
            // Create a new student object with the provided data
            classRosterArray[i] = new student(studentID, firstName, lastName, emailAddress, age, addDaysInCourse, degreeprogram);
            currentSize++;
            return;
        }
    }
}

// Removes a student from the roster by their student ID
void roster::remove(string studentID) {
    bool foundItem = false;
    cout << "--Attempting to delete student ID: " << RED << studentID << RESET << " from list--" << endl;

    // Iterate through the class roster array
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr && studentID == classRosterArray[i]->getStudentID()) {
            cout << "  Successfully Removed student " << RED << studentID << RESET << "." << endl << endl;

            // Delete the student object and set pointer to nullptr
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            currentSize--;
            foundItem = true;
            break;
        }
    }
    if (!foundItem) {
        cout << "  No students found with that ID" << endl << endl;
    }
}

// Prints the average number of days in courses for a given student
void roster::printAverageDaysInCourse(string studentID) {
    bool foundItem = false;
    float avgDaysResult = 0.0;
    cout << "The average days in course for student " << RED << studentID << RESET << " is: ";

    // Iterate through the class roster array to find the student
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr && studentID == classRosterArray[i]->getStudentID()) {
            const int* avgDays = classRosterArray[i]->getDaysToComplete();

            // Calculate the total days (assuming 3 courses)
            for (int j = 0; j < 3; j++) {
                avgDaysResult += avgDays[j];
            }

            // Print the average days
            cout << setprecision(4) << avgDaysResult / 3 << endl;
            foundItem = true;
            break;
        }
    }
    if (!foundItem) {
        cout << RED << "Error" << RESET << " - No students found with that ID" << endl << endl;
    }
}

// Prints all students in the class roster
void roster::printAll() const {
    cout << "------------PRINTING STUDENT LIST------------" << endl << endl;

    // Iterate through the class roster array and print each student
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print(printItemEnum::ALL);
        }
    }
    cout << endl;
}

// Prints all students enrolled in a specific degree program
void roster::printByDegreeProgram(degreeProgramEnum degreeProgram) {
    bool foundItem = false;
    cout << "-------PRINTING ALL STUDENTS IN " << RED << degreeProgramStrings[(int)degreeProgram] << RESET << "-------- " << endl << endl;

    // Iterate through the class roster array and print students in the specified degree program
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr && degreeProgram == classRosterArray[i]->getDegreeProgram()) {
            classRosterArray[i]->print(printItemEnum::ALL);
            foundItem = true;
        }
    }
    if (!foundItem) {
        cout << RED << "Error" << RESET << " - No students found in that program" << endl;
    }
    cout << endl;
}

// Prints invalid email addresses in the class roster
void roster::printInvalidEmails() {
    bool foundItem = false;
    cout << "------------PRINTING INVALID EMAILS------------" << endl << endl;

    // Regular expression pattern for a valid email address
    const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // Iterate through the class roster array to find invalid emails
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr && !regex_match(classRosterArray[i]->getEmailAddress(), emailPattern)) {
            cout << "Invalid Email Address found for Student ID: " << RED << classRosterArray[i]->getStudentID() << RESET;
            cout << "<--" << RED << classRosterArray[i]->getEmailAddress() << RESET << endl;
            foundItem = true;
        }
    }
    if (!foundItem) {
        cout << "No invalid email addresses found" << endl;
    }
    cout << endl;
}

// Default constructor
roster::roster() {
    for (int i = 0; i < rosterSize; i++) {
        classRosterArray[i] = nullptr;
    }
    currentSize = 0;
}

// Copy constructor
roster::roster(const roster& origRoster) {
    cout << GREEN << "Backend Info: copy constructor called" << RESET << endl << endl;

    // Deep copy of the original roster
    for (int i = 0; i < rosterSize; i++) {
        if (origRoster.classRosterArray[i] != nullptr) {
            classRosterArray[i] = new student(*origRoster.classRosterArray[i]);
        }
        else {
            classRosterArray[i] = nullptr;
        }
    }
    currentSize = origRoster.currentSize;
}

// Destructor
roster::~roster() {
    cout << GREEN << "Backend Info: roster destructor called" << RESET << endl << endl;

    // Delete each student object to free memory
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}