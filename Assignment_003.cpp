#include <iostream>
#include <string>
using namespace std;

struct Student {
    int studentID;
    string name;
    string course;
    float gpa;
};

void input(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << (i + 1) << ":\n";


        while (true) {
            cout << "Student ID: ";
            cin >> s[i].studentID;

            bool found = false;
            for (int j = 0; j < i; j++) {
                if (s[j].studentID == s[i].studentID) {
                    found = true;
                    break;
                }
            }

            if (!found) break;
            cout << "ID already exists. Try another.\n";
        }

        cin.ignore();
        cout << "Name: ";
        getline(cin, s[i].name);

        cout << "Course: ";
        getline(cin, s[i].course);

        while (true) {
            cout << "GPA (1-100): ";
            cin >> s[i].gpa;
            if (s[i].gpa >= 1 && s[i].gpa <= 100) break;
            cout << "Invalid GPA. Please enter a value between 1 and 100.\n";
        }
    }
}

void display(Student s[], int n) {
    cout << "\n----------------------------------------------------------\n";
    cout << "ID\tName\t\tCourse\t\tGPA\tStanding\n";
    cout << "----------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        string standing;
        if (s[i].gpa >= 90)      standing = "Excellent";
        else if (s[i].gpa >= 80) standing = "Very Good";
        else if (s[i].gpa >= 70) standing = "Good";
        else if (s[i].gpa >= 60) standing = "Passing";
        else                     standing = "Failed";

        cout << s[i].studentID << "\t"
             << s[i].name << "\t\t"
             << s[i].course << "\t\t"
             << s[i].gpa << "\t"
             << standing << "\n";
    }

    cout << "----------------------------------------------------------\n";
}

int main() {
    char choice;

    do {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        Student s[100];

        input(s, n);
        display(s, n);

        cout << "\nRun again? (y/n): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
