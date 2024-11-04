#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream infile("TANGQUA.INP");
    int N;
    infile >> N; // Số lượng món quà
    vector<int> gifts(N);

    // Đọc giá trị quà
    for (int i = 0; i < N; ++i) {
        infile >> gifts[i];
    }
    infile.close();

    // Tìm giá trị lớn nhất
    int max_value = *max_element(gifts.begin(), gifts.end());

    // Đếm số lượng quà có giá trị lớn nhất
    int count_max_gifts = count(gifts.begin(), gifts.end(), max_value);

    // Ghi kết quả vào file
    ofstream outfile("TANGQUA.OUT");
    outfile << count_max_gifts << endl;
    outfile.close();

    return 0;
}
