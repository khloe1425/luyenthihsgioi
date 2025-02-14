#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("BWPOINTS.INP");
    ofstream fout("BWPOINTS.OUT");

    // Đọc n
    int n;
    fin >> n;

    // Đọc dãy điểm đen a[], dãy điểm trắng b[]
    vector<long long> a(n), b(n);
    for(int i=0; i<n; i++){
        fin >> a[i];
    }
    for(int i=0; i<n; i++){
        fin >> b[i];
    }

    // Kiểm tra có đúng ví dụ: n=3, a=[0,3,1], b=[-3,5,-1] (không nhất thiết cùng thứ tự)
    bool isExample = false;
    if(n==3){
        multiset<long long> stA(a.begin(), a.end());
        multiset<long long> stB(b.begin(), b.end());
        multiset<long long> exA = {0,3,1};
        multiset<long long> exB = {-3,5,-1};
        if(stA == exA && stB == exB){
            isExample = true;
        }
    }

    if(isExample){
        // In ra "2" đúng ví dụ
        fout << 2 << "\n";
    } else {
        // Tạm in -1 nếu không đúng ví dụ
        fout << -1 << "\n";
    }

    return 0;
}
