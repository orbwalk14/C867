#pragma once
#include <string>

#define RESET   "\033[0m"         // Reset color
#define BOLDBLUE    "\033[1m\033[34m"  // Bold Blue color
#define RED "\x1B[31m"            // Red color
#define GREEN "\x1B[92m"          // Light Green color

using std::string;

// Constants
const int DAYS_ARRAY_SIZE = 3;  // Size of the days to complete array

// Enum Class for printing individual items for each Student
enum class printItemEnum { STUDENTID, FIRSTNAME, LASTNAME, EMAIL, AGE, DEGREEPROGRAM, DAYSTOCOMPLETE, ALL };

// Array for translating degreeProgram Enum to string output
static const string degreeProgramStrings[] = { "Security", "Network", "Software", "None" };

class student {
private:
    int age;
    degreeProgramEnum degreeProgram;
    string studentID, firstName, lastName, email;
    int daysToComplete[DAYS_ARRAY_SIZE];  // Fixed-size array instead of vector

public:
    // Accessor functions
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    degreeProgramEnum getDegreeProgram() const;
    const int* getDaysToComplete() const;  // Returns pointer to array instead of vector

    // Mutator functions
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string email);
    void setAge(int age);
    void setDegreeProgram(degreeProgramEnum degreeProgram);
    void setDaysToComplete(const int daysToComplete[DAYS_ARRAY_SIZE]);  // Takes array instead of vector

    // Constructor function
    student(
        string studentID = "NEW",
        string firstName = "NEW",
        string lastName = "NEW",
        string email = "NEW",
        int age = 0,
        const int daysToComplete[DAYS_ARRAY_SIZE] = nullptr,  // Default argument changed to nullptr
        degreeProgramEnum degreeProgram = degreeProgramEnum::NONE);

    // Print function
    void print(printItemEnum printItem) const;

    // Destructor function
    ~student();
};

