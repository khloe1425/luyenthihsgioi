#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Open input and output files
    ifstream fin("NOEL.INP");
    ofstream fout("NOEL.OUT");

    int n, d;
    fin >> n >> d;

    vector<int> gifts(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        fin >> gifts[i];
    }

    // Sort the array of gifts
    sort(gifts.begin(), gifts.end());

    int i = 0, j = 1; // Two pointers
    int max_kids = 0;

    // Process pairs
    while (j < 2 * n) {
        if (gifts[j] - gifts[i] <= d) {
            // Pair is valid, move to the next pair
            max_kids++;
            i++;
            j++;
        } else {
            // Pair is not valid, try the next gift for i
            j++;
        }
    }

    // Output the result
    fout << max_kids << endl;

    // Close the files
    fin.close();
    fout.close();

    return 0;
}
