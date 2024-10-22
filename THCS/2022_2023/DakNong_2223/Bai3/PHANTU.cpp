#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

// Hàm tính phân tử lượng từ công thức hóa học
int calculate_molecular_weight(const string &formula) {
    // Định nghĩa nguyên tử lượng
    unordered_map<char, int> atomic_weights = {
        {'H', 1},
        {'O', 16},
        {'N', 14},
        {'C', 12}
    };

    int total_weight = 0;
    int n = formula.length();
    for (int i = 0; i < n; ) {
        char element = formula[i]; // Lấy nguyên tử
        i++;

        int count = 0;

        // Kiểm tra nếu có số đi kèm nguyên tử
        while (i < n && isdigit(formula[i])) {
            count = count * 10 + (formula[i] - '0'); // Tính số lượng
            i++;
        }

        if (count == 0) { // Nếu không có số, mặc định số lượng là 1
            count = 1;
        }

        // Tính tổng trọng lượng cho nguyên tử hiện tại
        total_weight += atomic_weights[element] * count;
    }

    return total_weight;
}

int main() {
    // Đọc dữ liệu từ file PHANTU.INP
    ifstream input_file("PHANTU.INP");
    string formula;

    if (input_file.is_open()) {
        getline(input_file, formula); // Đọc công thức hóa học
        input_file.close();
    } else {
        cerr << "Không thể mở file PHANTU.INP" << endl;
        return 1;
    }

    // Tính phân tử lượng
    int molecular_weight = calculate_molecular_weight(formula);

    // Ghi kết quả ra file PHANTU.OUT
    ofstream output_file("PHANTU.OUT");
    if (output_file.is_open()) {
        output_file << molecular_weight << endl;
        output_file.close();
    } else {
        cerr << "Không thể mở file PHANTU.OUT" << endl;
        return 1;
    }

    return 0;
}
