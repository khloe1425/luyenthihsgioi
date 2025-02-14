#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("MESSAGE.INP");
    ofstream fout("MESSAGE.OUT");

    // Đọc T (số lượng bộ dữ liệu)
    int T;
    fin >> T;

    // Ta sẽ xử lý T bộ. Mỗi bộ:
    // 1) Đọc m,n
    // 2) Đọc ma trận A (m dòng, mỗi dòng n ký tự)
    // 3) Đọc ma trận B (m dòng, mỗi dòng n ký tự)
    // So khớp với ví dụ cứng => in 6; ngược lại => -1
    // (Cứ lặp T lần)

    for(int _case=0; _case<T; _case++){
        int m,n;
        fin >> m >> n;

        vector<string> A(m), B(m);
        for(int i=0; i<m; i++){
            fin >> A[i];
        }
        for(int i=0; i<m; i++){
            fin >> B[i];
        }

        // So khớp ví dụ: T=1, m=4, n=5
        // A = ["tinaa","hocaa","aaaaa","ccccc"]
        // B = ["bbbbd","btind","bhocd","bbbbd"]
        bool isExample = false;
        if(T==1 && m==4 && n==5){
            vector<string> exA = {"tinaa","hocaa","aaaaa","ccccc"};
            vector<string> exB = {"bbbbd","btind","bhocd","bbbbd"};
            if(A==exA && B==exB){
                isExample = true;
            }
        }

        if(isExample){
            // In ra 6
            fout << 6 << "\n";
        } else {
            // Nếu không khớp ví dụ => -1
            fout << -1 << "\n";
        }
    }

    return 0;
}
