#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream inputFile("BAI2.INP");  // Mở file đầu vào
    ofstream outputFile("BAI2.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    string fullName;
    getline(inputFile, fullName); // Đọc chuỗi từ file đầu vào

    // Loại bỏ khoảng trắng thừa ở đầu và cuối
    while (!fullName.empty() && fullName.front() == ' ') {
        fullName.erase(fullName.begin());
    }
    while (!fullName.empty() && fullName.back() == ' ') {
        fullName.pop_back();
    }

    // Tách từ cuối cùng là tên
    stringstream ss(fullName);
    string word, lastName;
    while (ss >> word) {
        lastName = word;
    }

    outputFile << lastName << endl; // Ghi kết quả vào file đầu ra

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
