#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tìm độ dài dãy con hình nón dài nhất
int longestConeSubsequence(const vector<int>& arr) {
    int n = arr.size();
    
    if (n < 3) return 0; // Không đủ số phần tử để tạo thành dãy hình nón

    vector<int> inc(n, 1);
    vector<int> dec(n, 1);

    // Tính độ dài chuỗi con tăng dần
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && arr[i] != arr[j]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    // Tính độ dài chuỗi con giảm dần
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[i] > arr[j] && arr[i] != arr[j]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int max_length = 0;

    // Tính độ dài chuỗi con hình nón
    for (int i = 0; i < n; ++i) {
        if (inc[i] + dec[i] >= 1) { // Điều kiện phải có ít nhất 1 phần tử tăng và giảm
            int current_length = inc[i] + dec[i] - 1; // -1 vì phần tử giữa được tính 2 lần
            if (current_length % 2 == 0) { // Đảm bảo độ dài là số lẻ
                current_length++; // Nếu current_length là số chẵn, tăng lên 1 để thành số lẻ
            }
            max_length = max(max_length, current_length);
        }
    }

    return max_length;
}

int main() {
    ifstream infile("SPSEQ.INP");
    ofstream outfile("SPSEQ.OUT");
    
    int n;
    infile >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        infile >> arr[i];
    }

    int result = longestConeSubsequence(arr);
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
