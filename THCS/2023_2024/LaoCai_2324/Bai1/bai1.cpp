#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream infile("bai1.inp");
    ofstream outfile("bai1.out");

    long long a, b, K;
    infile >> a >> b >> K;

    // Kiểm tra nếu K là số lẻ
    if (K % 2 != 0) {
        outfile << "NO" << endl;
    } else {
        // Tìm số chia hết cho K đầu tiên và cuối cùng trong đoạn [a, b]
        long long first = (a % K == 0) ? a : a + (K - a % K);
        long long last = (b % K == 0) ? b : b - (b % K);

        // Kiểm tra xem có tồn tại số nào chia hết cho K trong đoạn [a, b]
        if (first > b || last < a) {
            outfile << "NO" << endl;
        } else {
            // Tính số lượng các số chia hết cho K trong đoạn [a, b]
            long long count = ((last - first) / K) + 1;

            // Kiểm tra nếu số lượng chẵn
            if (count % 2 == 0) {
                outfile << "YES" << endl;
            } else {
                outfile << "NO" << endl;
            }
        }
    }

    infile.close();
    outfile.close();
    return 0;
}
