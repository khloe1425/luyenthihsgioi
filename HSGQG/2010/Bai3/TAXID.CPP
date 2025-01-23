#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("TAXID.INP");
    ofstream output("TAXID.OUT");

    int n, m, p, q;
    input >> n >> m >> p >> q;

    int k = n / 2; // Number of skipped codes
    vector<int> skipped(k);
    for (int i = 0; i < k; i++) {
        input >> skipped[i];
    }

    // Generate valid codes
    vector<int> valid_codes;
    for (int i = 1; i <= n; i++) {
        if (find(skipped.begin(), skipped.end(), i) == skipped.end()) {
            valid_codes.push_back(i);
        }
    }

    // Distribute codes among bureaus
    vector<vector<int>> bureaus(m);
    int total_codes = valid_codes.size();
    for (int i = 0; i < total_codes; i++) {
        int bureau_index = i % m;
        bureaus[bureau_index].push_back(valid_codes[i]);
    }

    // Sort bureaus based on odd/even rules
    for (int i = 0; i < m; i++) {
        if ((i + 1) % 2 == 0) {
            reverse(bureaus[i].begin(), bureaus[i].end());
        }
    }

    // Find the tax code for the specified bureau and person
    int result = bureaus[p - 1][q - 1];

    // Write the result to the output file
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
