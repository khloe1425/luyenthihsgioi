#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm để đảo ngược một chuỗi
string reverseString(const string& str) {
    return string(str.rbegin(), str.rend());
}

// Hàm để so sánh số đảo ngược của A và B
string compareReversedNumbers(const string& A, const string& B) {
    string reversedA = reverseString(A);
    string reversedB = reverseString(B);
    
    // So sánh số đảo ngược
    if (reversedA > reversedB) {
        return A; // Trả về A nếu số đảo ngược của A lớn hơn
    } else {
        return B; // Trả về B nếu số đảo ngược của B lớn hơn
    }
}

int main() {
    // Đọc dữ liệu từ tệp
    ifstream infile("BNGUOC.INP");
    string A, B;
    infile >> A >> B;
    infile.close();

    // So sánh và lấy kết quả
    string result = compareReversedNumbers(A, B);

    // Ghi kết quả vào tệp
    ofstream outfile("BNGUOC.OUT");
    outfile << result << endl;
    outfile.close();

    return 0;
}
