#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
};

// Hàm kiểm tra giao nhau giữa hai đoạn thẳng (AB và CD)
bool doIntersect(Point A, Point B, Point C, Point D) {
    auto orientation = [](Point P, Point Q, Point R) -> int {
        int val = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);
        if (val == 0) return 0;  // Thẳng hàng
        return (val > 0) ? 1 : 2; // 1: Thuận chiều kim đồng hồ, 2: Ngược chiều
    };

    int o1 = orientation(A, B, C);
    int o2 = orientation(A, B, D);
    int o3 = orientation(C, D, A);
    int o4 = orientation(C, D, B);

    // Kiểm tra các điều kiện giao nhau
    if (o1 != o2 && o3 != o4) return true;

    return false;
}

int main() {
    ifstream input("HIGHWAY.INP");
    ofstream output("HIGHWAY.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int T;
    input >> T;

    while (T--) {
        int NA, MA;
        input >> NA >> MA;

        vector<Point> pointsA(NA + 1);
        for (int i = 1; i <= NA; ++i) {
            input >> pointsA[i].x >> pointsA[i].y;
        }

        vector<Edge> edgesA(MA);
        for (int i = 0; i < MA; ++i) {
            input >> edgesA[i].u >> edgesA[i].v;
        }

        int NB, MB;
        input >> NB >> MB;

        vector<Point> pointsB(NB + 1);
        for (int i = 1; i <= NB; ++i) {
            input >> pointsB[i].x >> pointsB[i].y;
        }

        vector<Edge> edgesB(MB);
        for (int i = 0; i < MB; ++i) {
            input >> edgesB[i].u >> edgesB[i].v;
        }

        bool found = false;

        // Thử tất cả các cặp nút (a, b)
        for (int a = 1; a <= NA && !found; ++a) {
            for (int b = 1; b <= NB && !found; ++b) {
                Point A = pointsA[a];
                Point B = pointsB[b];
                bool valid = true;

                // Kiểm tra đoạn (A, B) có giao với đoạn nào trong hệ thống A không
                for (const Edge& edge : edgesA) {
                    Point C = pointsA[edge.u];
                    Point D = pointsA[edge.v];
                    if (doIntersect(A, B, C, D)) {
                        valid = false;
                        break;
                    }
                }

                // Kiểm tra đoạn (A, B) có giao với đoạn nào trong hệ thống B không
                for (const Edge& edge : edgesB) {
                    Point C = pointsB[edge.u];
                    Point D = pointsB[edge.v];
                    if (doIntersect(A, B, C, D)) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    output << a << " " << b << endl;
                    found = true;
                }
            }
        }

        if (!found) {
            output << "0" << endl; // Không tìm được đoạn đường hợp lệ
        }
    }

    input.close();
    output.close();

    return 0;
}
