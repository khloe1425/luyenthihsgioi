#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tìm giá trị lớn nhất của biểu thức (ai - aj) * (ak - al)
long long findMaxPassword(const vector<int>& arr, int n) {
    // Sắp xếp mảng
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    // Tính hai lựa chọn
    long long option1 = (long long)(sortedArr[n - 1] - sortedArr[0]) * (sortedArr[n - 2] - sortedArr[1]);
    long long option2 = (long long)(sortedArr[n - 1] - sortedArr[1]) * (sortedArr[n - 2] - sortedArr[0]);

    // Kết quả là giá trị lớn nhất trong hai lựa chọn
    return max(option1, option2);
}

int main() {
    // Mở file input và output
    ifstream inputFile("pass.inp");
    ofstream outputFile("pass.out");

    // Đọc số phần tử
    int n;
    inputFile >> n;

    // Đọc mảng số nguyên
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> arr[i];
    }

    // Tìm kết quả và ghi ra file output
    long long result = findMaxPassword(arr, n);
    outputFile << result << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
