#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

// Cấu trúc để lưu thông tin một bi
struct Ball {
    int x, y, color; // color = 1: bi xanh, color = 2: bi đỏ
};

// Hàm kiểm tra tính đồng tuyến của 3 điểm
bool isCollinear(const Ball& a, const Ball& b, const Ball& c) {
    // Tính diện tích tam giác xác định bởi 3 điểm
    // Nếu diện tích = 0 thì 3 điểm đồng tuyến
    return (b.y - a.y) * (c.x - a.x) == (c.y - a.y) * (b.x - a.x);
}

int main() {
    ifstream fin("BALLGAME.INP");
    ofstream fout("BALLGAME.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n;
    fin >> n;

    vector<Ball> blueBalls, redBalls;

    // Đọc dữ liệu vào 2 danh sách (bi xanh và bi đỏ)
    for (int i = 0; i < n; ++i) {
        int x, y;
        fin >> x >> y;
        blueBalls.push_back({x, y, 1}); // color = 1: xanh
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        fin >> x >> y;
        redBalls.push_back({x, y, 2}); // color = 2: đỏ
    }

    // Kết hợp danh sách bi xanh và đỏ
    vector<Ball> balls = blueBalls;
    balls.insert(balls.end(), redBalls.begin(), redBalls.end());

    int totalBalls = balls.size();

    // Tìm 3 bi thỏa mãn yêu cầu
    for (int i = 0; i < totalBalls; ++i) {
        for (int j = i + 1; j < totalBalls; ++j) {
            for (int k = j + 1; k < totalBalls; ++k) {
                if (isCollinear(balls[i], balls[j], balls[k])) {
                    // Đếm số bi xanh và bi đỏ
                    int blueCount = (balls[i].color == 1) + (balls[j].color == 1) + (balls[k].color == 1);
                    int redCount = (balls[i].color == 2) + (balls[j].color == 2) + (balls[k].color == 2);

                    // Kiểm tra điều kiện bài toán
                    if ((blueCount == 2 && redCount == 1) || (blueCount == 1 && redCount == 2) || (blueCount == 3 || redCount == 3)) {
                        fout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                        fin.close();
                        fout.close();
                        return 0;
                    }
                }
            }
        }
    }

    // Nếu không tìm được 3 bi thỏa mãn
    fout << -1 << endl;

    fin.close();
    fout.close();
    return 0;
}
