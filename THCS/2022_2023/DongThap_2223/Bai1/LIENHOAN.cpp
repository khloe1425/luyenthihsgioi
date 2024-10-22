#include <iostream>
#include <cmath> // Để sử dụng hàm ceil
#include <fstream> // Để đọc ghi tệp
using namespace std;

int main() {
    ifstream input("LIENHOAN.INP");
    ofstream output("LIENHOAN.OUT");
    
    int n, k;
    input >> n >> k; // Đọc số bánh và số bánh tối đa có thể chiên cùng lúc
    
    // Tính số mặt bánh cần chiên
    int total_faces = 2 * n;

    // Tính số lần chiên cần thiết
    int batches = (total_faces + k - 1) / k; // Tương đương với ceil(total_faces / k)

    // Thời gian tối thiểu
    int min_time = batches * 3; // Mỗi lần chiên tốn 3 phút

    output << min_time; // Ghi thời gian ra tệp
    input.close();
    output.close();

    return 0;
}
