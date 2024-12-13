#include <bits/stdc++.h>
using namespace std;

// Hàm đếm số ký tự khác nhau trong một từ
int countDistinctChars(const string &word) {
    unordered_set<char> charSet;
    for (char c : word) {
        charSet.insert(c);
    }
    return charSet.size();
}

int main() {
    ifstream inputFile("CAU3.INP");
    ofstream outputFile("CAU3.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string s;
    getline(inputFile, s);
    inputFile.close();

    stringstream ss(s);
    string word;
    string result;
    int maxDistinct = 0;

    while (ss >> word) {
        // Loại bỏ các ký tự không phải chữ cái
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalpha(c);
        }), word.end());

        int distinctCount = countDistinctChars(word);
        if (distinctCount > maxDistinct) {
            maxDistinct = distinctCount;
            result = word;
        }
    }

    outputFile << result << endl;
    outputFile.close();

    return 0;
}
