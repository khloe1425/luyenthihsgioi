#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Hàm đọc dữ liệu từ file
void read_input(const string &file_path, int &m, int &n, vector<vector<int>> &matrix) {
    ifstream infile(file_path);
    infile >> m >> n;
    matrix.resize(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> matrix[i][j];
        }
    }
    infile.close();
}

// Hàm lấy các vị trí hàng xóm
vector<pair<int, int>> get_neighbors(int i, int j, int m, int n) {
    vector<pair<int, int>> neighbors;
    // Các chỉ số hàng xóm
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // lên, xuống, trái, phải
    for (auto& dir : directions) {
        int ni = i + dir[0];
        int nj = j + dir[1];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            neighbors.push_back({ni, nj});
        }
    }
    return neighbors;
}

// Hàm đếm số người may mắn
int count_lucky_guests(int m, int n, const vector<vector<int>> &matrix) {
    int lucky_count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            auto neighbors = get_neighbors(i, j, m, n);
            vector<int> neighbor_values;
            for (const auto& neighbor : neighbors) {
                neighbor_values.push_back(matrix[neighbor.first][neighbor.second]);
            }
            if (!neighbor_values.empty()) { // Đảm bảo có hàng xóm
                double avg_neighbors = 0;
                for (int value : neighbor_values) {
                    avg_neighbors += value;
                }
                avg_neighbors /= neighbor_values.size();
                if (matrix[i][j] > avg_neighbors) {
                    lucky_count++;
                }
            }
        }
    }
    return lucky_count;
}

// Hàm ghi kết quả ra file
void write_output(const string &file_path, int result) {
    ofstream outfile(file_path);
    outfile << result << endl;
    outfile.close();
}

int main() {
    string input_file = "LUCKY.INP";
    string output_file = "LUCKY.OUT";

    int m, n;
    vector<vector<int>> matrix;

    read_input(input_file, m, n, matrix);
    int lucky_count = count_lucky_guests(m, n, matrix);
    write_output(output_file, lucky_count);

    return 0;
}
