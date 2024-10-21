#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("GIFT.INP"); // Mở file đầu vào
    ofstream outfile("GIFT.OUT"); // Mở file đầu ra

    int N, K;
    infile >> N >> K; // Đọc số lượng phần quà và K
    vector<int> gifts(N);

    for (int i = 0; i < N; i++) {
        infile >> gifts[i]; // Đọc giá trị các phần quà
    }

    // Sắp xếp danh sách phần quà theo giá trị tăng dần
    sort(gifts.begin(), gifts.end());

    int count = 0;  // Số lượng phần quà đã chọn
    int lastGift = -1;  // Giá trị của phần quà cuối cùng đã chọn

    for (int i = 0; i < N; i++) {
        // Kiểm tra xem phần quà có thể được chọn hay không
        if (lastGift == -1 || gifts[i] >= lastGift + K) {
            count++;
            lastGift = gifts[i];  // Cập nhật giá trị của phần quà đã chọn
        }
    }

    outfile << count << endl;  // Ghi số lượng phần quà đã chọn vào file đầu ra

    infile.close();  // Đóng file đầu vào
    outfile.close(); // Đóng file đầu ra

    return 0;
}
