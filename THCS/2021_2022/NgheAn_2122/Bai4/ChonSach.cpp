#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Định nghĩa cấu trúc sách
struct Book {
    int d, r; // Chiều dài và chiều rộng
};

bool compareBooks(const Book &a, const Book &b) {
    if (a.d == b.d) return a.r > b.r; // Nếu chiều dài bằng nhau, ưu tiên chiều rộng lớn hơn
    return a.d < b.d; // Ưu tiên chiều dài nhỏ hơn
}

int main() {
    ifstream input("ChonSach.INP");
    ofstream output("ChonSach.OUT");

    int n;
    input >> n;

    vector<Book> books(n);
    for (int i = 0; i < n; i++) {
        input >> books[i].d >> books[i].r;
    }

    // Sắp xếp sách
    sort(books.begin(), books.end(), compareBooks);

    // Lập trình động
    vector<int> dp(n, 1); // Tất cả sách đều có thể chọn ít nhất 1 quyển
    int maxBooks = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (books[j].d < books[i].d && books[j].r < books[i].r) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxBooks = max(maxBooks, dp[i]);
    }

    output << maxBooks << endl;

    input.close();
    output.close();

    return 0;
}
