#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("FAIL.INP");
    ofstream output("FAIL.OUT");

    int n, k;
    input >> n >> k;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        input >> scores[i];
    }

    // Tìm điểm số cao nhất của thí sinh không đoạt giải
    int maxFailScore = -1;
    for (int i = 0; i < n; i++) {
        if (scores[i] < k) {
            maxFailScore = max(maxFailScore, scores[i]);
        }
    }

    output << maxFailScore << endl;

    input.close();
    output.close();

    return 0;
}
