// TICHBASO.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ifstream input("TichBaSo.Inp");
    ofstream output("TichBaSo.Out");

    int N;
    long long x, y, z;
    input >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        input >> A[i];
    }

    input >> x >> y >> z;

    // Khởi tạo giá trị tối đa
    long long max_x = LLONG_MIN;
    long long max_xy = LLONG_MIN;
    long long max_xyz = LLONG_MIN;

    // Duyệt qua mảng để cập nhật max_x, max_xy, max_xyz
    for (int i = 0; i < N - 2; ++i) {
        max_x = max(max_x, x * A[i]); // Cập nhật max_x cho A[i]
        for (int j = i + 1; j < N - 1; ++j) {
            max_xy = max(max_xy, max_x + y * A[j]); // Cập nhật max_xy cho A[j]
            for (int k = j + 1; k < N; ++k) {
                max_xyz = max(max_xyz, max_xy + z * A[k]); // Cập nhật max_xyz cho A[k]
            }
        }
    }

    output << max_xyz << endl;

    input.close();
    output.close();

    return 0;
}
