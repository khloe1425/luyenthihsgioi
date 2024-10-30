#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm kiểm tra xem đoạn con B có đồng điệu với dãy A hay không
bool isHarmonic(const vector<int>& A, const vector<int>& B, int start) {
    int k = B[start] - A[0];
    int N = A.size();
    
    for (int i = 1; i < N; i++) {
        if (B[start + i] != A[i] + k) {
            return false;
        }
    }
    return true;
}

int main() {
    // Mở file BAI2.INP để đọc dữ liệu
    ifstream inp_file("BAI2.INP");
    ofstream out_file("BAI2.OUT");

    if (!inp_file || !out_file) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N, M;
    // Đọc dãy A
    inp_file >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        inp_file >> A[i];
    }

    // Đọc dãy B
    inp_file >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        inp_file >> B[i];
    }

    int count = 0;
    // Kiểm tra từng đoạn con của B có đồng điệu với A hay không
    for (int i = 0; i <= M - N; i++) {
        if (isHarmonic(A, B, i)) {
            count++;
            i += N - 1; // Bỏ qua các đoạn con rời nhau
        }
    }

    // Ghi kết quả vào file BAI2.OUT
    out_file << count << endl;

    // Đóng file
    inp_file.close();
    out_file.close();

    return 0;
}
