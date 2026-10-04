#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class to hold student details
class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    // Constructor
    Student(int r, string n, float m) {
        rollNumber = r;
        name = n;
        marks = m;
    }

    // Getters
    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    float getMarks() const { return marks; }

    // Setters for updating records
    void setName(string n) { name = n; }
    void setMarks(float m) { marks = m; }

    // Display student detail in a single formatted row
    void displayRow() const {
        cout << left << setw(12) << rollNumber 
             << setw(25) << name 
             << fixed << setprecision(2) << marks << endl;
    }
};

// Function declarations
void addStudent(vector<Student>& students);
void displayAll(const vector<Student>& students);
void updateStudent(vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n=========================================\n";
        cout << "  STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Update Student Record\n";
        cout << "4. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAll(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                cout << "\nExiting Program. Thank you!\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}

// Function to add a new student
void addStudent(vector<Student>& students) {
    int roll;
    string name;
    float marks;

    cout << "\n--- Add New Student ---\n";
    cout << "Enter Roll Number: ";
    cin >> roll;

    // Check if roll number already exists
    for (const auto& s : students) {
        if (s.getRollNumber() == roll) {
            cout << "Error: A student with Roll Number " << roll << " already exists!\n";
            return;
        }
    }

    cin.ignore(); // Clear newline buffer before reading string
    cout << "Enter Full Name: ";
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    students.push_back(Student(roll, name, marks));
    cout << "\nStudent record added successfully!\n";
}

// Function to display all student records
void displayAll(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo records found!\n";
        return;
    }

    cout << "\n-------------------------------------------------\n";
    cout << left << setw(12) << "Roll No" << setw(25) << "Name" << "Marks\n";
    cout << "-------------------------------------------------\n";
    for (const auto& s : students) {
        s.displayRow();
    }
    cout << "-------------------------------------------------\n";
}

// Function to update existing student record
void updateStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo records available to update!\n";
        return;
    }

    int roll;
    cout << "\n--- Update Student Record ---\n";
    cout << "Enter Roll Number of student to update: ";
    cin >> roll;

    for (auto& s : students) {
        if (s.getRollNumber() == roll) {
            string newName;
            float newMarks;

            cin.ignore();
            cout << "Found record for Roll Number " << roll << "!\n";
            cout << "Enter New Name: ";
            getline(cin, newName);
            cout << "Enter New Marks: ";
            cin >> newMarks;

            s.setName(newName);
            s.setMarks(newMarks);

            cout << "\nRecord updated successfully!\n";
            return;
        }
    }

    cout << "\nStudent with Roll Number " << roll << " not found!\n";
}