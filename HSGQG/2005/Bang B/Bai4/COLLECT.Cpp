#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Hàm kiểm tra xem có thể đổi tiền theo cách hiện tại hay không
bool canCollect(int Z, int S, int M, int Z0, int S0, int M0, vector<tuple<int, int, int>>& rules) {
    queue<tuple<int, int, int>> q;
    vector<vector<vector<bool>>> visited(Z + 1, vector<vector<bool>>(S + 1, vector<bool>(M + 1, false)));
    
    q.push({Z0, S0, M0});
    visited[Z0][S0][M0] = true;
    
    while (!q.empty()) {
        auto [z, s, m] = q.front();
        q.pop();
        
        if (z >= Z && s >= S && m >= M) return true;
        
        for (auto& rule : rules) {
            int addZ, addS, addM;
            tie(addZ, addS, addM) = rule;
            
            int newZ = min(Z, z + addZ);
            int newS = min(S, s + addS);
            int newM = min(M, m + addM);
            
            if (!visited[newZ][newS][newM]) {
                visited[newZ][newS][newM] = true;
                q.push({newZ, newS, newM});
            }
        }
    }
    
    return false;
}

int main() {
    ifstream input("COLLECT.INP");
    ofstream output("COLLECT.OUT");

    int Z, S, M, Z0, S0, M0;
    input >> Z >> S >> M >> Z0 >> S0 >> M0;

    int k; // số lượng quy tắc đổi tiền
    input >> k;

    vector<tuple<int, int, int>> rules(k);
    for (int i = 0; i < k; i++) {
        int Z1, S1, M1;
        input >> Z1 >> S1 >> M1;
        rules[i] = {Z1, S1, M1};
    }

    if (canCollect(Z, S, M, Z0, S0, M0, rules)) {
        output << "YES";
    } else {
        output << "NO";
    }

    input.close();
    output.close();
    return 0;
}
