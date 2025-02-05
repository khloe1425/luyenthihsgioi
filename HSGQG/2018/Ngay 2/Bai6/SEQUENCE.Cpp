#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("SEQUENCE.INP");
    ofstream fout("SEQUENCE.OUT");
    
    int N;
    fin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        fin >> A[i];
    }
    fin.close();
    
    sort(A.begin(), A.end()); // Sắp xếp dãy A để dễ tìm giá trị B tối ưu
    
    vector<int> B(N);
    int midIndex = N / 2;
    int start = A[midIndex] - midIndex; // Tạo dãy bắt đầu từ trung vị trừ đi index
    for (int i = 0; i < N; i++) {
        B[i] = start + i;
    }
    
    int d = 0;
    for (int i = 0; i < N; i++) {
        d += abs(A[i] - B[i]);
    }
    
    fout << d << endl;
    for (int i = 0; i < N; i++) {
        fout << B[i] << (i == N - 1 ? "" : " ");
    }
    fout << endl;
    
    fout.close();
    return 0;
}
