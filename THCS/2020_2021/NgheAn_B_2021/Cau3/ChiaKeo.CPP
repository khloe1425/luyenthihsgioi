// CHIAKEO.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    ifstream input("ChiaKeo.Inp");
    ofstream output("ChiaKeo.Out");

    int N;
    input >> N;

    vector<int> candies(N);
    long long totalSum = 0;

    for (int i = 0; i < N; ++i) {
        input >> candies[i];
        totalSum += candies[i];
    }

    long long x = 0;
    long long minDifference = LLONG_MAX;

    for (int i = 0; i < N - 1; ++i) {
        x += candies[i];
        long long y = totalSum - x;
        minDifference = min(minDifference, abs(x - y));
    }

    output << minDifference << endl;

    input.close();
    output.close();

    return 0;
}
