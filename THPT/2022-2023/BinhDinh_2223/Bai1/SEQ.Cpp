#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("SEQ.INP");
    ofstream output("SEQ.OUT");

    int n, Q;
    input >> n >> Q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }

    while (Q--) {
        int K;
        input >> K;

        int start = 0, maxLength = 0, count = 0;

        for (int end = 0; end < n; end++) {
            if (a[end] <= K) {
                count++;
            } else {
                count = 0; // Reset count when element exceeds K
            }

            maxLength = max(maxLength, count);
        }

        output << maxLength << endl;
    }

    input.close();
    output.close();
    return 0;
}
