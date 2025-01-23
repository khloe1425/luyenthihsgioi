#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Hàm tính diện tích của đa giác dựa trên tọa độ điểm
double calculateArea(const vector<pair<int, int>>& points) {
    double area = 0;
    int n = points.size();
    for (int i = 0; i < n - 1; i++) {
        area += (points[i].first * points[i + 1].second - points[i + 1].first * points[i].second);
    }
    return abs(area) / 2.0;
}

int main() {
    ifstream input("LAND.INP");
    ofstream output("LAND.OUT");

    int n;
    input >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        input >> points[i].first >> points[i].second;
    }

    // Tính diện tích SA và SB ban đầu
    vector<pair<int, int>> alphaRegion(points);
    alphaRegion.push_back({points.back().first, 0});
    alphaRegion.push_back({points[0].first, 0});

    vector<pair<int, int>> betaRegion = alphaRegion;

    double initialAlphaArea = calculateArea(alphaRegion);
    double initialBetaArea = calculateArea(betaRegion);

    // Tính diện tích sau khi đổi đường ranh giới
    vector<pair<int, int>> newAlphaRegion, newBetaRegion;
    newAlphaRegion.push_back(points[0]);
    newBetaRegion.push_back(points[0]);

    for (int i = 1; i < n; i++) {
        if (points[i].second >= points[i - 1].second) {
            newAlphaRegion.push_back(points[i]);
        } else {
            newBetaRegion.push_back(points[i]);
        }
    }

    newAlphaRegion.push_back({points.back().first, 0});
    newBetaRegion.push_back({points.back().first, 0});

    double newAlphaArea = calculateArea(newAlphaRegion);
    double newBetaArea = calculateArea(newBetaRegion);

    // Ghi kết quả
    output << fixed << setprecision(4) << newAlphaArea << endl;
    output << fixed << setprecision(4) << newBetaArea << endl;

    input.close();
    output.close();

    return 0;
}
