#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){


    fstream outFile;
    outFile.open("color.txt", ios::out);
    if(outFile.is_open()){
        outFile << "Red\n";
        outFile << "Blue\n";
        outFile << "Green\n";
        outFile << "Yellow\n";
        outFile << "Purple\n";
        outFile.close();
        cout << "color.txt written successfully!\n";
    }else{
        cout << "Failed to open color.txt for writing.\n";
        return 1;
    }

 
    fstream inFile;
    inFile.open("color.txt", ios::in);
    if(!inFile.is_open()){
        cout << "Failed to open color.txt for reading.\n";
        return 1;
    }

 
    fstream copyFile;
    copyFile.open("color_copy.txt", ios::out);
    if(!copyFile.is_open()){
        cout << "Failed to open color_copy.txt.\n";
        return 1;
    }

    string line;
    while(getline(inFile, line)){
        copyFile << line << "\n";
    }

    inFile.close();
    copyFile.close();
    cout << "color_copy.txt created successfully!\n";

    return 0;
}
