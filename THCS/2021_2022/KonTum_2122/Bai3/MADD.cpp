#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char calculateCode(const string& id) {
    int weights[] = {3, 5, 7, 2, 8, 6, 4}; // Predefined weights
    int sum = 0;

    for (int i = 0; i < 7; ++i) {
        sum += (id[i] - '0') * weights[i]; // Calculate the weighted sum
    }

    int remainder = sum % 9; // Get the remainder when divided by 9
    char mapping[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'K'}; // Mapping to letters
    return mapping[remainder];
}

int main() {
    ifstream input("MADD.INP");
    ofstream output("MADD.OUT");

    string id;
    while (input >> id) {
        output << calculateCode(id) << endl; // Write the calculated code to the output file
    }

    input.close();
    output.close();
    return 0;
}
