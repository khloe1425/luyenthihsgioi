#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> // Thêm thư viện thuật toán

using namespace std;

// Hàm Bubble Sort thủ công
void manualSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    // Mở file input và output
    ifstream inputFile("PRDESIGN.INP");
    ofstream outputFile("PRDESIGN.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<int> vertical;   // Các đường dọc (x = u)
    vector<int> horizontal; // Các đường ngang (y = v)

    // Đọc dữ liệu
    for (int i = 0; i < n; ++i) {
        int type, coord;
        inputFile >> type >> coord;
        if (type == 0) {
            horizontal.push_back(coord); // Đường ngang
        } else {
            vertical.push_back(coord);   // Đường dọc
        }
    }

    // Thêm biên của bản đồ
    horizontal.push_back(0);
    horizontal.push_back(1000000000);
    vertical.push_back(0);
    vertical.push_back(1000000000);

    // Sắp xếp các đường kênh rạch bằng Bubble Sort
    manualSort(horizontal);
    manualSort(vertical);

    // Tìm khoảng cách lớn nhất giữa các đường ngang
    int maxHorizontalGap = 0;
    for (size_t i = 1; i < horizontal.size(); ++i) {
        maxHorizontalGap = max(maxHorizontalGap, horizontal[i] - horizontal[i - 1]);
    }

    // Tìm khoảng cách lớn nhất giữa các đường dọc
    int maxVerticalGap = 0;
    for (size_t i = 1; i < vertical.size(); ++i) {
        maxVerticalGap = max(maxVerticalGap, vertical[i] - vertical[i - 1]);
    }

    // Độ dài cạnh lớn nhất của hình vuông
    int maxSquareSize = min(maxHorizontalGap, maxVerticalGap);

    // Ghi kết quả ra file output
    outputFile << maxSquareSize << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
