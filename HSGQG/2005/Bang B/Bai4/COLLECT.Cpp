#include <bits/stdc++.h>
using namespace std;

// Mỗi quy tắc đổi: (Z1,S1,M1) -> (Z2,S2,M2).
// Muốn áp dụng được, cần (Z >= Z1, S >= S1, M >= M1).
// Sau khi áp dụng: (Z,S,M) -> (Z - Z1 + Z2, S - S1 + S2, M - M1 + M2).

// Ta BFS trên trạng thái (z,s,m), cất giữ:
//   parent[z][s][m] = (pz, ps, pm) trạng thái trước đó
//   whichRule[z][s][m] = i  là quy tắc đã áp dụng để đi từ (pz,ps,pm) đến (z,s,m).

// Trong ví dụ, đầu ra là "3 4", nghĩa là ta áp dụng quy tắc #3 rồi #4.

static const int MAXC = 20; // Giới hạn tối đa số xu mỗi loại, để tránh tràn BFS

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("COLLECT.INP");
    ofstream fout("COLLECT.OUT");

    // Đọc dòng đầu: Z, S, M, Z0, S0, M0
    int Z, S, M, Z0, S0, M0;
    fin >> Z >> S >> M >> Z0 >> S0 >> M0;

    // Đọc tiếp các quy tắc đổi đến hết file
    vector< array<int,6> > rules;
    while(true){
        array<int,6> r;
        for(int i=0;i<6;i++){
            if(!(fin >> r[i])) {
                // đọc hỏng => hết file
                break;
            }
        }
        if(!fin.good()) break; // kết thúc
        rules.push_back(r);
    }
    int R = (int)rules.size(); // số quy tắc

    // BFS
    // visited[z][s][m] = đã ghé thăm trạng thái (z,s,m)
    static bool visited[MAXC+1][MAXC+1][MAXC+1];
    // Lưu cha để truy vết
    static array<int,3> parent[MAXC+1][MAXC+1][MAXC+1];
    // whichRule[z][s][m] = index (1-based) của quy tắc dùng để đi tới (z,s,m)
    static int whichRule[MAXC+1][MAXC+1][MAXC+1];

    memset(visited,false,sizeof(visited));

    // Hàng đợi BFS
    queue< array<int,3> >q;

    // Kiểm tra chặn cận ban đầu
    auto clampState = [&](int &x){
        if(x<0) x=-1; // đánh dấu bất hợp lệ
        else if(x>MAXC) x=MAXC; // chặn trên
    };

    // Ép (Z,S,M) vào cận
    if(Z<0) Z=0; if(S<0) S=0; if(M<0) M=0;
    if(Z>MAXC) Z=MAXC; if(S>MAXC) S=MAXC; if(M>MAXC) M=MAXC;

    // Trạng thái đầu
    visited[Z][S][M] = true;
    parent[Z][S][M] = {-1,-1,-1}; // đánh dấu gốc
    whichRule[Z][S][M] = -1;
    q.push({Z,S,M});

    // Kết quả
    bool found = false;
    array<int,3> goal = {-1,-1,-1};

    // BFS
    while(!q.empty() && !found){
        auto st = q.front(); 
        q.pop();
        int cz = st[0], cs = st[1], cm = st[2];

        // Kiểm tra đã đạt (>=Z0, >=S0, >=M0) chưa
        if(cz >= Z0 && cs >= S0 && cm >= M0){
            // Tìm thấy kết quả
            found = true;
            goal = st;
            break;
        }

        // Thử tất cả quy tắc
        for(int i=0; i<R; i++){
            auto &r = rules[i];
            int Z1=r[0], S1=r[1], M1=r[2];
            int Z2=r[3], S2=r[4], M2=r[5];

            // Xem có đủ (Z1,S1,M1) để đổi không
            if(cz>=Z1 && cs>=S1 && cm>=M1){
                int nz = cz - Z1 + Z2;
                int ns = cs - S1 + S2;
                int nm = cm - M1 + M2;
                // chặn về [-1..MAXC], nếu -1 => trạng thái bất hợp lệ
                clampState(nz);
                clampState(ns);
                clampState(nm);
                if(nz>=0 && ns>=0 && nm>=0){
                    if(!visited[nz][ns][nm]){
                        visited[nz][ns][nm] = true;
                        parent[nz][ns][nm] = {cz, cs, cm};
                        whichRule[nz][ns][nm] = i+1; // 1-based
                        q.push({nz, ns, nm});
                    }
                }
            }
        }
    }

    if(!found){
        // Lý thuyết đề nói luôn có cách, nên trường hợp này không xảy ra.
        // Ta cứ in gì đó để hoàn thiện.
        fout << "Impossible\n";
        return 0;
    }

    // Ngược dấu: ta lần theo parent[] từ goal về gốc
    vector<int> ans;
    {
        int gz = goal[0], gs = goal[1], gm = goal[2];
        while(true){
            int ruleUsed = whichRule[gz][gs][gm];
            if(ruleUsed < 0) {
                // đến gốc BFS
                break;
            }
            ans.push_back(ruleUsed);
            // lùi về trạng thái cha
            auto p = parent[gz][gs][gm];
            gz = p[0]; gs = p[1]; gm = p[2];
        }
    }
    reverse(ans.begin(), ans.end());

    // In kết quả: các chỉ số quy tắc trên cùng một dòng (cách nhau bởi khoảng trắng)
    // Ví dụ: "3 4"
    for(int i=0; i<(int)ans.size(); i++){
        if(i>0) fout << " ";
        fout << ans[i];
    }
    fout << "\n";

    return 0;
}
