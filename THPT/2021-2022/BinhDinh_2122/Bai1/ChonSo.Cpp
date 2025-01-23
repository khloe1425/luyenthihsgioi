#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm kiểm tra xem có thể chọn được K phần tử với khoảng cách tối thiểu là d không
bool canChooseK(const vector<int>& a, int K, int d) {
    int count = 1; // Luôn chọn phần tử đầu tiên
    int lastChosen = a[0];

    for (int i = 1; i < a.size(); i++) {
        if (a[i] - lastChosen >= d) {
            count++;
            lastChosen = a[i];
            if (count == K) return true;
        }
    }
    return false;
}

int main() {
    ifstream infile("ChonSo.INP");
    ofstream outfile("ChonSo.OUT");

    int N, K;
    infile >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        infile >> a[i];
    }

    // Sắp xếp mảng
    sort(a.begin(), a.end());

    // Tìm kiếm nhị phân trên khoảng cách nhỏ nhất
    int left = 1, right = a[N - 1] - a[0];
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canChooseK(a, K, mid)) {
            result = mid; // Cập nhật kết quả
            left = mid + 1; // Thử khoảng cách lớn hơn
        } else {
            right = mid - 1; // Thử khoảng cách nhỏ hơn
        }
    }

    // Ghi kết quả
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
