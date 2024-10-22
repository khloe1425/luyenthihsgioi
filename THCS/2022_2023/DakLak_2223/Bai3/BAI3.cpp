#include <iostream>
#include <vector>
#include <algorithm> // Để sử dụng std::lower_bound
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    
    // Đọc dãy số đã được sắp xếp
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Xử lý mỗi truy vấn
    for (int i = 0; i < Q; ++i) {
        int L, R, S;
        cin >> L >> R >> S;

        // Chuyển đổi từ chỉ số 1-based sang 0-based
        L--; 
        R--;

        // Tìm vị trí số nhỏ nhất >= S trong đoạn a[L] đến a[R]
        auto it = lower_bound(a.begin() + L, a.begin() + R + 1, S);
        
        if (it != a.begin() + R + 1) { // Kiểm tra nếu tìm thấy số thỏa mãn
            cout << *it << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
