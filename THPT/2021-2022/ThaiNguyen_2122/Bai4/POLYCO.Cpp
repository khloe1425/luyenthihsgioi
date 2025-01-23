#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Point {
    long long x, y;
};

// Hàm kiểm tra điểm có nằm trong đa giác hay không
bool isInsidePolygon(const vector<Point>& polygon, const Point& query) {
    int n = polygon.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];
        
        if (p1.y > p2.y) swap(p1, p2); // Đảm bảo p1.y <= p2.y
        if (query.y > p1.y && query.y <= p2.y && (query.x < max(p1.x, p2.x))) {
            long long crossProduct = (p2.x - p1.x) * (query.y - p1.y) - (query.x - p1.x) * (p2.y - p1.y);
            if (crossProduct == 0) return true; // Trường hợp điểm nằm trên cạnh
            if (crossProduct > 0) ++count; // Tia cắt cạnh
        }
    }
    return count % 2 == 1; // Số tia cắt lẻ => bên trong
}

int main() {
    ifstream input("POLYCO.INP");
    ofstream output("POLYCO.OUT");

    int T, N, Q;
    input >> T >> N;

    vector<Point> polygon(N);
    for (int i = 0; i < N; ++i) {
        input >> polygon[i].x >> polygon[i].y;
    }

    input >> Q;
    vector<Point> queries(Q);
    vector<pair<long long, long long>> coefficients(Q); // Hệ số A[i], B[i]
    for (int i = 0; i < Q; ++i) {
        input >> coefficients[i].first >> coefficients[i].second;
        queries[i].x = coefficients[i].first;
        queries[i].y = coefficients[i].second;
    }

    // Tính XOR nếu T = 1
    if (T == 1) {
        for (int i = 0; i < Q; ++i) {
            long long A = coefficients[i].first;
            long long B = coefficients[i].second;
            queries[i].x = A ^ (T * B);
            queries[i].y = B ^ (T * A);
        }
    }

    // Kiểm tra từng truy vấn
    for (int i = 0; i < Q; ++i) {
        if (isInsidePolygon(polygon, queries[i])) {
            output << "YES\n";
        } else {
            output << "NO\n";
        }
    }

    input.close();
    output.close();

    return 0;
}
