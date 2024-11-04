#include <iostream>
using namespace std;

int main() {
    // Khai báo biến cho số bàn thắng và thua
    int p, q, r, s, u, v;
    cin >> p >> q >> r >> s >> u >> v;

    // Khởi tạo điểm cho các đội
    int points_A = 0, points_B = 0, points_C = 0;

    // Tính điểm cho trận A gặp B
    if (p > q) {
        points_A += 3; // A thắng
    } else if (p < q) {
        points_B += 3; // B thắng
    } else {
        points_A += 1; // Hòa
        points_B += 1; // Hòa
    }

    // Tính điểm cho trận A gặp C
    if (r > s) {
        points_A += 3; // A thắng
    } else if (r < s) {
        points_C += 3; // C thắng
    } else {
        points_A += 1; // Hòa
        points_C += 1; // Hòa
    }

    // Tính điểm cho trận B gặp C
    if (u > v) {
        points_B += 3; // B thắng
    } else if (u < v) {
        points_C += 3; // C thắng
    } else {
        points_B += 1; // Hòa
        points_C += 1; // Hòa
    }

    // Xuất điểm của ba đội
    cout << points_A << " " << points_B << " " << points_C << endl;

    return 0;
}
