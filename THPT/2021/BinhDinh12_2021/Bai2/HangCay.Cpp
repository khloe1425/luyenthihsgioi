#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("HangCay.Inp");
    ofstream output("HangCay.Out");

    int N;
    input >> N;

    vector<int> heights(N), positions(N);
    for (int i = 0; i < N; ++i) {
        input >> heights[i];
        positions[i] = i;  // Tree position based on index
    }

    // Edge cases
    if (N == 1) {
        // Only one tree: always needs to fall
        output << 1 << endl;
        return 0;
    }

    int cuts = 0;

    // First tree can always fall left
    cuts++;
    int last_fall_position = positions[0] - heights[0];

    for (int i = 1; i < N - 1; ++i) {
        if (positions[i] - heights[i] > last_fall_position) {
            // Tree can fall to the left
            cuts++;
            last_fall_position = positions[i] - heights[i];
        } else if (positions[i] + heights[i] < positions[i + 1]) {
            // Tree can fall to the right
            cuts++;
            last_fall_position = positions[i] + heights[i];
        } else {
            // Tree remains standing
            last_fall_position = positions[i];
        }
    }

    // Last tree can always fall right
    cuts++;

    output << cuts << endl;

    input.close();
    output.close();

    return 0;
}
