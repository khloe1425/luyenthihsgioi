#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("SEQGAME.INP");
    ofstream output("SEQGAME.OUT");

    int n;
    input >> n;

    vector<int> b(n), c(n);

    // Read array b
    for (int i = 0; i < n; i++) {
        input >> b[i];
    }

    // Read array c
    for (int i = 0; i < n; i++) {
        input >> c[i];
    }

    // Find the minimum value in both arrays
    int min_b = *min_element(b.begin(), b.end());
    int min_c = *min_element(c.begin(), c.end());

    // Calculate the minimum sum
    int min_sum = min_b + min_c;

    // Write the result to the output file
    output << min_sum << endl;

    input.close();
    output.close();

    return 0;
}
