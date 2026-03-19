#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

struct Student {
    int studentID;
    string name;
    string course;
    float gpa;
};

int main() {
    char runAgain;

    do {
        int n;
        cout << "===== Student GPA System =====\n";
        cout << "Enter number of students: ";
        cin >> n;

        Student students[100];

        // Input loop
        for (int i = 0; i < n; i++) {
            cout << "\n--- Student " << (i + 1) << " ---\n";

            // Student ID with uniqueness check
            int id;
            while (true) {
                cout << "Student ID: ";
                cin >> id;

                bool duplicate = false;
                for (int j = 0; j < i; j++) {
                    if (students[j].studentID == id) {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate) {
                    students[i].studentID = id;
                    break;
                } else {
                    cout << "Error: Student ID already exists. Please enter another ID.\n";
                }
            }

            cin.ignore();
            cout << "Name: ";
            getline(cin, students[i].name);

            cout << "Course: ";
            getline(cin, students[i].course);

            // GPA validation
            float gpa;
            while (true) {
                cout << "GPA (0-100): ";
                cin >> gpa;
                if (gpa >= 0 && gpa <= 100) {
                    students[i].gpa = gpa;
                    break;
                } else {
                    cout << "Invalid GPA. Please enter a value between 0 and 100.\n";
                }
            }
        }

        // Display table
        cout << "\n===== Student Records =====\n";

        // Top border
        cout << "-" << string(12, '-')
             << "-" << string(25, '-')
             << "-" << string(20, '-')
             << "-" << string(10, '-')
             << "-" << string(15, '-')
             << "+\n";

        // Header
        cout << "-" << left << setw(11) << "Student ID"
             << "-" << setw(24) << "Name"
             << "- " << setw(19) << "Course"
             << "-" << setw(9)  << "GPA"
             << "-" << setw(14) << "Standing"
             << "|\n";

        // Header divider
        cout << "-" << string(12, '-')
             << "-" << string(25, '-')
             << "-" << string(20, '-')
             << "-" << string(10, '-')
             << "-" << string(15, '-')
             << "+\n";

        // Rows
        for (int i = 0; i < n; i++) {

            // Determine standing
            string standing;
            if (students[i].gpa >= 90)      standing = "Excellent";
            else if (students[i].gpa >= 80) standing = "Very Good";
            else if (students[i].gpa >= 70) standing = "Good";
            else if (students[i].gpa >= 60) standing = "Passing";
            else                            standing = "Failed";

            // Format GPA
            ostringstream gpaStr;
            gpaStr << fixed << setprecision(2) << students[i].gpa;

            // Print row
            cout << "| " << left << setw(11) << students[i].studentID
                 << "| " << setw(24) << students[i].name
                 << "| " << setw(19) << students[i].course
                 << "| " << setw(9)  << gpaStr.str()
                 << "| " << setw(14) << standing
                 << "|\n";

            // Row divider
            cout << "-" << string(12, '-')
                 << "-" << string(25, '-')
                 << "-" << string(20, '-')
                 << "-" << string(10, '-')
                 << "-" << string(15, '-')
                 << "+\n";
        }

        cout << "\nDo you want to run the program again? (y/n): ";
        cin >> runAgain;
        cout << "\n";

    } while (runAgain == 'y' || runAgain == 'Y');

    cout << "Program terminated. Goodbye!\n";
    return 0;
}
