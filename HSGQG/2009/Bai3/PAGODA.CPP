#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool is_valid(const string& C, const string& A, const string& B) {
    return A < C && C < B;
}

int main() {
    ifstream input("PAGODA.INP");
    ofstream output("PAGODA.OUT");

    int n;
    string A, B, C;

    // Read input
    input >> n;
    input >> A >> B >> C;

    // Sort C to start with the smallest permutation
    sort(C.begin(), C.end());

    string result = "-1";

    do {
        if (is_valid(C, A, B)) {
            if (result == "-1" || C < result) {
                result = C;
            }
        }
    } while (next_permutation(C.begin(), C.end()));

    // Output the result
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
