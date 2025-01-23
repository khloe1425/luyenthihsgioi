#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Cấu trúc để lưu thời gian bắt đầu và kết thúc của trò chơi
struct Game {
    int start, end;
};

// So sánh để sắp xếp theo thời gian kết thúc
bool compare(const Game& a, const Game& b) {
    return a.end < b.end;
}

int maxGames(int N, vector<Game>& games) {
    // Sắp xếp các trò chơi theo thời gian kết thúc
    sort(games.begin(), games.end(), compare);

    int count = 0; // Đếm số trò chơi tham gia
    int last_end_time = 0; // Thời gian kết thúc của trò chơi cuối cùng được chọn

    // Duyệt qua các trò chơi
    for (const auto& game : games) {
        if (game.start >= last_end_time) { // Nếu không trùng thời gian
            count++; // Chọn trò chơi
            last_end_time = game.end; // Cập nhật thời gian kết thúc
        }
    }

    return count;
}

int main() {
    ifstream infile("LeHoi.Inp");
    ofstream outfile("LeHoi.Out");

    int N;
    infile >> N;

    vector<Game> games(N);
    for (int i = 0; i < N; i++) {
        infile >> games[i].start >> games[i].end;
    }

    int result = maxGames(N, games);
    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
