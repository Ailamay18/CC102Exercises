#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int main() {
    char runAgain;

    do {
        array<array<float, 4>, 5> sales{};
        int sp, prod;
        float amount;
        char choice;

        cout << "\n--- Monthly Sales Input ---\n";

        do {
            cout << "\nSalesperson (1-4): ";
            cin >> sp;
            while(sp < 1 || sp > 4){
                cout << "Invalid input! Enter salesperson number (1-4): ";
                cin >> sp;
            }

            cout << "Product (1-5): ";
            cin >> prod;
            while(prod < 1 || prod > 5){
                cout << "Invalid input! Enter product number (1-5): ";
                cin >> prod;
            }

            cout << "Amount: $";
            cin >> amount;
            while(amount < 0){
                cout << "Invalid amount! Enter a positive value: $";
                cin >> amount;
            }

            sales[prod-1][sp-1] += amount;

            cout << "Add more? (y/n): ";
            cin >> choice;

        } while(choice == 'y' || choice == 'Y');  // end input do-while

        cout << "\n---------------- Monthly Sales Summary ----------------\n";
        cout << setw(10) << "Product"
             << setw(8) << "S1"
             << setw(8) << "S2"
             << setw(8) << "S3"
             << setw(8) << "S4"
             << setw(10) << "Total" << endl;

        cout << "--------------------------------------------------------\n";

        float grandTotal = 0;

        for(int i = 0; i < 5; i++){
            float rowTotal = 0;
            cout << setw(10) << i+1;
            for(int j = 0; j < 4; j++){
                cout << setw(8) << fixed << setprecision(2) << sales[i][j];
                rowTotal += sales[i][j];
            }
            cout << setw(10) << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "--------------------------------------------------------\n";

        cout << setw(10) << "Total";
        for(int j = 0; j < 4; j++){
            float colTotal = 0;
            for(int i = 0; i < 5; i++)
                colTotal += sales[i][j];
            cout << setw(8) << fixed << setprecision(2) << colTotal;
        }

        cout << setw(10) << grandTotal << endl;
        cout << "--------------------------------------------------------\n";

        cout << "Would you like to run the program again? (y/n): ";
        cin >> runAgain;

    } while(runAgain == 'y' || runAgain == 'Y'); // end run-again do-while

    cout << "\nThank you for using the Monthly Sales Summary program!\n";
    return 0;
}

