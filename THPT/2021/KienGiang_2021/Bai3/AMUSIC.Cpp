#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

struct Show {
    int end_time; // Thời gian kết thúc tiết mục
    int gift;     // Giá trị quà tặng
    int index;    // Chỉ số của nhóm
};

int N, d;
Show shows[MAXN];
vector<int> selected_shows;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("AMUSIC.INP");
    ofstream fout("AMUSIC.OUT");

    // Đọc dữ liệu
    fin >> N >> d;
    for (int i = 0; i < N; i++) {
        fin >> shows[i].end_time;
        shows[i].index = i + 1;
    }
    for (int i = 0; i < N; i++) {
        fin >> shows[i].gift;
    }

    // Sắp xếp các tiết mục theo thời gian kết thúc tăng dần
    sort(shows, shows + N, [](Show a, Show b) {
        return a.end_time < b.end_time;
    });

    // Chọn các nhóm nhạc sao cho tổng giá trị quà tặng là lớn nhất
    int total_gift = 0, last_time = -d;
    for (int i = 0; i < N; i++) {
        if (shows[i].end_time >= last_time + d) {
            total_gift += shows[i].gift;
            selected_shows.push_back(shows[i].index);
            last_time = shows[i].end_time;
        }
    }

    // Ghi kết quả
    fout << total_gift << "\n";
    for (int idx : selected_shows) {
        fout << idx << " ";
    }
    fout << "\n";

    fin.close();
    fout.close();
    return 0;
}
