#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "degree.h"
#include "student.h"
#include "roster.h"

// Function declaration - Parses data from StudentData and inputs it into the Roster class
roster inputStudentData(const string studentData[], int size);

int main() {
    cout << "Scripting and Programming: Applications/C867" << endl;
    cout << "C++" << endl;
    cout << "Cole Detrick: 011447776 " << endl << endl << endl;

    // Input Data: Array of strings, each containing student information in CSV format
    const int numStudents = 5;
    string studentData[numStudents] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Cole,Detrick,cdetri7@wgu.edu,24,7,9,11,SOFTWARE",
    };

    // Creating and populating the Roster class
    roster classRoster = inputStudentData(studentData, numStudents);

    // Performing Rubric Function Requirements
    // Print all student data
    classRoster.printAll();

    // Print invalid email addresses
    classRoster.printInvalidEmails();

    // Print average days in course for each student
    cout << "--PRINTING AVG DAYS IN COURSE FOR ALL STUDENTS--" << endl << endl;
    for (int i = 0; i < numStudents; i++) {
        if (classRoster.classRosterArray[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
    }
    cout << endl;

    // Print students by degree program (SOFTWARE)
    classRoster.printByDegreeProgram(degreeProgramEnum::SOFTWARE);

    // Remove student with ID "A3"
    classRoster.remove("A3");
    cout << endl;

    // Print all student data again
    classRoster.printAll();

    // Attempt to remove student with ID "A3" again (should show error)
    classRoster.remove("A3");

    return 0;
}

// Function Definition
roster inputStudentData(const string studentData[], int size) {
    // Create a new roster object
    roster roster;

    // Iterate over each student data string
    for (int i = 0; i < size; i++) {
        stringstream ss(studentData[i]);  // Create a stringstream object for parsing
        string token;  // Token to hold each segment of the CSV string
        string parsedData[9];  // Array to hold parsed segments
        int dataIndex = 0;

        // Parse the CSV string and split by comma
        while (getline(ss, token, ',') && dataIndex < 9) {
            parsedData[dataIndex++] = token;
        }

        // Ensure all expected data segments are present
        if (dataIndex == 9) {
            // Extract and store each piece of student data
            string studentID = parsedData[0];
            string firstName = parsedData[1];
            string lastName = parsedData[2];
            string email = parsedData[3];
            int age = stoi(parsedData[4]);
            int daysInCourse1 = stoi(parsedData[5]);
            int daysInCourse2 = stoi(parsedData[6]);
            int daysInCourse3 = stoi(parsedData[7]);

            // Determine degree program from string
            degreeProgramEnum program = degreeProgramEnum::NONE;
            if (parsedData[8] == "SECURITY") {
                program = degreeProgramEnum::SECURITY;
            }
            else if (parsedData[8] == "NETWORK") {
                program = degreeProgramEnum::NETWORK;
            }
            else if (parsedData[8] == "SOFTWARE") {
                program = degreeProgramEnum::SOFTWARE;
            }
            else {
                // Handle unknown degree program entry
                cout << "ERROR: Unknown Degree Program entry. Please review input." << endl;
                continue;
            }

            // Add the student to the roster
            roster.add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, program);
        }
    }
    return roster;  // Return the populated roster object
}