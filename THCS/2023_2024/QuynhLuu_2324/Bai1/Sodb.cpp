#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Hàm tìm vị trí số đặc biệt cuối cùng
int find_last_special_number(const vector<int>& arr) {
    int last_special_index = 0; // Vị trí 1-based
    for (size_t i = 1; i < arr.size() - 1; ++i) {
        if (is_prime(arr[i - 1]) && is_prime(arr[i + 1])) {
            last_special_index = i + 1; // Chuyển sang chỉ số 1-based
        }
    }
    return last_special_index;
}

int main() {
    // Đọc dữ liệu từ file Sodb.INP
    ifstream infile("Sodb.INP");
    vector<int> arr;
    int number;

    while (infile >> number) {
        arr.push_back(number);
    }
    infile.close();

    // Tìm vị trí số đặc biệt cuối cùng
    int result = find_last_special_number(arr);

    // Ghi kết quả ra file Sodb.OUT
    ofstream outfile("Sodb.OUT");
    outfile << result << endl;
    outfile.close();

    return 0;
}
