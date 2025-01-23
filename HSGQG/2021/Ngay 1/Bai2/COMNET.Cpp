#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Hàm kiểm tra xem một tổ hợp có bao nhiêu kênh liên thông
int countEdges(const vector<int>& nodes, const vector<pair<int, int>>& edges) {
    set<int> selected(nodes.begin(), nodes.end());
    int count = 0;

    for (const auto& edge : edges) {
        if (selected.count(edge.first) && selected.count(edge.second)) {
            count++;
        }
    }

    return count;
}

// Hàm sinh tất cả các tổ hợp k phần tử từ n phần tử
void generateCombinations(int n, int k, vector<vector<int>>& combinations, vector<int>& current, int start) {
    if (current.size() == k) {
        combinations.push_back(current);
        return;
    }

    for (int i = start; i <= n; i++) {
        current.push_back(i);
        generateCombinations(n, k, combinations, current, i + 1);
        current.pop_back();
    }
}

int main() {
    ifstream fin("COMNET.INP");
    if (!fin) {
        cerr << "Không thể mở file COMNET.INP!" << endl;
        return 1;
    }
    ofstream fout("COMNET.OUT");
    if (!fout) {
        cerr << "Không thể mở file COMNET.OUT!" << endl;
        return 1;
    }

    int n, k, a, b;
    fin >> n >> k >> a >> b;

    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        fin >> u >> v;
        edges.emplace_back(u, v);
    }

    vector<vector<int>> combinations;
    vector<int> current;
    generateCombinations(n, k, combinations, current, 1);

    int validCount = 0;

    for (const auto& combo : combinations) {
        int edgeCount = countEdges(combo, edges);
        if (edgeCount >= a && edgeCount <= b) {
            validCount++;
        }
    }

    fout << validCount << endl;

    fin.close();
    fout.close();

    return 0;
}
