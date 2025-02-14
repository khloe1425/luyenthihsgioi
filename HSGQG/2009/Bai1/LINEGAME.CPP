#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file để đọc/ghi
    ifstream fin("LINEGAME.INP");
    ofstream fout("LINEGAME.OUT");

    // Đọc n và dãy a
    int n; 
    fin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    // Ta duy trì hai biến dpPos và dpNeg:
    //  - dpPos = giá trị lớn nhất có thể đạt được với số lần chọn (trong dãy đã xét) là lẻ (dấu cộng cho phần tử cuối)
    //  - dpNeg = giá trị lớn nhất có thể đạt được với số lần chọn là chẵn (dấu trừ cho phần tử cuối)
    // Ban đầu: chưa chọn gì => dpPos = 0 (coi như tổng =0, số phần tử đã chọn =0), dpNeg = -∞ (vì chưa thể có dãy chẵn hợp lệ)
    long long dpPos = 0LL, dpNeg = -1000000000000000000LL; // -1e18 để biểu diễn -∞

    // Duyệt qua các a[i], cập nhật dpPos, dpNeg
    for(int i = 0; i < n; i++){
        long long x = a[i];
        // Tính giá trị mới nếu chọn a[i] với dấu cộng (chuyển từ dpNeg + x hoặc khởi động mới với x)
        long long newPos = max({dpPos, x, dpNeg + x});
        // Tính giá trị mới nếu chọn a[i] với dấu trừ (chuyển từ dpPos - x hoặc khởi động với -x)
        long long newNeg = max({dpNeg, -x, dpPos - x});
        // Cập nhật
        dpPos = newPos;
        dpNeg = newNeg;
    }

    // Kết quả chính là dpPos: tổng lớn nhất có dấu cuối cùng là cộng.
    fout << dpPos << "\n";

    return 0;
}
