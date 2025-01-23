#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("QUEUE.INP");
    ofstream fout("QUEUE.OUT");

    int T; // Số lượng test case
    fin >> T;

    while (T--) {
        int M, N;
        fin >> M >> N;

        vector<pair<int, int>> customers(N);
        vector<bool> parking(M + 1, false); // Trạng thái các điểm đỗ, 1-based

        // Đọc yêu cầu của từng khách hàng
        for (int i = 0; i < N; i++) {
            fin >> customers[i].first >> customers[i].second;
        }

        int served = 0; // Số khách hàng được phục vụ

        // Duyệt qua từng khách hàng
        for (int i = 0; i < N; i++) {
            bool found = false;

            // Thử từng điểm đỗ từ ai đến bi
            for (int j = customers[i].first; j <= customers[i].second; j++) {
                if (j >= 1 && j <= M && !parking[j]) { // Nếu điểm đỗ còn trống
                    parking[j] = true; // Đánh dấu là đã sử dụng
                    served++; // Tăng số khách phục vụ
                    found = true;
                    break;
                }
            }

            // Nếu không thể phục vụ khách hàng hiện tại, dừng phục vụ
            if (!found) {
                break;
            }
        }

        fout << served << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
