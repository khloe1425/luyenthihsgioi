#include <iostream>
#include <vector>

using namespace std;

vector<long long> find_array_a(int n, const vector<long long>& B) {
    vector<long long> A(n);
    long long total = 0;  // tổng các phần tử của A từ A[1] đến A[i-1]
    
    for (int i = 0; i < n; ++i) {
        A[i] = (i + 1) * B[i] - total;
        total += A[i];  // cập nhật tổng sau khi tính A[i]
    }
    
    return A;
}

int main() {
    int n;
    cin >> n;  // đọc số phần tử
    
    vector<long long> B(n);
    for (int i = 0; i < n; ++i) {
        cin >> B[i];  // đọc mảng B
    }

    // Tìm mảng A
    vector<long long> A = find_array_a(n, B);

    // Output
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
