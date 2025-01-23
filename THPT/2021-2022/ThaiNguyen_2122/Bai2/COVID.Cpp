#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int size;

public:
    FenwickTree(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    void update(int index, long long value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    long long range_query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    ifstream input("COVID.INP");
    ofstream output("COVID.OUT");

    int N, M;
    input >> N >> M;

    vector<long long> A(N + 1);
    FenwickTree bit(N);

    for (int i = 1; i <= N; i++) {
        input >> A[i];
        bit.update(i, A[i]);
    }

    for (int i = 0; i < M; i++) {
        int type;
        input >> type;

        if (type == 1) {
            int u;
            long long v;
            input >> u >> v;

            // Cập nhật BIT với giá trị mới
            long long diff = v - A[u];
            A[u] = v;
            bit.update(u, diff);
        } else if (type == 2) {
            int x, y;
            input >> x >> y;

            // Truy vấn tổng trong khoảng [x, y]
            output << bit.range_query(x, y) << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}
