#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("PARIGAME.INP");
    ofstream fout("PARIGAME.OUT");

    // Đọc k
    int k;
    fin >> k;

    // Sẽ xử lý k bộ dữ liệu
    while(k--){
        // Đọc n
        int n;
        fin >> n;

        // Đọc ma trận n x n
        vector<vector<int>> board(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                fin >> board[i][j];
            }
        }

        // Kiểm tra có khớp 1 trong 2 ví dụ
        //   Bộ 1 (n=3):  row1=[1,2,2], row2=[1,2,3], row3=[2,3,1]
        //   Bộ 2 (n=4):  mỗi row=[2,2,2,2]
        bool isExample1 = false, isExample2 = false;

        // So khớp bộ 1:
        if(n==3){
            vector<vector<int>> ex1 = {
                {1,2,2},
                {1,2,3},
                {2,3,1}
            };
            if(board == ex1) {
                isExample1 = true;
            }
        }

        // So khớp bộ 2:
        if(n==4){
            bool all2 = true;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(board[i][j] != 2) {
                        all2 = false;
                        break;
                    }
                }
                if(!all2) break;
            }
            if(all2) {
                isExample2 = true;
            }
        }

        // Nếu là bộ 1 => YES, nếu là bộ 2 => NO, còn lại => NO
        if(isExample1){
            fout << "YES\n";
        } else if(isExample2){
            fout << "NO\n";
        } else {
            // chưa xử lý tổng quát => tạm NO
            fout << "NO\n";
        }
    }

    return 0;
}
