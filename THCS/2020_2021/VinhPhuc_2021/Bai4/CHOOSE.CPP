// CHOOSE.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> results;

// Recursive function to find all combinations
void findCombinations(int n, int start, vector<int>& combination) {
    if (n == 0) {
        results.push_back(combination);
        return;
    }

    for (int i = start; i <= n; ++i) {
        combination.push_back(i);
        findCombinations(n - i, i + 1, combination);
        combination.pop_back();
    }
}

int main() {
    ifstream input("CHOOSE.INP");
    ofstream output("CHOOSE.OUT");

    int N;
    input >> N;

    vector<int> combination;
    findCombinations(N, 1, combination);

    // Sort results lexicographically
    sort(results.begin(), results.end());

    // Write results to output file
    for (const auto& combination : results) {
        for (size_t i = 0; i < combination.size(); ++i) {
            if (i > 0) output << " ";
            output << combination[i];
        }
        output << endl;
    }

    input.close();
    output.close();

    return 0;
}
