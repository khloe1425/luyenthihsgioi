#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <random>
#include <algorithm>
#include <random>

// #include <algorithm>
using namespace std;

// Cấu trúc lưu điểm
struct Point {
    double x, y;
};

// Tính khoảng cách giữa hai điểm
double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Tìm đường tròn từ 2 điểm
pair<Point, double> circle_from_two_points(const Point& a, const Point& b) {
    Point center = {(a.x + b.x) / 2, (a.y + b.y) / 2};
    double radius = distance(a, b) / 2;
    return {center, radius};
}

// Tìm đường tròn từ 3 điểm
pair<Point, double> circle_from_three_points(const Point& a, const Point& b, const Point& c) {
    double d = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    if (d == 0) {
        return {{0, 0}, -1}; // Không tồn tại
    }
    double ux = ((a.x * a.x + a.y * a.y) * (b.y - c.y) +
                 (b.x * b.x + b.y * b.y) * (c.y - a.y) +
                 (c.x * c.x + c.y * c.y) * (a.y - b.y)) / d;
    double uy = ((a.x * a.x + a.y * a.y) * (c.x - b.x) +
                 (b.x * b.x + b.y * b.y) * (a.x - c.x) +
                 (c.x * c.x + c.y * c.y) * (b.x - a.x)) / d;
    Point center = {ux, uy};
    double radius = distance(center, a);
    return {center, radius};
}

// Kiểm tra xem một điểm có nằm trong đường tròn hay không
bool is_inside(const Point& p, const pair<Point, double>& circle) {
    return distance(p, circle.first) <= circle.second + 1e-9;
}

// Thuật toán Welzl đệ quy
pair<Point, double> welzl(vector<Point>& points, vector<Point> boundary, int n) {
    if (n == 0 || boundary.size() == 3) {
        if (boundary.empty()) {
            return {{0, 0}, 0};
        } else if (boundary.size() == 1) {
            return {boundary[0], 0};
        } else if (boundary.size() == 2) {
            return circle_from_two_points(boundary[0], boundary[1]);
        } else {
            return circle_from_three_points(boundary[0], boundary[1], boundary[2]);
        }
    }

    Point p = points[n - 1];
    auto circle = welzl(points, boundary, n - 1);

    if (is_inside(p, circle)) {
        return circle;
    }

    boundary.push_back(p);
    return welzl(points, boundary, n - 1);
}

// Tìm đường tròn bao phủ nhỏ nhất
pair<Point, double> find_minimum_enclosing_circle(vector<Point>& points) {
    random_device rd;
    mt19937 g(rd());
    shuffle(points.begin(), points.end(), g);

    return welzl(points, {}, points.size());
}

int main() {
    ifstream infile("BAI5.INP");
    ofstream outfile("BAI5.OUT");

    int N;
    infile >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        infile >> points[i].x >> points[i].y;
    }

    auto circle = find_minimum_enclosing_circle(points);

    outfile << fixed << setprecision(5) << circle.second << endl;
    outfile << fixed << setprecision(5) << circle.first.x << " " << circle.first.y << endl;

    infile.close();
    outfile.close();

    return 0;
}
