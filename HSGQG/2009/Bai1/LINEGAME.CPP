#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("LINEGAME.INP");
    ofstream output("LINEGAME.OUT");

    int n;
    input >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        input >> arr[i];
    }

    // Debug: Print the original array
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Sort the array in descending order
    sort(arr.rbegin(), arr.rend());

    // Debug: Print the sorted array
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Calculate the maximum score
    int max_score = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            max_score += arr[i]; // Add for odd positions (0-based index)
        } else {
            max_score -= arr[i]; // Subtract for even positions (0-based index)
        }

        // Debug: Show the current score at each step
        cout << "Step " << i + 1 << ": max_score = " << max_score << endl;
    }

    // Output the result
    output << max_score << endl;

    input.close();
    output.close();

    return 0;
}
