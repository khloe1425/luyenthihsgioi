#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Hàm đọc dữ liệu từ tệp
void read_data(const string &filename, vector<int> &a, vector<int> &b, vector<int> &c, int &n, int &m, int &p) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Lỗi: Không thể mở tệp " << filename << endl;
        exit(1);
    }

    file >> n >> m >> p;
    a.resize(n);
    b.resize(m);
    c.resize(p);

    for (int i = 0; i < n; ++i) {
        file >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        file >> b[j];
    }
    for (int k = 0; k < p; ++k) {
        file >> c[k];
    }
    
    file.close();
}

// Hàm tính chênh lệch độ sáng nhỏ nhất
long long min_brightness_difference(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    vector<int> sorted_a = a;
    vector<int> sorted_b = b;
    vector<int> sorted_c = c;

    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    sort(sorted_c.begin(), sorted_c.end());

    long long min_diff = numeric_limits<long long>::max();
    int i = 0, j = 0, k = 0;

    while (i < sorted_a.size() && j < sorted_b.size() && k < sorted_c.size()) {
        int ai = sorted_a[i];
        int bj = sorted_b[j];
        int ck = sorted_c[k];

        // Tính chênh lệch
        long long diff = (ai - bj) * (ai - bj) + (bj - ck) * (bj - ck) + (ck - ai) * (ck - ai);

        // Cập nhật min_diff
        min_diff = min(min_diff, diff);

        // Tìm viên bi có độ sáng thấp nhất để tăng lên
        if (ai <= bj && ai <= ck) {
            i++;
        } else if (bj <= ai && bj <= ck) {
            j++;
        } else {
            k++;
        }
    }

    return min_diff;
}

// Hàm ghi kết quả vào tệp
void write_result(const string &filename, long long result) {
    ofstream file(filename);
    file << result << endl;
    file.close();
}

// Hàm chính
int main() {
    int n, m, p;
    vector<int> a, b, c;

    read_data("MARBLES.INP", a, b, c, n, m, p);
    long long result = min_brightness_difference(a, b, c);
    write_result("MARBLES.OUT", result);

    return 0;
}