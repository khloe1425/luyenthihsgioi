#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm tìm độ dài của dãy con tăng dần dài nhất
int longestIncreasingSubsequence(const vector<int>& values) {
    int max_length = 0;
    int current_length = 1;

    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] > values[i - 1]) {  // Kiểm tra nếu giá trị tăng
            current_length++;
        } else {
            max_length = max(max_length, current_length);  // Cập nhật độ dài lớn nhất
            current_length = 1;  // Reset độ dài hiện tại
        }
    }
    
    // Cập nhật một lần nữa để xem chuỗi cuối có phải là dài nhất không
    max_length = max(max_length, current_length);
    return max_length;
}

int main() {
    ifstream infile("GIFT.INP");
    ofstream outfile("GIFT.OUT");

    if (!infile) {
        cerr << "Không thể mở file GIFT.INP!" << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        vector<int> values;
        size_t pos = 0;

        // Phân tách các số trong dòng
        while ((pos = line.find(' ')) != string::npos) {
            values.push_back(stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        values.push_back(stoi(line)); // thêm số cuối

        // Tìm độ dài dãy con tăng dần và ghi vào file
        int result = longestIncreasingSubsequence(values);
        outfile << result << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
