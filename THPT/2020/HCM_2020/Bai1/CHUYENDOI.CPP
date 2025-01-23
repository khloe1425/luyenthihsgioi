#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Hàm chuyển đổi số N sang hệ đếm D và trả về chuỗi
string convertToBase(int N, int D) {
    string result = "";
    while (N > 0) {
        result += char((N % D) + '0'); // Lấy phần dư và chuyển thành ký tự
        N /= D;
    }
    reverse(result.begin(), result.end()); // Đảo chuỗi để được hệ đếm đúng
    return result;
}

int main() {
    ifstream input("CHUYENDOI.INP");
    ofstream output("CHUYENDOI.OUT");

    int N, K;
    input >> N >> K;

    int bestD = 0;  // Hệ đếm tốt nhất
    int maxCount = 0; // Số lần K xuất hiện nhiều nhất

    for (int D = 2; D <= 10; ++D) {
        string converted = convertToBase(N, D);
        // Đếm số chữ số K xuất hiện ở cuối
        int countK = 0;
        for (int i = converted.size() - 1; i >= 0 && converted[i] == char(K + '0'); --i) {
            countK++;
        }

        // Cập nhật nếu tìm thấy hệ đếm tốt hơn
        if (countK > maxCount) {
            maxCount = countK;
            bestD = D;
        }
    }

    if (maxCount == 0) {
        output << "0 0" << endl; // Không có hệ nào thỏa mãn
    } else {
        output << bestD << " " << maxCount << endl;
    }

    input.close();
    output.close();

    return 0;
}
