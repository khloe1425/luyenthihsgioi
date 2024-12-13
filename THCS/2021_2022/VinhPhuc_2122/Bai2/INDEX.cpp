#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <fstream> // Thêm thư viện để sử dụng ifstream và ofstream

using namespace std;

struct Student {
    int district; // Mã số huyện
    int index;    // Số báo danh
};

// Hàm so sánh để sắp xếp các thí sinh theo số báo danh
bool compareByIndex(const Student &a, const Student &b) {
    return a.index < b.index;
}

int main() {
    // Mở file input và output
    ifstream inputFile("INDEX.inp");
    ofstream outputFile("INDEX.out");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    map<int, queue<int>> grouped; // Lưu các thí sinh theo từng huyện (hàng đợi)
    vector<Student> students(n);

    // Đọc dữ liệu
    for (int i = 0; i < n; i++) {
        int district, index;
        inputFile >> district >> index;
        grouped[district].push(index);
    }

    // Kết quả cuối cùng
    vector<Student> result;

    // Hàng đợi các huyện để duyệt
    queue<int> districtsQueue;
    for (auto &group : grouped) {
        districtsQueue.push(group.first);
    }

    int lastDistrict = -1; // Huyện cuối cùng đã thêm vào danh sách

    while (!districtsQueue.empty()) {
        int currentDistrict = districtsQueue.front();
        districtsQueue.pop();

        if (currentDistrict == lastDistrict && !districtsQueue.empty()) {
            // Nếu huyện hiện tại trùng với huyện cuối cùng, bỏ qua lần này
            districtsQueue.push(currentDistrict);
            continue;
        }

        if (!grouped[currentDistrict].empty()) {
            int studentIndex = grouped[currentDistrict].front();
            grouped[currentDistrict].pop();

            result.push_back({currentDistrict, studentIndex});
            lastDistrict = currentDistrict;

            if (!grouped[currentDistrict].empty()) {
                districtsQueue.push(currentDistrict);
            }
        }
    }

    // Ghi kết quả ra file
    for (const auto &student : result) {
        outputFile << student.district << " " << student.index << endl;
    }

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0; // Thêm dấu đóng của hàm main
}
