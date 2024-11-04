#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Hàm tách biểu thức theo các dấu cộng và trừ
vector<string> splitByPlusMinus(const string &expr) {
    vector<string> result;
    string current = "";
    
    for (char c : expr) {
        if (c == '+' || c == '-') {
            result.push_back(current);
            result.push_back(string(1, c));
            current = "";
        } else {
            current += c;
        }
    }
    
    result.push_back(current);
    return result;
}

// Hàm tính giá trị của một biểu thức có phép nhân
long long evaluateMultiplication(const string &expr) {
    long long result = 1;
    string current = "";
    for (char c : expr) {
        if (c == '*') {
            result *= stoll(current);
            current = "";
        } else {
            current += c;
        }
    }
    result *= stoll(current); // tính toán phần còn lại
    return result;
}

// Hàm tính toán biểu thức
long long evaluateExpression(const string &expression) {
    vector<string> tokens = splitByPlusMinus(expression);
    long long result = evaluateMultiplication(tokens[0]);
    
    for (size_t i = 1; i < tokens.size(); i += 2) {
        string op = tokens[i];
        long long value = evaluateMultiplication(tokens[i + 1]);
        
        if (op == "+") {
            result += value;
        } else if (op == "-") {
            result -= value;
        }
    }
    
    return result;
}

int main() {
    // Đọc biểu thức từ file BIEUTHUC.INP
    ifstream inputFile("BIEUTHUC.INP");
    string expression;
    inputFile >> expression;
    inputFile.close();
    
    // Tính toán kết quả của biểu thức
    long long result = evaluateExpression(expression);
    
    // Ghi kết quả ra file BIEUTHUC.OUT
    ofstream outputFile("BIEUTHUC.OUT");
    outputFile << result;
    outputFile.close();
    
    return 0;
}
