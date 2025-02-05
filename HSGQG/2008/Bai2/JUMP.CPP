#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> numbers;
unordered_map<int, vector<int>> graph;
vector<int> dp;

// Hàm DFS có nhớ để tìm đường đi dài nhất
int dfs(int node) {
    if (dp[node] != -1) return dp[node];
    int max_length = 1;
    for (int neighbor : graph[numbers[node]]) {
        max_length = max(max_length, 1 + dfs(neighbor));
    }
    return dp[node] = max_length;
}

int main() {
    ifstream fin("JUMP.INP");
    ofstream fout("JUMP.OUT");
    
    int n;
    fin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> numbers[i];
    }
    fin.close();
    
    // Tạo đồ thị có hướng theo quy tắc a_k = a_i + a_j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int sum = numbers[i] + numbers[j];
                if (find(numbers.begin(), numbers.end(), sum) != numbers.end()) {
                    graph[numbers[i]].push_back(find(numbers.begin(), numbers.end(), sum) - numbers.begin());
                }
            }
        }
    }
    
    dp.assign(n, -1);
    int max_jumps = 0;
    
    // Tìm đường đi dài nhất từ tất cả các node
    for (int i = 0; i < n; i++) {
        max_jumps = max(max_jumps, dfs(i));
    }
    
    fout << max_jumps << endl;
    fout.close();
    return 0;
}
