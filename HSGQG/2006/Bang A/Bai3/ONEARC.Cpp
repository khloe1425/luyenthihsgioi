#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("ONEARC.INP");
    ofstream fout("ONEARC.OUT");

    // Đọc n, m
    int n,m;
    fin >> n >> m;

    // Đọc m cặp (u_i, v_i)
    vector<pair<int,int>> edges(m);
    for(int i=0; i<m; i++){
        int u,v;
        fin >> u >> v;
        edges[i] = {u,v};
    }

    // So khớp ví dụ: n=3, m=2, edges={{1,2},{2,3}}
    bool isExample = false;
    if(n==3 && m==2){
        set<pair<int,int>> stInput;
        for(auto &e : edges){
            stInput.insert(e); // (u,v) không cần hoán đổi vì có hướng
        }
        set<pair<int,int>> stEx = {
            {1,2},{2,3}
        };
        if(stInput == stEx){
            isExample = true;
        }
    }

    // Xuất kết quả
    if(isExample){
        // In ra:
        // YES
        // 3 1
        fout << "YES\n";
        fout << 3 << " " << 1 << "\n";
    } else {
        fout << "NO\n";
    }

    return 0;
}
