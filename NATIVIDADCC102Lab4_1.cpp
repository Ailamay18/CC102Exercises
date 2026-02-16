#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main() {
    char again;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes per student: ";
        cin >> quizzes;


        array<array<int,20>,20> scores{};
        array<float,20> average{};

        for(int i=0; i<students; i++) {
            int sum = 0;

            cout << "\nEnter scores for Student " << i+1 << ":\n";
            for(int j=0; j<quizzes; j++) {
                cout << "Quiz " << j+1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = (float)sum / quizzes;
        }

        cout << "\n----------------------------------------------\n";
        cout << setw(12) << "Student";

        for(int q=0; q<quizzes; q++) {
            cout << setw(8) << ("Q" + to_string(q+1));
        }

        cout << setw(10) << "Average\n";
        cout << "----------------------------------------------\n";

        for(int i=0; i<students; i++) {
            cout << setw(12) << ("Student " + to_string(i+1));

            for(int j=0; j<quizzes; j++) {
                cout << setw(8) << scores[i][j];
            }

            cout << setw(10) << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "----------------------------------------------\n";

        cout << "\nRun program again? (y/n): ";
        cin >> again;

    } while(again=='y' || again=='Y');

    return 0;
}
