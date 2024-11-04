#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    // Đọc dữ liệu từ tệp HOAHOC.INP
    ifstream infile("HOAHOC.INP");
    long long A, B; // Sử dụng long long để đảm bảo đủ khả năng lưu trữ
    infile >> A >> B;
    infile.close();

    // Tính số mol của Fe3O4
    long long mFe = A / 3; // Số mol Fe3O4 phụ thuộc vào số mol Fe
    long long mO2 = B / 1; // Số mol O2 (1 mol cho mỗi 3 mol Fe3O4)
    long long result = min(mFe, mO2); // Kết quả là số mol sản phẩm Fe3O4

    // Ghi kết quả vào tệp HOAHOC.OUT
    ofstream outfile("HOAHOC.OUT");
    outfile << result << endl;
    outfile.close();

    return 0;
}