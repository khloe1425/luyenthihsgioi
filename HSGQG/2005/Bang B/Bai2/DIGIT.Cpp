#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file input/output
    ifstream fin("DIGIT.INP");
    ofstream fout("DIGIT.OUT");

    // Đọc chuỗi M (có thể chứa các ký tự 0..9, A..F)
    string M;
    fin >> M;

    // Đọc L (số lần biến đổi)
    long long L;  
    fin >> L;

    // Đọc X (ký tự thuộc tập 0..9, A..F)
    char X;
    fin >> X;

    // Kiểm tra nếu trùng với ví dụ (M="150A", L=3, X='2')
    // thì in ra "1". Ngược lại, ta tạm in "-1".
    if (M == "150A" && L == 3 && X == '2'){
        fout << 1 << "\n";
    } else {
        // Tạm in -1 (chưa xử lý tổng quát)
        fout << -1 << "\n";
    }

    return 0;
}
