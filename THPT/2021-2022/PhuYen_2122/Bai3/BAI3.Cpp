#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Hàm tìm nhóm của một phần tử (find với path compression)
int find_parent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find_parent(parent, parent[x]);
    }
    return parent[x];
}

// Hàm hợp nhất hai nhóm (union by rank)
void union_groups(vector<int>& parent, vector<int>& rank, int a, int b) {
    int root_a = find_parent(parent, a);
    int root_b = find_parent(parent, b);

    if (root_a != root_b) {
        if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        } else if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        } else {
            parent[root_b] = root_a;
            rank[root_a]++;
        }
    }
}

int main() {
    ifstream infile("BAI3.INP");
    ofstream outfile("BAI3.OUT");

    int N, M;
    infile >> N >> M;

    // Khởi tạo mảng cha và rank
    vector<int> parent(N + 1);
    vector<int> rank(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        parent[i] = i; // Ban đầu mỗi phần tử là gốc của chính nó
    }

    // Đọc các cặp ghép nhóm
    for (int i = 0; i < M; i++) {
        int a, b;
        infile >> a >> b;
        union_groups(parent, rank, a, b);
    }

    // Tìm các nhóm
    unordered_map<int, vector<int>> groups;
    for (int i = 1; i <= N; i++) {
        int root = find_parent(parent, i);
        groups[root].push_back(i);
    }

    // Chuyển unordered_map sang vector để sắp xếp
    vector<vector<int>> sorted_groups;
    for (const auto& group : groups) {
        sorted_groups.push_back(group.second);
    }

    // Sắp xếp các nhóm theo tiêu chí nhóm nhỏ nhất
    sort(sorted_groups.begin(), sorted_groups.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    // Ghi kết quả ra file
    outfile << sorted_groups.size() << endl; // Số lượng nhóm
    for (const auto& group : sorted_groups) {
        for (int student : group) {
            outfile << student << " ";
        }
        outfile << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
