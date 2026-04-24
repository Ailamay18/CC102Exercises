#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    
    ofstream original("original.txt");
    original << "One\nTwo\nThree\nFour\nFive\nSix\n";
    original.close();

  
    ifstream inFile("original.txt");
    vector<string> words;
    string word;

    while (getline(inFile, word)) {
        words.push_back(word);
    }
    inFile.close();

    
    sort(words.begin(), words.end());

  
    ofstream sorted("sorted.txt");
    for (const string& w : words) {
        sorted << w << "\n";
    }
    sorted.close();

    cout << "Done! Files created." << endl;

    return 0;
}
