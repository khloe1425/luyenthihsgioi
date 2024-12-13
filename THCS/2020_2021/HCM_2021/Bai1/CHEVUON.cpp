// CHEVUON.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the height adjustment for a cluster
int calculateClusterAdjustment(vector<vector<int>> &garden, int startRow, int startCol) {
    vector<int> heights;
    for (int i = startRow; i < startRow + 2; ++i) {
        for (int j = startCol; j < startCol + 2; ++j) {
            heights.push_back(garden[i][j]);
        }
    }

    sort(heights.begin(), heights.end(), greater<int>());
    int targetHeight = heights[0];
    int adjustment = 0;
    for (int h : heights) {
        adjustment += targetHeight - h;
    }

    return adjustment;
}

// Function to update the garden matrix to uniform height in a cluster
void updateCluster(vector<vector<int>> &garden, int startRow, int startCol) {
    vector<int> heights;
    for (int i = startRow; i < startRow + 2; ++i) {
        for (int j = startCol; j < startCol + 2; ++j) {
            heights.push_back(garden[i][j]);
        }
    }

    sort(heights.begin(), heights.end(), greater<int>());
    int targetHeight = heights[0];

    for (int i = startRow; i < startRow + 2; ++i) {
        for (int j = startCol; j < startCol + 2; ++j) {
            garden[i][j] = targetHeight;
        }
    }
}

int main() {
    ifstream input("CHEVUON.INP");
    ofstream output("CHEVUON.OUT");

    int M, N;
    input >> M >> N;

    vector<vector<int>> garden(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            input >> garden[i][j];
        }
    }

    int totalAdjustment = 0;

    for (int i = 0; i < M; i += 2) {
        for (int j = 0; j < N; j += 2) {
            totalAdjustment += calculateClusterAdjustment(garden, i, j);
            updateCluster(garden, i, j);
        }
    }

    // Output the updated garden
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            output << garden[i][j] << " ";
        }
        output << endl;
    }

    // Output the total adjustment
    output << totalAdjustment << endl;

    input.close();
    output.close();

    return 0;
}
