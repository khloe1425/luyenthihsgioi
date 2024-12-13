// DEMUOC.CPP
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream input("DemUoc.Inp");
    ofstream output("DemUoc.Out");

    long long N;
    input >> N;

    int divisorCount = 0;
    for (long long i = 1; i <= sqrt(N); ++i) {
        if (N % i == 0) {
            // i là ước của N
            divisorCount += 1;
            if (i != N / i) {
                // Trường hợp N / i là ước khác
                divisorCount += 1;
            }
        }
    }

    output << divisorCount << endl;

    input.close();
    output.close();

    return 0;
}
