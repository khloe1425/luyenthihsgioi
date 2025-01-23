#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream infile("kethop.inp");
    ofstream outfile("kethop.out");

    int x, y, z, n;
    infile >> x >> y >> z >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        infile >> a[i];
    }

    long long maxT = LLONG_MIN; // Khởi tạo giá trị nhỏ nhất cho maxT

    // Duyệt qua tất cả các bộ ba (i, j, k) thỏa mãn i < j < k
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                long long T = x * a[i] + y * a[j] + z * a[k];
                maxT = max(maxT, T); // Cập nhật giá trị lớn nhất
            }
        }
    }

    outfile << maxT << endl;

    infile.close();
    outfile.close();

    return 0;
}
