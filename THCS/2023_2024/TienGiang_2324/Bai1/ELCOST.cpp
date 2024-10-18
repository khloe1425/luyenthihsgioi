#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input_file("ELCOST.INP");
    ofstream output_file("ELCOST.OUT");

    int n;
    input_file >> n; // Đọc số lượng hộ gia đình

    vector<int> kWh(n);
    for (int i = 0; i < n; ++i) {
        input_file >> kWh[i]; // Đọc số Kwh của mỗi hộ gia đình
    }

    long long total_cost = 0;

    for (int i = 0; i < n; ++i) {
        int usage = kWh[i];
        long long cost = 0;

        // Tính tiền điện cho hộ gia đình thứ i
        if (usage <= 100) {
            cost = usage * 2500;
        } else if (usage <= 200) {
            cost = 100 * 2500 + (usage - 100) * 3000;
        } else {
            cost = 100 * 2500 + 100 * 3000 + (usage - 200) * 3500;
        }

        total_cost += cost; // Cộng dồn vào tổng tiền
    }

    output_file << total_cost << endl; // Ghi tổng tiền vào tệp

    input_file.close();
    output_file.close();
    return 0;
}
