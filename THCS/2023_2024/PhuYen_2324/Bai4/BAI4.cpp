#include <iostream>
#include <fstream> // Thư viện cho việc đọc/ghi file
#include <cstring>
#define SIZE 120 // Điều chỉnh SIZE lớn hơn cho số lớn
using namespace std;

// Khai báo hàm trước khi sử dụng
void tinhTich(char A[], char B[], char C[]);

// Hàm để đảo ngược chuỗi
void reverse(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

int main() {
    char A[SIZE], B[SIZE], C[SIZE * 2] = {0}; // Khởi tạo C

    // Mở file để đọc dữ liệu
    ifstream inputFile("BAI4.INP");
    if (!inputFile) {
        cerr << "Không thể mở file BAI4.INP" << endl;
        return 1; // Thoát nếu không mở được file
    }

    // Đọc hai số từ file
    inputFile.getline(A, SIZE);
    inputFile.getline(B, SIZE);
    inputFile.close(); // Đóng file sau khi đọc

    // Tính tích và lưu kết quả
    tinhTich(A, B, C);

    // Mở file để ghi kết quả
    ofstream outputFile("BAI4.OUT");
    if (!outputFile) {
        cerr << "Không thể mở file BAI4.OUT" << endl;
        return 1; // Thoát nếu không mở được file
    }

    // Ghi kết quả vào file
    outputFile << C << endl;
    outputFile.close(); // Đóng file sau khi ghi

    return 0; // Kết thúc chương trình thành công
}

void tinhTich(char A[], char B[], char C[]) {
    reverse(A);
    reverse(B);
    int lenA = strlen(A);
    int lenB = strlen(B);

    // Khởi tạo mảng C
    for (int i = 0; i < lenA + lenB; i++) {
        C[i] = '0'; // Khởi tạo tất cả các vị trí bằng '0'
    }
    
    for (int iB = 0; iB < lenB; iB++) {
        int nho = 0; // Biến nhớ
        for (int iA = 0; iA < lenA; iA++) {
            // Tính tích
            int x = (B[iB] - '0') * (A[iA] - '0') + nho + (C[iA + iB] - '0');
            C[iA + iB] = (x % 10) + '0'; // Đặt giá trị tại vị trí tương ứng
            nho = x / 10; // Cập nhật giá trị nhớ
        }
        // Nếu còn số nhớ thì thêm vào
        if (nho > 0) {
            C[lenA + iB] += nho; // Cộng vào vị trí thích hợp
        }
    }

    // Xử lý vị trí null
    int result_len = lenA + lenB;
    while (result_len > 0 && C[result_len - 1] == '0') {
        result_len--; // Bỏ qua các số 0 ở đầu
    }
    C[result_len] = '\0'; // Đặt ký tự null
    reverse(C); // Đảo ngược lại kết quả
}
