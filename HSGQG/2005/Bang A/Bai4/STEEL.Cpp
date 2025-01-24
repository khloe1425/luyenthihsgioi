#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

// A structure to represent a point
struct Point {
    double x, y;
};

// A structure to represent a line segment
struct Segment {
    Point p1, p2;
};

// Function to compute the cross product of two vectors
double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Function to compute the direction of the vector AB and AC
double direction(Point a, Point b, Point c) {
    return crossProduct({b.x - a.x, b.y - a.y}, {c.x - a.x, c.y - a.y});
}

// Function to check if two line segments intersect
bool segmentsIntersect(Segment s1, Segment s2) {
    double d1 = direction(s1.p1, s1.p2, s2.p1);
    double d2 = direction(s1.p1, s1.p2, s2.p2);
    double d3 = direction(s2.p1, s2.p2, s1.p1);
    double d4 = direction(s2.p1, s2.p2, s1.p2);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    }

    return false;
}

// Function to find the intersection point of two line segments
bool segmentIntersection(Segment s1, Segment s2, Point &intersection) {
    if (!segmentsIntersect(s1, s2)) {
        return false;
    }

    double a1 = s1.p2.y - s1.p1.y;
    double b1 = s1.p1.x - s1.p2.x;
    double c1 = a1 * s1.p1.x + b1 * s1.p1.y;

    double a2 = s2.p2.y - s2.p1.y;
    double b2 = s2.p1.x - s2.p2.x;
    double c2 = a2 * s2.p1.x + b2 * s2.p1.y;

    double det = a1 * b2 - a2 * b1;

    if (fabs(det) < 1e-9) {
        return false; // Lines are parallel
    }

    intersection.x = (b2 * c1 - b1 * c2) / det;
    intersection.y = (a1 * c2 - a2 * c1) / det;
    return true;
}

// Function to compute the Euclidean distance between two points
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to calculate the minimum cutting cost
double calculateCuttingCost(const vector<Point> &steel, const vector<Point> &mold) {
    double totalCost = 0;

    for (size_t i = 0; i < mold.size(); i++) {
        Segment moldEdge = {mold[i], mold[(i + 1) % mold.size()]};

        vector<Point> intersections;

        for (size_t j = 0; j < steel.size(); j++) {
            Segment steelEdge = {steel[j], steel[(j + 1) % steel.size()]};

            Point intersection;
            if (segmentIntersection(moldEdge, steelEdge, intersection)) {
                intersections.push_back(intersection);
            }
        }

        if (intersections.size() == 2) {
            totalCost += distance(intersections[0], intersections[1]);
        }
    }

    return totalCost;
}

int main() {
    ifstream fin("STEEL.INP");
    ofstream fout("STEEL.OUT");

    int n, m;
    fin >> n;

    vector<Point> steel(n);
    for (int i = 0; i < n; i++) {
        fin >> steel[i].x >> steel[i].y;
    }

    fin >> m;
    vector<Point> mold(m);
    for (int i = 0; i < m; i++) {
        fin >> mold[i].x >> mold[i].y;
    }

    double result = calculateCuttingCost(steel, mold);

    fout << fixed << setprecision(4) << result << endl;

    fin.close();
    fout.close();

    return 0;
}
