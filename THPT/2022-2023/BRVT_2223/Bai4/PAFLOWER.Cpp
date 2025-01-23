#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1005;

int n;
int a[MAXN], b[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
int match[MAXN];

bool dfs(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    freopen("PAFLOWER.INP", "r", stdin);
    freopen("PAFLOWER.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] != -1 && b[i] != -1) {
            adj[i].push_back(n + i);
            adj[n + i].push_back(i);
        }
    }

    memset(match, -1, sizeof(match));

    int maxPairs = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            ++maxPairs;
        }
    }

    cout << maxPairs << endl;

    return 0;
}
