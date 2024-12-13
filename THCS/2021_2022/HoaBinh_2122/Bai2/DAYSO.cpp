#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream input("DAYSO.INP");
    ofstream output("DAYSO.OUT");

    int n; // Số lượng phần tử trong dãy
    long long k; // Số lần quay
    input >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }

    // Chỉ cần lấy k modulo n vì quay vòng n lần sẽ trở về trạng thái ban đầu
    k = k % n;

    // Phần tử đầu tiên sau khi quay k lần
    output << a[k] << endl;

    input.close();
    output.close();

    return 0;
}
