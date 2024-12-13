#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream input("LWORD.INP");   // Mở tệp đầu vào
    ofstream output("LWORD.OUT"); // Mở tệp đầu ra

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở tệp!" << endl;
        return 1;
    }

    string line;
    getline(input, line); // Đọc toàn bộ dòng từ tệp

    stringstream ss(line); // Sử dụng stringstream để tách các từ
    string word;
    int maxLength = 0;

    while (ss >> word) { // Tách từng từ
        maxLength = max(maxLength, (int)word.length()); // Cập nhật độ dài lớn nhất
    }

    output << maxLength << endl; // Ghi kết quả vào tệp

    input.close();
    output.close();

    return 0;
}
