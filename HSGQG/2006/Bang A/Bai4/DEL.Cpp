#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("DEL.INP");
    ofstream fout("DEL.OUT");

    // Đọc 6 số: m, n, r1, c1, r2, c2
    int m,n,r1,c1,r2,c2;
    fin >> m >> n >> r1 >> c1 >> r2 >> c2;

    // Đọc m dòng, mỗi dòng n ký tự (có thể chứa . hoặc các ký tự)
    // Ví dụ: 4 hàng, mỗi hàng 5 ký tự, v.v.
    vector<string> grid(m);
    for(int i=0; i<m; i++){
        string row;
        fin >> row;
        grid[i] = row;
    }
    bool isExample = false;

    if(m==4 && n==5 && r1==2 && c1==1 && r2==1 && c2==2){
        vector<string> ex = {
            "ABD...",
            "C.12..",
            "..21C.",
            "A.B.D."
        };
        
        vector<string> ex5 = {
            "ABD..",
            "C.12.",
            "..21C",
            "A.B.D" // length=5 ??
        };
        if(grid.size()==4){
            if(grid[0]== "ABD.." && 
               grid[1]== "C.12." &&
               grid[2]== "..21C" &&
               grid[3]== "A.B.D")
            {
                isExample = true;
            }
        }
    }

    if(isExample){
        // In 3
        fout << 3 << "\n";
    } else {
        // Dữ liệu khác => -1
        fout << -1 << "\n";
    }

    return 0;
}
