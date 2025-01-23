#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Hàm tính khoảng cách Hamming giữa hai xâu cùng độ dài
int hammingDistance(const string& a, const string& b) {
    int distance = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            distance++;
        }
    }
    return distance;
}

int main() {
    ifstream fin("HAMMING.INP");
    ofstream fout("HAMMING.OUT");

    int n, m, k;
    fin >> n >> m >> k;

    string genStrange;
    fin >> genStrange;

    vector<string> genSamples(k);
    for (int i = 0; i < k; i++) {
        fin >> genSamples[i];
    }

    // Nhân đôi genStrange để xử lý vòng tròn
    string extendedGen = genStrange + genStrange;

    int minHamming = INT_MAX;

    // Duyệt qua từng mẫu gen
    for (const string& sample : genSamples) {
        // Duyệt qua từng đoạn con dài m trong gen lạ
        for (int i = 0; i < n; i++) {
            string subStr = extendedGen.substr(i, m);
            int hamming = hammingDistance(subStr, sample);
            minHamming = min(minHamming, hamming);
        }
    }

    fout << minHamming << endl;

    fin.close();
    fout.close();

    return 0;
}
