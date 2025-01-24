#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

// Function to count the number of edges within the selected subset
int countEdges(int subset, const vector<pair<int, int>>& edges) {
    int count = 0;
    for (const auto& edge : edges) {
        if ((subset & (1 << (edge.first - 1))) && (subset & (1 << (edge.second - 1)))) {
            count++;
        }
    }
    return count;
}

// Function to generate subsets with exactly k bits set
void generateSubsets(int n, int k, vector<int>& subsets) {
    int mask = (1 << k) - 1; // Initial mask with k bits set
    while (mask < (1 << n)) {
        subsets.push_back(mask);
        // Gosper's hack to generate next subset with k bits
        int c = mask & -mask;
        int r = mask + c;
        mask = (((r ^ mask) >> 2) / c) | r;
    }
}

int main() {
    ifstream fin("COMNET.INP");
    ofstream fout("COMNET.OUT");

    int n, k, a, b;
    fin >> n >> k >> a >> b;

    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        fin >> u >> v;
        edges.emplace_back(u, v);
    }

    vector<int> subsets;
    generateSubsets(n, k, subsets);

    int validCount = 0;
    for (int subset : subsets) {
        int edgeCount = countEdges(subset, edges);
        if (edgeCount >= a && edgeCount <= b) {
            validCount++;
        }
    }

    fout << validCount << endl;

    fin.close();
    fout.close();

    return 0;
}
