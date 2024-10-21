#include <bits/stdc++.h>
using namespace std;

char* inp_file_name = "CAU01";

int main() {
    if (strcmp(inp_file_name, "") != 0) {
        char s[100];
        strcpy(s, inp_file_name);
        strcat(s, ".INP");
        freopen(s, "r", stdin);  // Đọc từ file input
        strcpy(s, inp_file_name);
        strcat(s, ".OUT");
        freopen(s, "w", stdout); // Ghi ra file output
    }

    // Đọc input từ file
    int n;
    cin >> n;
    vector<int> a(n + 1, 0); 

    // Tính toán t giá trị
    for (int i = 1; i <= n; i++) {
        int t = 1;
        int c = sqrt(i);
        for (int j = 2; j <= c; j++) {
            if (i % j == 0) {
                t += j;
                if (j != i / j) {
                    t += i / j;
                }
            }
        }
        if (i > 1) {
            t += i;
        }
        a[i] = t;
    }

    // Đếm số cặp
    int d = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == j || a[j] == i) {
                d++;
            }
        }
    }

    // In kết quả ra file .out
    cout << d << endl;

    return 0;
}
