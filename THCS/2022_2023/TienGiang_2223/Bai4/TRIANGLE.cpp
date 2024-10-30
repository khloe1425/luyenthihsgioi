#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

// Hàm đọc dữ liệu từ file
void read_input(const string &file_path, int &n, vector<int> &lengths) {
    ifstream infile(file_path);
    infile >> n;
    lengths.resize(n);
    for (int i = 0; i < n; ++i) {
        infile >> lengths[i];
    }
    infile.close();
}

// Hàm kiểm tra xem ba que tính có thể tạo thành tam giác không
bool is_triangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Hàm tính diện tích của tam giác
double triangle_area(int a, int b, int c) {
    double p = (a + b + c) / 2.0; // Nửa chu vi
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Hàm tìm số lượng tam giác và diện tích lớn nhất
void count_triangles_and_max_area(int n, const vector<int> &lengths, int &triangle_count, double &max_area) {
    triangle_count = 0;
    max_area = -1.0; // Khởi tạo max_area với giá trị không hợp lệ
    // Duyệt qua tất cả các bộ ba que tính
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int a = lengths[i];
                int b = lengths[j];
                int c = lengths[k];
                if (is_triangle(a, b, c)) {
                    triangle_count++;
                    double area = triangle_area(a, b, c);
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
    }
}

// Hàm ghi kết quả ra file
void write_output(const string &file_path, int triangle_count, double max_area) {
    ofstream outfile(file_path);
    outfile << triangle_count << endl;
    if (triangle_count > 0) {
        outfile << fixed << setprecision(2) << max_area << endl;
    } else {
        outfile << -1 << endl;
    }
    outfile.close();
}

int main() {
    string input_file = "TRIANGLE.INP";
    string output_file = "TRIANGLE.OUT";

    int n;
    vector<int> lengths;

    read_input(input_file, n, lengths);
    int triangle_count;
    double max_area;
    count_triangles_and_max_area(n, lengths, triangle_count, max_area);
    write_output(output_file, triangle_count, max_area);

    return 0;
}
