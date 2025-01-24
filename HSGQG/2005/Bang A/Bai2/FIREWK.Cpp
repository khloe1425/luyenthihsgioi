#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, C;
vector<int> sequence;
int validCount = 0; // Total valid sequences
vector<int> targetSequence;

// Function to check if a transition between two colors is valid
bool isValidTransition(int prev, int current) {
    if (prev == 1) return (current == 1 || current == 2);
    if (prev == m) return (current == m || current == m - 1);
    return (current == prev || current == prev - 1 || current == prev + 1);
}

// Backtracking to generate all valid sequences
void generateSequences(int index, int countC) {
    if (index == 2 * n) {
        // Check if the sequence is circular
        if (isValidTransition(sequence.back(), sequence[0])) {
            validCount++; // Count this valid sequence
            if (countC == k) {
                targetSequence = sequence; // Save the sequence containing exactly k color C
            }
        }
        return;
    }

    for (int color = 1; color <= m; color++) {
        if (index == 0 || isValidTransition(sequence[index - 1], color)) {
            sequence.push_back(color);
            generateSequences(index + 1, countC + (color == C ? 1 : 0));
            sequence.pop_back();
        }
    }
}

int main() {
    ifstream fin("FIREWK.INP");
    ofstream fout("FIREWK.OUT");

    // Input reading
    fin >> n >> m >> k >> C;

    // Initialize sequence and generate valid sequences
    sequence.reserve(2 * n);
    generateSequences(0, 0);

    // Output the total number of valid sequences
    fout << validCount << endl;

    // Output the k-th sequence containing color C, if it exists
    if (!targetSequence.empty()) {
        for (int color : targetSequence) {
            fout << color << " ";
        }
        fout << endl;
    } else {
        fout << -1 << endl; // No valid sequence found with k occurrences of C
    }

    fin.close();
    fout.close();

    return 0;
}
