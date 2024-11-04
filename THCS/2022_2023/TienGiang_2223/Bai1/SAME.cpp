#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ifstream input("SAME.INP");
    ofstream output("SAME.OUT");

    int n;
    input >> n; // Đọc số lượng cây

    unordered_map<int, int> frequency; // Sử dụng unordered_map để đếm tần số
    vector<int> heights(n);

    // Đọc chiều cao của các cây và đếm tần số
    for (int i = 0; i < n; i++) {
        input >> heights[i];
        frequency[heights[i]]++;
    }

    // Tìm tần số lớn nhất
    int max_freq = 0;
    for (const auto& pair : frequency) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
        }
    }

    // Ghi kết quả vào tệp
    output << max_freq << endl;

    input.close();
    output.close();
    return 0;
}
