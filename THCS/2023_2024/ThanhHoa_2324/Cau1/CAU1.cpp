#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm chuyển đổi từ PropCase sang join_case
string convertPropToJoinCase(const string &varName) {
    string result;
    for (size_t i = 0; i < varName.size(); i++) {
        char ch = varName[i];
        if (isupper(ch) && i > 0) { // Nếu là chữ hoa và không phải ký tự đầu
            result += '_';          // Thêm dấu gạch dưới
        }
        result += tolower(ch);       // Thêm chữ cái (chuyển thành chữ thường)
    }
    return result;
}

int main() {
    // Đọc dữ liệu từ tệp CAU1.INP
    ifstream inputFile("CAU1.INP");
    string propCaseVar;
    if (inputFile.is_open()) {
        getline(inputFile, propCaseVar);
        inputFile.close();
    }

    // Chuyển đổi từ PropCase sang join_case
    string joinCaseVar = convertPropToJoinCase(propCaseVar);

    // Ghi kết quả vào tệp CAU1.OUT
    ofstream outputFile("CAU1.OUT");
    if (outputFile.is_open()) {
        outputFile << joinCaseVar;
        outputFile.close();
    }

    return 0;
}
