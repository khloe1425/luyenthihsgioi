// CHIAKEO.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ifstream input("ChiaKeo.Inp");
    ofstream output("ChiaKeo.Out");

    int N;
    input >> N;

    vector<int> A(N);
    vector<long long> prefixSum(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        input >> A[i];
        prefixSum[i + 1] = prefixSum[i] + A[i];
    }

    long long minT = LLONG_MAX;

    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long x = prefixSum[i];
            long long y = prefixSum[j] - prefixSum[i];
            long long z = prefixSum[N] - prefixSum[j];

            // Sử dụng std::max và std::min cho 3 giá trị
            long long maxVal = std::max(x, std::max(y, z));
            long long minVal = std::min(x, std::min(y, z));

            minT = std::min(minT, maxVal - minVal);
        }
    }

    output << minT << endl;

    input.close();
    output.close();

    return 0;
}
