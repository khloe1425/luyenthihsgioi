#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ifstream input("MAXSEQ.INP");
    ofstream output("MAXSEQ.OUT");

    int n, p;
    input >> n >> p;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }

    long long sum = 0;
    int start = 0, maxLength = -1;

    for (int end = 0; end < n; end++) {
        sum += a[end];

        while (sum >= p) {
            maxLength = max(maxLength, end - start + 1);
            sum -= a[start++];
        }
    }

    output << maxLength << endl;

    input.close();
    output.close();

    return 0;
}
