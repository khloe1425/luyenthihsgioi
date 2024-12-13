#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm chuyển đổi từ CamelCase sang snake_case
string convertToSnakeCase(const string& camelCase) {
    string snake_case = "";
    for (int i = 0; i < camelCase.size(); i++) {
        char c = camelCase[i];
        if (isupper(c)) { // Nếu là chữ cái viết hoa
            if (i > 0) {
                snake_case += "_"; // Thêm dấu gạch dưới trước chữ cái viết hoa
            }
            snake_case += tolower(c); // Chuyển thành chữ thường
        } else {
            snake_case += c; // Thêm trực tiếp vào kết quả
        }
    }
    return snake_case;
}

int main() {
    // Đọc dữ liệu từ file KIEUMOI.INP
    ifstream input("KIEUMOI.INP");
    ofstream output("KIEUMOI.OUT");

    int n;
    input >> n; // Số lượng xâu
    input.ignore(); // Bỏ qua ký tự xuống dòng sau số nguyên

    for (int i = 0; i < n; i++) {
        string camelCase;
        getline(input, camelCase); // Đọc từng xâu CamelCase
        string snake_case = convertToSnakeCase(camelCase); // Chuyển đổi
        output << snake_case << endl; // Ghi kết quả vào file
    }

    input.close();
    output.close();

    return 0;
}
