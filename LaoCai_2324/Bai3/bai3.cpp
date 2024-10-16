#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    // Đọc dữ liệu từ tệp bai3.inp
    ifstream infile("bai3.inp");
    ofstream outfile("bai3.out");

    int n, k;
    infile >> n >> k; // Đọc n và k
    vector<int> a(n);

    // Đọc dãy số a
    for (int i = 0; i < n; i++) {
        infile >> a[i];
    }

    // Sắp xếp dãy số a theo thứ tự giảm dần
    sort(a.begin(), a.end(), greater<int>());

    // Tính giá trị biểu thức
    long long sumPositive = 0; // Tổng các số sẽ cộng
    long long sumNegative = 0; // Tổng các số sẽ trừ

    // Cộng k số đầu tiên
    for (int i = 0; i < k; i++) {
        sumPositive += a[i];
    }

    // Trừ các số còn lại
    for (int i = k; i < n; i++) {
        sumNegative += a[i];
    }

    // Tính giá trị biểu thức
    long long result = sumPositive - sumNegative;

    // Ghi kết quả vào tệp bai3.out
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
