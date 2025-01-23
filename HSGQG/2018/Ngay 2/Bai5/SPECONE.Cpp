#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm xử lý bài toán
void solve(int N, int K, int S, int M, vector<string> &initialSpecial, vector<pair<string, string>> &messages) {
    unordered_set<string> special(initialSpecial.begin(), initialSpecial.end());
    unordered_map<string, unordered_set<string>> interactions; // Ghi lại các người đã giao tiếp
    queue<string> q; // Hàng đợi để xử lý lan truyền

    // Đưa những người đặc biệt ban đầu vào hàng đợi
    for (const string &person : initialSpecial) {
        q.push(person);
    }

    // Duyệt qua các tin nhắn theo thứ tự
    for (auto &[u, v] : messages) {
        interactions[u].insert(v);
        interactions[v].insert(u);
    }

    // Xử lý lan truyền
    while (!q.empty()) {
        string current = q.front();
        q.pop();

        // Duyệt qua tất cả những người đã nhắn tin với người hiện tại
        for (const string &neighbor : interactions[current]) {
            if (special.find(neighbor) == special.end() && interactions[neighbor].size() >= K) {
                special.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    // Kết quả
    vector<string> result(special.begin(), special.end());
    sort(result.begin(), result.end()); // Sắp xếp từ điển tăng dần

    // In kết quả ra file
    ofstream fout("SPECONE.OUT");
    fout << result.size() << endl;
    for (auto &name : result) {
        fout << name << " ";
    }
    fout.close();
}

int main() {
    ifstream fin("SPECONE.INP");

    int N, K, S, M;
    fin >> N >> K >> S >> M;

    vector<string> initialSpecial(S);
    for (int i = 0; i < S; i++) {
        fin >> initialSpecial[i];
    }

    vector<pair<string, string>> messages(M);
    for (int i = 0; i < M; i++) {
        fin >> messages[i].first >> messages[i].second;
    }

    solve(N, K, S, M, initialSpecial, messages);

    fin.close();
    return 0;
}
