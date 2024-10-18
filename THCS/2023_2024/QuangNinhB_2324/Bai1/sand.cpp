#include <iostream>
#include <fstream>
#include <algorithm> // cho std::min

using namespace std;

int main() {
    // Đọc dữ liệu từ file sand.inp
    ifstream infile("sand.inp");
    long long a, b, c, x, y;
    infile >> a >> b >> c >> x >> y;
    infile.close();

    // Tính số bánh sandwich có thể làm
    long long max_profit = 0;

    // Thử bán sandwich thịt bò trước
    long long max_bo = min(b, a / 2);  // số bánh sandwich thịt bò tối đa có thể làm
    long long remaining_bread = a - (max_bo * 2);
    long long max_ga = min(c, remaining_bread / 2);  // số bánh sandwich thịt gà tối đa có thể làm
    long long profit1 = (max_bo * x) + (max_ga * y);

    // Thử bán sandwich thịt gà trước
    long long max_ga_first = min(c, a / 2);  // số bánh sandwich thịt gà tối đa có thể làm
    long long remaining_bread_first = a - (max_ga_first * 2);
    long long max_bo_first = min(b, remaining_bread_first / 2);  // số bánh sandwich thịt bò tối đa có thể làm
    long long profit2 = (max_ga_first * y) + (max_bo_first * x);

    // Lợi nhuận tối đa
    max_profit = max(profit1, profit2);

    // Ghi kết quả ra file sand.out
    ofstream outfile("sand.out");
    outfile << max_profit << endl;
    outfile.close();

    return 0;
}
