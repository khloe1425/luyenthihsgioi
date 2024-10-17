#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Hàm nhân hai số lớn
string multiply_large_numbers(const string &num1, const string &num2) {
    if (num1 == "0" || num2 == "0") return "0"; // Nếu một trong hai số là 0, trả về 0

    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0); // Vector để lưu trữ kết quả

    // Nhân từng chữ số
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int n1 = num1[i] - '0'; // Chuyển ký tự thành số
            int n2 = num2[j] - '0'; // Chuyển ký tự thành số
            int sum = n1 * n2 + result[i + j + 1]; // Tính tích và cộng vào vị trí tương ứng

            result[i + j + 1] = sum % 10; // Cập nhật vị trí phần đơn vị
            result[i + j] += sum / 10; // Cập nhật phần chục
        }
    }

    // Chuyển vector kết quả thành chuỗi
    string result_str;
    for (int num : result) {
        if (!(result_str.empty() && num == 0)) { // Bỏ qua các số 0 ở đầu
            result_str.push_back(num + '0'); // Chuyển số về ký tự
        }
    }

    return result_str.empty() ? "0" : result_str; // Nếu không có kết quả, trả về "0"
}

int main() {
    ifstream infile("BAI4.INP"); // Mở file để đọc
    ofstream outfile("BAI4.OUT"); // Mở file để ghi

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file!" << endl; // Kiểm tra lỗi mở file
        return 1;
    }

    string S1, S2;
    getline(infile, S1); // Đọc số S1
    getline(infile, S2); // Đọc số S2

    string product = multiply_large_numbers(S1, S2); // Tính tích
    outfile << product << endl; // Ghi kết quả vào file

    infile.close(); // Đóng file đọc
    outfile.close(); // Đóng file ghi
    return 0;
}
