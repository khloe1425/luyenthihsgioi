#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("TROCHOI.INP");
    ofstream outputFile("TROCHOI.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N; // Số lần quay số
    inputFile >> N;

    unordered_map<int, int> frequency; // Bảng tần suất xuất hiện của từng số
    int maxFrequency = 0; // Tần suất lớn nhất
    int luckyNumber = 0; // Con số may mắn

    // Đọc các số và đếm tần suất
    for (int i = 0; i < N; ++i) {
        int num;
        inputFile >> num;

        frequency[num]++; // Tăng tần suất của số num

        // Cập nhật con số may mắn
        if (frequency[num] > maxFrequency || (frequency[num] == maxFrequency && num < luckyNumber)) {
            maxFrequency = frequency[num];
            luckyNumber = num;
        }
    }

    // Ghi kết quả ra file
    outputFile << luckyNumber << " " << maxFrequency << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
