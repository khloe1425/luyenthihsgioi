#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

string solve_string_game(int N, int K, string s) {
    // Sắp xếp xâu ký tự
    sort(s.begin(), s.end());

    // Nếu K = 1, kết quả là toàn bộ xâu sau khi sắp xếp
    if (K == 1) {
        return s;
    }

    // Nếu ký tự đầu tiên khác ký tự K-th trong xâu sắp xếp, kết quả là ký tự K-th
    if (s[0] != s[K - 1]) {
        return string(1, s[K - 1]);
    }

    // Bắt đầu với ký tự đầu tiên
    string result = string(1, s[0]);
    string rest = s.substr(K); // Phần còn lại sau khi lấy ra K ký tự đầu tiên

    // Nếu các ký tự còn lại đều giống nhau, chia đều thành các đoạn
    set<char> unique_chars(rest.begin(), rest.end());
    if (unique_chars.size() == 1) {
        for (int i = 0; i < rest.size(); i += K) {
            result += rest[i];
        }
    } else {
        result += rest;
    }

    return result;
}

int main() {
    ifstream inp("STRGAME.INP");
    ofstream out("STRGAME.OUT");

    int N, K;
    string s;

    // Đọc dữ liệu từ file STRGAME.INP
    inp >> N >> K;
    inp >> s;

    // Giải bài toán
    string result = solve_string_game(N, K, s);

    // Ghi kết quả ra file STRGAME.OUT
    out << result << endl;

    return 0;
}
