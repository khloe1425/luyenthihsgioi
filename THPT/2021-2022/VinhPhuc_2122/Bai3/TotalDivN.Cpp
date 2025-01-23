#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ifstream input("TotalDivN.inp");
    ofstream output("TotalDivN.out");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error: Could not open file(s)." << endl;
        return 1;
    }

    int M, N;
    input >> M >> N;

    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        input >> A[i];
    }

    // Variable to count the number of valid subsets
    long long result = 0;

    // Use unordered_map to store the count of remainders
    unordered_map<int, int> remainderCount;
    remainderCount[0] = 1; // Empty subset contributes to a sum of 0, which is divisible by N

    int currentSumMod = 0;

    for (int i = 0; i < M; i++) {
        // Update the running sum modulo N
        currentSumMod = (currentSumMod + A[i]) % N;

        // Ensure non-negative remainders
        if (currentSumMod < 0) {
            currentSumMod += N;
        }

        // Add the count of subsets that produce the same remainder
        if (remainderCount.find(currentSumMod) != remainderCount.end()) {
            result += remainderCount[currentSumMod];
        }

        // Increment the count of the current remainder
        remainderCount[currentSumMod]++;
    }

    // Write the result to the output file
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
