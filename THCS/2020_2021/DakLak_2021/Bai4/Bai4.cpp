#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Mở file đầu vào và đầu ra
    ifstream inputFile("BAI4.INP");
    ofstream outputFile("BAI4.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N;
    inputFile >> N; // Đọc số lượng phần tử

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> arr[i]; // Đọc các phần tử của mảng
    }

    inputFile.close();

    // Sắp xếp mảng
    sort(arr.begin(), arr.end());

    // Tính tích lớn nhất
    // Trường hợp 1: Tích của 3 số lớn nhất
    int option1 = arr[N-1] * arr[N-2] * arr[N-3];
    // Trường hợp 2: Tích của 2 số nhỏ nhất và số lớn nhất
    int option2 = arr[0] * arr[1] * arr[N-1];
    // Lấy giá trị lớn nhất của hai trường hợp
    int maxProduct = max(option1, option2);

    // Ghi kết quả vào file
    outputFile << maxProduct << endl;
    outputFile.close();

    cout << "Kết quả đã được ghi vào file BAI4.OUT" << endl;

    return 0;
}
