#include <iostream>
#include <cmath>
using namespace std;

// Function to find the largest rectangle area within the circle
int largestRectangle(int R) {
    int maxArea = 0;
    
    // Loop through all possible pairs of (x1, x2) and (y1, y2)
    for (int x1 = -R; x1 <= R; ++x1) {
        for (int x2 = x1; x2 <= R; ++x2) {
            for (int y1 = -R; y1 <= R; ++y1) {
                for (int y2 = y1; y2 <= R; ++y2) {
                    // Check if all 4 corners of the rectangle are inside the circle
                    if (x1 * x1 + y1 * y1 <= R * R && x2 * x2 + y1 * y1 <= R * R &&
                        x1 * x1 + y2 * y2 <= R * R && x2 * x2 + y2 * y2 <= R * R) {
                        // Calculate the area of the rectangle
                        int area = abs(x2 - x1) * abs(y2 - y1);
                        if (area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            }
        }
    }
    
    return maxArea;
}

int main() {
    // Read input from DIENTICH.INP
    freopen("DIENTICH.INP", "r", stdin);
    int R;
    cin >> R;

    // Find and output the largest rectangle area to DIENTICH.OUT
    freopen("DIENTICH.OUT", "w", stdout);
    cout << largestRectangle(R) << endl;

    return 0;
}
