#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Polygon {
    int numVertices;
    int color;
    vector<pair<int, int>> vertices;
};

double calculateArea(const vector<pair<int, int>>& vertices) {
    int n = vertices.size();
    long long area = 0; // Sử dụng long long để tránh tràn số
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; // Đỉnh tiếp theo
        area += 1LL * vertices[i].first * vertices[j].second; // Nhân chéo
        area -= 1LL * vertices[j].first * vertices[i].second; // Nhân chéo
    }
    return fabs(area) / 2.0; // Trả về diện tích tuyệt đối
}

int main() {
    ifstream input("TFIELD.INP");
    ofstream output("TFIELD.OUT");

    int m, k;
    input >> m >> k;

    vector<Polygon> polygons(m);
    map<int, double> colorArea;

    for (int i = 0; i < m; i++) {
        input >> polygons[i].numVertices >> polygons[i].color;
        polygons[i].vertices.resize(polygons[i].numVertices);
        for (int j = 0; j < polygons[i].numVertices; j++) {
            input >> polygons[i].vertices[j].first >> polygons[i].vertices[j].second;
        }
        double area = calculateArea(polygons[i].vertices);
        colorArea[polygons[i].color] += area;
    }

    vector<pair<double, int>> areaList;
    for (auto& entry : colorArea) {
        areaList.push_back({entry.second, entry.first});
    }

    sort(areaList.rbegin(), areaList.rend()); // Sắp xếp diện tích giảm dần

    double maxArea = 0;
    for (int i = 0; i < min(k, (int)areaList.size()); i++) {
        maxArea += areaList[i].first;
    }

    output << fixed << setprecision(1) << round(maxArea * 10) / 10.0 << endl;

    input.close();
    output.close();
    return 0;
}
