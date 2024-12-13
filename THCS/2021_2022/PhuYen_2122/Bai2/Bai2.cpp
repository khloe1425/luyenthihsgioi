#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ifstream input("Bai2.INP");   // Đọc dữ liệu từ file
    ofstream output("Bai2.OUT"); // Ghi dữ liệu ra file

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N1, N2; // Số lượng địa điểm tham quan của hai đoàn
    input >> N1; // Số lượng địa điểm đoàn 1

    vector<int> group1(N1);

    // Đọc các địa điểm tham quan của đoàn thứ nhất
    for (int i = 0; i < N1; ++i) {
        input >> group1[i];
    }

    input >> N2; // Số lượng địa điểm đoàn 2

    vector<int> group2(N2);

    // Đọc các địa điểm tham quan của đoàn thứ hai
    for (int i = 0; i < N2; ++i) {
        input >> group2[i];
    }

    // Sử dụng set để lưu trữ các địa điểm đoàn 1
    set<int> result(group1.begin(), group1.end());

    // Tìm giao giữa hai tập hợp
    set<int> intersection;
    for (int place : group2) {
        if (result.find(place) != result.end()) {
            intersection.insert(place);
        }
    }

    // Ghi các địa điểm chung ra file
    if (intersection.empty()) {
        output << "Không có địa điểm chung" << endl;
    } else {
        for (int place : intersection) {
            output << place << " ";
        }
    }

    input.close();
    output.close();

    return 0;
}
