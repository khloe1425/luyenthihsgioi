#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Function to calculate the final position in the stack
int calculate_position(int k, int row, int col) {
    int position = 0;
    for (int i = 0; i < k; i++) {
        int bit_row = (row >> i) & 1; // Get the i-th bit of the row index
        int bit_col = (col >> i) & 1; // Get the i-th bit of the column index
        position |= (bit_row << (2 * i + 1)) | (bit_col << (2 * i));
    }
    return position;
}

int main() {
    ifstream input("GIFTS.INP");
    ofstream output("GIFTS.OUT");

    int k, p, q, u, v;
    input >> k >> p >> q >> u >> v;

    // Calculate positions for (p, q) and (u, v)
    int position_pq = calculate_position(k, p, q);
    int position_uv = calculate_position(k, u, v);

    // Output the results
    output << position_pq + 1 << " " << position_uv + 1 << endl;

    input.close();
    output.close();

    return 0;
}
