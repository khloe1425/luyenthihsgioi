// NGHICHTHE.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ifstream input("NghichThe.Inp");
    ofstream output("NghichThe.Out");

    int N;
    input >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        input >> A[i];
    }

    int minDifference = INT_MAX;

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (A[i] > A[j]) {
                minDifference = min(minDifference, A[i] - A[j]);
            }
        }
    }

    output << minDifference << endl;

    input.close();
    output.close();

    return 0;
}
