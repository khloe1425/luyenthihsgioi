// DIVISIBLE.CPP
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("DIVISIBLE.INP");
    ofstream output("DIVISIBLE.OUT");

    int T;
    input >> T;
    
    while (T--) {
        string N;
        input >> N;

        int sum = 0;
        for (char c : N) {
            sum += (c - '0'); // Tính tổng các chữ số
        }

        if (sum % 9 == 0) {
            output << "Yes" << endl;
        } else {
            output << "No" << endl;
        }
    }

    input.close();
    output.close();

    return 0;
}
