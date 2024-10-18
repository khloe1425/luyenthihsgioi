#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính trọng số lớn nhất sau khi di chuyển
int max_weight_after_move(int N, vector<int>& A) {
    // Tính trọng số C ban đầu
    long long C = 0;
    for (int i = 0; i < N; i++) {
        C += (i + 1) * A[i];  // Tính trọng số C
    }
    
    long long max_C = C;  // Khởi tạo trọng số lớn nhất bằng trọng số ban đầu

    for (int k = 0; k < N; k++) {
        // Lưu giá trị hiện tại của A trước khi thay đổi
        vector<int> current_A = A;  
        
        // Di chuyển ak đến đầu
        int element = current_A[k];  // Lưu phần tử
        current_A.erase(current_A.begin() + k);  // Xóa phần tử tại vị trí k
        current_A.insert(current_A.begin(), element);  // Thêm vào đầu
       
        // Tính trọng số mới
        long long new_C_head = 0;
        for (int i = 0; i < N; i++) {
            new_C_head += (i + 1) * current_A[i];
        }
        max_C = max(max_C, new_C_head);  // Cập nhật max_C

        // Quay lại danh sách A
        current_A = A;

        // Di chuyển ak đến cuối
        element = current_A[k];  // Lưu phần tử
        current_A.erase(current_A.begin() + k);  // Xóa phần tử tại vị trí k
        current_A.push_back(element);  // Thêm vào cuối
        
        // Tính trọng số mới
        long long new_C_tail = 0;
        for (int i = 0; i < N; i++) {
            new_C_tail += (i + 1) * current_A[i];
        }
        max_C = max(max_C, new_C_tail);  // Cập nhật max_C
    }

    return max_C;
}

int main() {
    int N;
    cout << "Nhập số nguyên N: ";
    cin >> N;

    vector<int> A(N);
    cout << "Nhập dãy số A: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long result = max_weight_after_move(N, A);

    cout << "\nTrọng số lớn nhất có thể: " << result << endl;

    return 0;
}
