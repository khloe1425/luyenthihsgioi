#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm tìm độ dài của dãy con tăng dài nhất
int longestIncreasingSubsequence(const vector<int>& sequence) {
    vector<int> dp; // Mảng chứa các giá trị của dãy tăng

    for (int num : sequence) {
        // Tìm vị trí để thay thế hoặc chèn giá trị mới vào dãy tăng
        auto it = lower_bound(dp.begin(), dp.end(), num);

        if (it == dp.end()) {
            // Nếu không tìm thấy vị trí, thêm phần tử mới vào dãy tăng
            dp.push_back(num);
        } else {
            // Nếu tìm thấy, thay thế giá trị
            *it = num;
        }
    }

    return dp.size(); // Kích thước của dp chính là độ dài dãy con tăng dài nhất
}

int main() {
    ifstream inputFile("DAYSO.INP");
    ofstream outputFile("DAYSO.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N;
    string numberString;

    // Đọc dữ liệu từ file
    inputFile >> N;
    inputFile >> numberString;

    // Chuyển chuỗi ký tự thành vector các số nguyên
    vector<int> sequence;
    for (char ch : numberString) {
        sequence.push_back(ch - '0'); // Chuyển ký tự thành số nguyên
    }

    // Tìm độ dài của dãy con tăng dài nhất
    int result = longestIncreasingSubsequence(sequence);

    // Ghi kết quả ra file
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
