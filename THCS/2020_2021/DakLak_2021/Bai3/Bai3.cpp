#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    // Open input and output files
    ifstream inputFile("BAI3.INP");
    ofstream outputFile("BAI3.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Cannot open file!" << endl;
        return 1;
    }

    string S;
    inputFile >> S; // Read the input string

    unordered_map<char, int> frequency; // To store character frequencies

    // Count the frequency of each character in the string
    for (char ch : S) {
        frequency[ch]++;
    }

    int count = 0;

    // Count how many characters appear exactly twice
    for (const auto &entry : frequency) {
        if (entry.second == 2) {
            count++;
        }
    }

    // If no characters meet the condition, output -1
    if (count == 0) {
        outputFile << -1 << endl;
    } else {
        outputFile << count << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
