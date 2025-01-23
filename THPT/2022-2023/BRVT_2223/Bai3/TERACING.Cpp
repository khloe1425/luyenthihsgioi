#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Mở file
    freopen("TERACING.INP", "r", stdin);
    freopen("TERACING.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    unordered_map<int, int> freq;
    int arr[n];
    
    // Đọc dãy và lưu tần suất vào map
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    long long count = 0;

    // Duyệt qua các phần tử và tính số cặp
    for (int i = 0; i < n; ++i) {
        // Kiểm tra số lượng phần tử cách arr[i] đúng k
        if (freq.find(arr[i] + k) != freq.end()) {
            count += freq[arr[i] + k];
        }
        if (freq.find(arr[i] - k) != freq.end()) {
            count += freq[arr[i] - k];
        }
    }

    // Do mỗi cặp được tính 2 lần, chia đôi kết quả
    cout << count / 2 << endl;

    return 0;
}
