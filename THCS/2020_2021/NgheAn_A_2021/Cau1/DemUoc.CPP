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
            divisorCount += 1; // Đếm ước i
            if (i != N / i) {
                divisorCount += 1; // Đếm ước N / i nếu khác i
            }
        }
    }

    output << divisorCount << endl;

    input.close();
    output.close();

    return 0;
}
