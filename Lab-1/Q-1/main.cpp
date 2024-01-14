#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    int x;
    int largest = INT_MIN, secondLargest = INT_MIN;
    
    while (inputFile >> x) {
        if(x > largest) {
            secondLargest = largest;
            largest = x;
            continue;
        }
        if(x > secondLargest) secondLargest = x;
    }

    inputFile.close();

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    outputFile << largest + secondLargest << endl;
    outputFile.close();
    cout << "Data has been written to output.txt." << endl;

    return 0;
}