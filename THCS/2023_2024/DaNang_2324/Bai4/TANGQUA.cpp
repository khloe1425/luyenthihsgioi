#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_increasing_subsequence(const vector<int>& sequence) {
    vector<int> lis;
    for (int value : sequence) {
        auto pos = lower_bound(lis.begin(), lis.end(), value);
        if (pos == lis.end()) {
            lis.push_back(value);
        } else {
            *pos = value;
        }
    }
    return lis.size();
}

int main() {
    ifstream infile("TANGQUA.INP");
    ofstream outfile("TANGQUA.OUT");

    int n;
    infile >> n;
    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        infile >> values[i];
    }

    int lis_length = longest_increasing_subsequence(values);
    int result = n - lis_length;

    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
