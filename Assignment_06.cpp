#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimes(const string& filename) {
    ifstream file(filename);
    int count = 0, num;

    while (file >> num) {
        if (isPrime(num)) count++;
    }

    file.close();
    return count;
}

int main() {
    int result = countPrimes("NUMS.TXT");
    cout << "Prime count: " << result << endl;
    return 0;
}
