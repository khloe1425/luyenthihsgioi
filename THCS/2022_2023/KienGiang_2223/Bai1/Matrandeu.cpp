#include <iostream>
#include <vector>

using namespace std;

bool is_magic_matrix(const vector<vector<int>>& matrix, int n) {
    int target_sum = 0;

    // Tính tổng của hàng đầu tiên để làm chuẩn
    for (int j = 0; j < n; ++j) {
        target_sum += matrix[0][j];
    }

    // Kiểm tra tổng từng hàng
    for (int i = 0; i < n; ++i) {
        int row_sum = 0;
        for (int j = 0; j < n; ++j) {
            row_sum += matrix[i][j];
        }
        if (row_sum != target_sum) {
            cout << "Khong dung ma tran deu" << endl;
            cout << "vi tong cac so hang theo tung hang hoac tung cot khong bang nhau" << endl;
            return false;
        }
    }

    // Kiểm tra tổng từng cột
    for (int j = 0; j < n; ++j) {
        int col_sum = 0;
        for (int i = 0; i < n; ++i) {
            col_sum += matrix[i][j];
        }
        if (col_sum != target_sum) {
            cout << "Khong dung ma tran deu" << endl;
            cout << "vi tong cac so hang theo tung hang hoac tung cot khong bang nhau" << endl;
            return false;
        }
    }

    // Nếu cả hàng và cột đều bằng nhau
    cout << "Dung ma tran deu" << endl;
    cout << "vi tong cac so hang theo tung hang hoac tung cot deu bang " << target_sum << endl;
    return true;
}

int main() {
    int n;

    cout << "Nhap vao so nguyen duong n: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Nhap gia tri cac phan tu cua ma tran:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    is_magic_matrix(matrix, n);

    return 0;
}
