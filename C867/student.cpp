#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"
#include "student.h"

// Import necessary standard library components
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::left;

// Accessor function to get the student ID
string student::getStudentID() const {
    return studentID;
}

// Accessor function to get the first name
string student::getFirstName() const {
    return firstName;
}

// Accessor function to get the last name
string student::getLastName() const {
    return lastName;
}

// Accessor function to get the email address
string student::getEmailAddress() const {
    return email;
}

// Accessor function to get the age
int student::getAge() const {
    return age;
}

// Accessor function to get the degree program
degreeProgramEnum student::getDegreeProgram() const {
    return degreeProgram;
}

// Accessor function to get the days to complete courses
const int* student::getDaysToComplete() const {
    return daysToComplete;
}

// Mutator function to set the student ID
void student::setStudentID(string studentID) {
    this->studentID = studentID;
}

// Mutator function to set the first name
void student::setFirstName(string firstName) {
    this->firstName = firstName;
}

// Mutator function to set the last name
void student::setLastName(string lastName) {
    this->lastName = lastName;
}

// Mutator function to set the email address
void student::setEmailAddress(string email) {
    this->email = email;
}

// Mutator function to set the age
void student::setAge(int age) {
    this->age = age;
}

// Mutator function to set the degree program
void student::setDegreeProgram(degreeProgramEnum degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Mutator function to set the days to complete courses
void student::setDaysToComplete(const int daysToComplete[3]) {
    for (int i = 0; i < 3; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

// Constructor to initialize a student object with given attributes
student::student(
    string studentID,
    string firstName,
    string lastName,
    string email,
    int age,
    const int daysToComplete[3],
    degreeProgramEnum degreeProgram) :
    studentID(studentID),  // Initialize studentID
    firstName(firstName),  // Initialize firstName
    lastName(lastName),    // Initialize lastName
    email(email),          // Initialize email
    age(age),              // Initialize age
    degreeProgram(degreeProgram)  // Initialize degreeProgram
{
    // Initialize daysToComplete array
    for (int i = 0; i < 3; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

// Function to print student attributes based on the specified print item
void student::print(printItemEnum printItem) const {
    switch (printItem) {
    case printItemEnum::STUDENTID:  // Print student ID
        cout << "StudentID: " << studentID << endl;
        break;
    case printItemEnum::FIRSTNAME:  // Print first name
        cout << "First Name: " << firstName << endl;
        break;
    case printItemEnum::LASTNAME:  // Print last name
        cout << "Last Name: " << lastName << endl;
        break;
    case printItemEnum::EMAIL:  // Print email address
        cout << "Email: " << email << endl;
        break;
    case printItemEnum::AGE:  // Print age
        cout << "Age: " << age << endl;
        break;
    case printItemEnum::DAYSTOCOMPLETE:  // Print days to complete courses
        cout << "Days In Course: { ";
        for (int i = 0; i < 3; i++) {
            cout << daysToComplete[i];  // Print each day in course
            if (i + 1 < 3) {
                cout << ", ";  // Print comma if not last element
            }
        }
        cout << " }" << endl;
        break;
    case printItemEnum::DEGREEPROGRAM:  // Print degree program
        cout << "Program: " << degreeProgramStrings[(int)degreeProgram] << endl;
        break;
    case printItemEnum::ALL:  // Print all attributes
        cout << setw(10) << "StudentID: " << setw(6) << left << studentID
            << setw(10) << "First Name: " << setw(10) << firstName
            << setw(10) << "Last Name: " << setw(10) << lastName
            << setw(10) << "Email: " << setw(30) << email
            << setw(10) << "Age: " << setw(6) << age
            << setw(10) << "Days In Course: { ";
        for (int i = 0; i < 3; i++) {  // Print each day in course
            cout << daysToComplete[i];
            if (i + 1 < 3) {
                cout << ", ";  // Print comma if not last element
            }
        }
        cout << " }\t"
            << "Program: " << degreeProgramStrings[(int)degreeProgram] << endl;
        break;
    }
}

// Destructor to handle cleanup
student::~student() {
    cout << "Backend Info: Student Destructor called" << endl;
}
