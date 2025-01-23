#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra liệu có thể chọn K phần tử sao cho khoảng cách nhỏ nhất >= x
bool isPossible(const vector<int>& arr, int K, int x) {
    int count = 1; // Đếm số phần tử được chọn (phần tử đầu tiên luôn được chọn)
    int last_pos = arr[0]; // Vị trí phần tử được chọn cuối cùng

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] - last_pos >= x) {
            count++;
            last_pos = arr[i]; // Cập nhật phần tử được chọn cuối cùng
            if (count == K) return true; // Nếu đủ K phần tử thì trả về true
        }
    }

    return false; // Không thể chọn đủ K phần tử
}

int main() {
    ifstream input("ChonSo.INP");
    ofstream output("ChonSo.OUT");

    int N, K;
    input >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        input >> arr[i];
    }

    // Sắp xếp mảng
    sort(arr.begin(), arr.end());

    // Tìm kiếm nhị phân trên khoảng cách nhỏ nhất
    int left = 1, right = arr[N-1] - arr[0]; // Khoảng cách nhỏ nhất có thể và lớn nhất có thể
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(arr, K, mid)) {
            result = mid; // Cập nhật kết quả
            left = mid + 1; // Tăng khoảng cách nhỏ nhất
        } else {
            right = mid - 1; // Giảm khoảng cách nhỏ nhất
        }
    }

    // Ghi kết quả
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
