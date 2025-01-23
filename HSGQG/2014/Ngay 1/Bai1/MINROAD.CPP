#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Point {
    int position;
    int type; // 1 for bamboo, 2 for pine
};

int main() {
    ifstream fin("MINROAD.INP");
    ofstream fout("MINROAD.OUT");

    int n, a, b;
    fin >> n >> a >> b;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        fin >> points[i].position >> points[i].type;
    }

    // Sort points by position
    sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
        return p1.position < p2.position;
    });

    int min_length = INT_MAX;

    // Sliding window to find the minimum segment
    int left = 0;
    int bamboo_count = 0, pine_count = 0;

    for (int right = 0; right < n; ++right) {
        // Increment counts based on type
        if (points[right].type == 1) {
            bamboo_count++;
        } else if (points[right].type == 2) {
            pine_count++;
        }

        // Check if current segment satisfies conditions
        while (bamboo_count >= a && pine_count >= b) {
            int segment_length = points[right].position - points[left].position;
            min_length = min(min_length, segment_length);

            // Move left pointer to try minimizing the segment
            if (points[left].type == 1) {
                bamboo_count--;
            } else if (points[left].type == 2) {
                pine_count--;
            }
            left++;
        }
    }

    if (min_length == INT_MAX) {
        fout << -1 << endl; // No valid segment found
    } else {
        fout << min_length << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
