#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Hàm kiểm tra xem tất cả các giá trị trong vùng có giống nhau không
bool isUniform(const vector<vector<int>> &image, int x, int y, int size) {
    int value = image[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (image[i][j] != value) return false;
        }
    }
    return true;
}

// Hàm thực hiện nén ảnh và tính độ dài chuỗi nén
string compress(const vector<vector<int>> &image, int x, int y, int size) {
    if (isUniform(image, x, y, size)) {
        // Nếu tất cả các giá trị trong vùng giống nhau
        return image[x][y] == 1 ? "01" : "00";
    } else {
        // Chia ảnh thành 4 phần và nén từng phần
        int newSize = size / 2;
        string topLeft = compress(image, x, y, newSize);
        string topRight = compress(image, x, y + newSize, newSize);
        string bottomLeft = compress(image, x + newSize, y, newSize);
        string bottomRight = compress(image, x + newSize, y + newSize, newSize);
        return "1" + topLeft + topRight + bottomLeft + bottomRight;
    }
}

int main() {
    ifstream inputFile("IMAGE.INP");
    ofstream outputFile("IMAGE.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int size = 1 << n; // Kích thước ảnh: 2^n x 2^n
    vector<vector<int>> image(size, vector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> image[i][j];
        }
    }

    // Thực hiện nén ảnh
    string compressed = compress(image, 0, 0, size);

    // Ghi độ dài chuỗi nén ra file
    outputFile << compressed.length() << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
