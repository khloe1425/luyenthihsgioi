#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_combinations(int n, int k, int start, vector<int>& current_combination, ofstream& output_file) {
    // Nếu độ dài của current_combination bằng k, ghi tổ hợp vào file
    if (current_combination.size() == k) {
        output_file << "{";
        for (size_t i = 0; i < current_combination.size(); i++) {
            output_file << current_combination[i];
            if (i < current_combination.size() - 1) {
                output_file << ",";
            }
        }
        output_file << "}\n";
        return;
    }

    // Tạo các tổ hợp
    for (int i = start; i <= n; i++) {
        current_combination.push_back(i); // Thêm người vào tổ hợp
        generate_combinations(n, k, i + 1, current_combination, output_file); // Gọi đệ quy
        current_combination.pop_back(); // Loại bỏ người vừa thêm
    }
}

int main() {
    int n, k;
    // Đọc dữ liệu từ file HT.INP
    ifstream input_file("HT.INP");
    if (input_file.is_open()) {
        input_file >> n >> k;
        input_file.close();
    }

    vector<int> current_combination; // Danh sách để chứa tổ hợp hiện tại
    ofstream output_file("HT.OUT");
    
    // Gọi hàm để tạo tổ hợp
    generate_combinations(n, k, 1, current_combination, output_file);
    
    // Đếm số tổ hợp
    int total_combinations = 1; // Công thức tính C(n, k) = n! / (k! * (n-k)!)
    for (int i = 1; i <= k; i++) {
        total_combinations *= (n - i + 1);
        total_combinations /= i;
    }
    
    // Ghi tổng số tổ hợp vào file
    output_file << total_combinations << endl;
    output_file.close();

    return 0;
}
