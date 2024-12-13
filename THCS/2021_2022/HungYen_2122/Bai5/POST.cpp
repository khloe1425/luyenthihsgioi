#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("POST.INP");
    ofstream output("POST.OUT");

    int N;
    input >> N;

    vector<int> positions(N);
    for (int i = 0; i < N; i++) {
        input >> positions[i];
    }

    // Sắp xếp vị trí để tối ưu việc tính tổng khoảng cách
    sort(positions.begin(), positions.end());

    vector<long long> P(N, 0);
    long long totalSum = 0;

    // Tính tổng trước
    for (int i = 0; i < N; i++) {
        totalSum += positions[i];
    }

    long long leftSum = 0;
    for (int i = 0; i < N; i++) {
        long long rightSum = totalSum - leftSum - positions[i];
        P[i] = (i * 1LL * positions[i] - leftSum) + (rightSum - (N - 1 - i) * 1LL * positions[i]);
        leftSum += positions[i];
    }

    // Ghi kết quả ra file
    for (int i = 0; i < N; i++) {
        output << P[i] << " ";
    }

    input.close();
    output.close();
    return 0;
}
