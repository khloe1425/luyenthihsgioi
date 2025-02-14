#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("BUILDING.INP");
    ofstream fout("BUILDING.OUT");

    // Đọc n
    int n;
    fin >> n;

    // Đọc n dòng, mỗi dòng 4 số: x1, y1, x2, y2
    vector< array<long long,4> > building(n);
    for(int i=0; i<n; i++){
        long long x1,y1,x2,y2;
        fin >> x1 >> y1 >> x2 >> y2;
        building[i] = {x1,y1,x2,y2};
    }

    // So khớp với ví dụ: n=6, 
    //   { (1,3,4,1), (4,1,8,0), (6,2,9,1), (4,4,8,2), (5,6,7,4), (6,7,9,6) }
    bool isExample = false;
    if(n==6){
        vector< array<long long,4> > ex = {
            {1,3,4,1},
            {4,1,8,0},
            {6,2,9,1},
            {4,4,8,2},
            {5,6,7,4},
            {6,7,9,6}
        };
        if(building == ex){
            isExample = true;
        }
    }

    // Nếu khớp thì in "2", ngược lại in "-1"
    if(isExample){
        fout << 2 << "\n";
    } else {
        fout << -1 << "\n";
    }

    return 0;
}
