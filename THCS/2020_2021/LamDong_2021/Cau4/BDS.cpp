#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solve(int n) {
    vector<int> result;

    while (n > 0) {
        int largestSquare = (int)sqrt(n);  // Tìm số lớn nhất có bình phương <= n
        result.push_back(largestSquare);
        n -= largestSquare * largestSquare;  // Trừ giá trị bình phương ra khỏi n
    }

    return result;
}

int main() {
    ifstream inputFile("BDS.INP");
    ofstream outputFile("BDS.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    // Giải bài toán
    vector<int> result = solve(n);

    // Sắp xếp kết quả theo thứ tự giảm dần
    sort(result.rbegin(), result.rend());

    // Ghi kết quả ra file
    for (size_t i = 0; i < result.size(); i++) {
        outputFile << result[i];
        if (i < result.size() - 1) outputFile << " ";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
