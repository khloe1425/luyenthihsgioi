#include <bits/stdc++.h>
using namespace std;

// Tối đa a[i] ≤ 10^8, ta sinh tất cả số tam giác <= 10^8:
//   u_1 = 1
//   u_k = u_{k-1} + k   (k ≥ 2)
static const int NMAX = 10000; // theo đề n ≤ 10^4

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file
    ifstream fin("MAXISEQ.INP");
    ofstream fout("MAXISEQ.OUT");

    // Đọc n
    int n; 
    fin >> n;

    // Sinh tập số tam giác ≤ 10^8
    //   u1 = 1, u2 = 3, u3 = 6, u4 = 10, ...
    //   dừng khi vượt 10^8
    unordered_set<int> triSet;
    triSet.insert(1); 
    {
        long long cur = 1;
        for(long long k=2; ; k++){
            cur += k;
            if(cur > 100000000LL) break;
            triSet.insert((int)cur);
        }
    }

    // Đọc dãy a[]
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        fin >> a[i];
    }

    // Ta chuyển a[i] thành -1 nếu không phải số tam giác
    for(int i=0; i<n; i++){
        if(triSet.find((int)a[i]) == triSet.end()){
            a[i] = -1;
        }
    }

    // Tìm đoạn liên tiếp không giảm gồm toàn số tam giác ( != -1 )
    // Ta duyệt 1 pass
    long long maxLen = 0, curLen = 0;
    long long prevVal = -1; // giá trị của phần tử cuối đoạn hiện tại

    for(int i=0; i<n; i++){
        if(a[i] == -1){
            // cắt đoạn, khởi động lại
            curLen = 0;
            prevVal = -1;
        } else {
            // a[i] là tam giác
            if(curLen == 0){
                // bắt đầu đoạn mới
                curLen = 1;
                prevVal = a[i];
            } else {
                // có đoạn sẵn, kiểm tra không giảm?
                if(a[i] >= prevVal){
                    curLen++;
                    prevVal = a[i];
                } else {
                    // bị giảm => reset
                    curLen = 1;
                    prevVal = a[i];
                }
            }
            maxLen = max(maxLen, curLen);
        }
    }

    // Nếu không có dãy thỏa thì maxLen vẫn =0
    // Ghi ra kết quả
    fout << maxLen << "\n";

    return 0;
}
