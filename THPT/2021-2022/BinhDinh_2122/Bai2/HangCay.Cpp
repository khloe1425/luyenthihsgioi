#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream infile("HangCay.INP");
    ofstream outfile("HangCay.OUT");

    int n;
    infile >> n;
    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        infile >> h[i];
    }

    if (n == 1) {
        // Nếu chỉ có 1 cây, luôn phải cưa đổ cây đó
        outfile << 1 << endl;
        return 0;
    }

    int result = 2; // Cây đầu tiên và cây cuối cùng luôn đổ

    for (int i = 1; i < n - 1; i++) {
        if (h[i] < h[i - 1]) {
            // Cây có thể đổ sang trái mà không ảnh hưởng cây trước
            result++;
        } else if (h[i] + h[i] < h[i + 1]) {
            // Cây có thể đổ sang phải mà không ảnh hưởng cây sau
            result++;
        }
    }

    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
