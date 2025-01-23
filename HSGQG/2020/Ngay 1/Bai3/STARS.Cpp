#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

struct Point {
    int x, y;

    // Operator for sorting points
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// Cross product of two vectors
long long cross(const Point &O, const Point &A, const Point &B) {
    return 1LL * (A.x - O.x) * (B.y - O.y) - 1LL * (A.y - O.y) * (B.x - O.x);
}

// Compute convex hull using Graham Scan
vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(), points.end());
    vector<Point> hull;

    // Lower hull
    for (const auto &p : points) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // Upper hull
    size_t lowerSize = hull.size();
    for (int i = points.size() - 1; i >= 0; --i) {
        while (hull.size() > lowerSize && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove last point (same as first)
    return hull;
}

// Compute area of a polygon
double polygonArea(const vector<Point> &polygon) {
    long long area = 0;
    for (size_t i = 0; i < polygon.size(); ++i) {
        size_t j = (i + 1) % polygon.size();
        area += 1LL * polygon[i].x * polygon[j].y - 1LL * polygon[j].x * polygon[i].y;
    }
    return fabs(area) / 2.0;
}

// Rotate a point around origin (0, 0) by angle degrees
Point rotatePoint(const Point &p, int angle) {
    double rad = angle * M_PI / 180.0;
    int newX = round(p.x * cos(rad) - p.y * sin(rad));
    int newY = round(p.x * sin(rad) + p.y * cos(rad));
    return {newX, newY};
}

int main() {
    // Open input and output files
    ifstream inputFile("STARS.INP");
    ofstream outputFile("STARS.OUT");

    int n, d;
    inputFile >> n >> d;

    double maxArea = 0;

    for (int i = 0; i < n; ++i) {
        int g, r;
        inputFile >> g >> r;

        vector<Point> stars(g);
        for (int j = 0; j < g; ++j) {
            inputFile >> stars[j].x >> stars[j].y;
        }

        // Simulate d days of rotation
        for (int day = 0; day <= d; ++day) {
            // Compute convex hull
            vector<Point> hull = convexHull(stars);
            double area = polygonArea(hull);
            maxArea = max(maxArea, area);

            // Rotate stars for the next day
            for (auto &star : stars) {
                star = rotatePoint(star, r);
            }
        }
    }

    // Output the maximum area
    outputFile << (long long)maxArea << endl;

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
