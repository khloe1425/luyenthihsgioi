#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Mở file input
    ifstream inputFile("BAI01.INP");
    ofstream outputFile("BAI01.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    vector<int> numbers(N);
    unordered_map<int, int> frequency;

    // Đọc dãy số và tính tần suất
    for (int i = 0; i < N; ++i) {
        inputFile >> numbers[i];
        frequency[numbers[i]]++;
    }

    // Tìm số xuất hiện nhiều nhất
    int maxFrequency = 0, maxNumber = 0;
    for (const auto& [num, freq] : frequency) {
        if (freq > maxFrequency || (freq == maxFrequency && num > maxNumber)) {
            maxFrequency = freq;
            maxNumber = num;
        }
    }

    // Ghi kết quả ra file output
    outputFile << maxNumber << " " << maxFrequency << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
