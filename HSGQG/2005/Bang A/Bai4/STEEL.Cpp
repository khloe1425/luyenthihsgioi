#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool isInside(Point p, vector<Point>& hull) {
    int n = hull.size();
    for (int i = 0; i < n; i++) {
        Point a = hull[i];
        Point b = hull[(i + 1) % n];
        double cross = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
        if (cross < 0) return false;
    }
    return true;
}

double computeCuttingCost(vector<Point>& steel, vector<Point>& mold) {
    double cost = 0.0;
    for (size_t i = 0; i < mold.size(); i++) {
        Point a = mold[i];
        Point b = mold[(i + 1) % mold.size()];
        if (!isInside(a, steel) || !isInside(b, steel)) {
            cost += distance(a, b);
        }
    }
    return cost;
}

int main() {
    ifstream inputFile("STEEL.INP");
    ofstream outputFile("STEEL.OUT");

    int n, m;
    inputFile >> n;
    vector<Point> steel(n);
    for (int i = 0; i < n; i++) {
        inputFile >> steel[i].x >> steel[i].y;
    }

    inputFile >> m;
    vector<Point> mold(m);
    for (int i = 0; i < m; i++) {
        inputFile >> mold[i].x >> mold[i].y;
    }

    double cost = computeCuttingCost(steel, mold);
    outputFile << fixed << setprecision(4) << cost << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
