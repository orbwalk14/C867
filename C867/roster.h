#pragma once
#include <iostream>
#include <string>
#include "student.h"

using std::string;

// Constants
const int rosterSize = 5;  // Maximum size of the roster

class roster {
public:
    // Fixed-size array of student pointers
    student* classRosterArray[rosterSize];
    int currentSize;  // Tracks current number of students in roster

    // Mutator functions
    void add(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        degreeProgramEnum degreeProgram);
    void remove(string studentID);

    // Print functions
    void printAll() const;
    void printAverageDaysInCourse(string studentID);
    void printByDegreeProgram(degreeProgramEnum degreeProgram);
    void printInvalidEmails();

    // Constructor
    roster();

    // Destructor
    ~roster();

    // Copy constructor
    roster(const roster& origRoster);

    // Gets the size of the roster
    int getCurrentSize() const { return currentSize; }
};