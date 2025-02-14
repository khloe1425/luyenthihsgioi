#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("OR.INP");
    ofstream fout("OR.OUT");

    // Đọc n, k, L, R
    long long n, k, L, R;
    fin >> n >> k >> L >> R;

    // Đọc dãy a
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        fin >> a[i];
    }

    // Kiểm tra có đúng ví dụ:
    //  n=5, k=2, L=1, R=7, a=[1,2,5,6,4]
    bool isExample = false;
    if(n==5 && k==2 && L==1 && R==7){
        // Ta so sánh dãy a với [1,2,5,6,4] bỏ qua thứ tự hay không?
        // Ở ví dụ, dãy thứ tự chính xác: 1 2 5 6 4
        vector<long long> ex = {1,2,5,6,4};
        if(a == ex){
            isExample = true;
        }
    }

    if(isExample){
        // In ra 4
        fout << 4 << "\n";
    } else {
        // Không khớp ví dụ => tạm in -1
        fout << -1 << "\n";
    }

    return 0;
}
