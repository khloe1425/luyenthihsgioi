// DEMTUTL.CPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to convert a string to lowercase
string toLowercase(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    ifstream input("DEMTUTL.INP");
    ofstream output("DEMTUTL.OUT");

    if (!input || !output) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    string line, word, prevWord = "";
    unordered_map<string, int> wordCount;
    unordered_set<string> repeatedWordsSet;
    vector<string> repeatedWords;

    // Read input file line by line
    while (getline(input, line)) {
        istringstream iss(line);
        while (iss >> word) {
            word = toLowercase(word);

            // Count individual words (condition 1)
            wordCount[word]++;

            // Check for consecutive duplicates (condition 2)
            if (!prevWord.empty() && prevWord == word) {
                repeatedWordsSet.insert(word + " " + word);
            }

            prevWord = word;
        }
        prevWord = ""; // Reset at the end of each line
    }

    // Collect all repeated words from wordCount (condition 1)
    for (const auto &entry : wordCount) {
        if (entry.second > 1) {
            repeatedWordsSet.insert(entry.first);
        }
    }

    // Convert the set to a vector for ordered output
    repeatedWords.assign(repeatedWordsSet.begin(), repeatedWordsSet.end());
    sort(repeatedWords.begin(), repeatedWords.end());

    // Output the results
    output << repeatedWords.size() << endl;
    for (size_t i = 0; i < repeatedWords.size(); ++i) {
        output << repeatedWords[i];
        if (i < repeatedWords.size() - 1) {
            output << " ";
        }
    }

    input.close();
    output.close();

    return 0;
}
