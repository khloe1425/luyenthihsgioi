#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline, money, index;
};

// Sắp xếp giảm dần theo tiền công, nếu bằng nhau thì giữ nguyên thứ tự
bool cmp(Job a, Job b) {
    return a.money > b.money;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI3.INP");
    ofstream fout("BAI3.OUT");

    int n;
    fin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        fin >> jobs[i].deadline >> jobs[i].money;
        jobs[i].index = i + 1; // Ghi nhớ chỉ số ban đầu
    }

    // Bước 1: Sắp xếp công việc giảm dần theo tiền công
    sort(jobs.begin(), jobs.end(), cmp);

    vector<int> slot(n + 1, -1); // Mảng theo dõi thời gian thực hiện công việc
    vector<int> result;          // Chứa chỉ số công việc được chọn
    long long totalMoney = 0;

    // Bước 2: Lập lịch thực hiện công việc
    for (auto job : jobs) {
        for (int t = min(job.deadline, n); t >= 1; t--) { // Tìm thời gian trống
            if (slot[t] == -1) { // Nếu thời gian t còn trống
                slot[t] = job.index; // Thực hiện công việc tại thời gian này
                totalMoney += job.money;
                break;
            }
        }
    }

    // Bước 3: Ghi kết quả theo thời gian thực hiện
    for (int t = 1; t <= n; t++) {
        if (slot[t] != -1) {
            result.push_back(slot[t]);
        }
    }

    for (int idx : result) {
        fout << idx << "\n";
    }
    fout << totalMoney << "\n";

    fin.close();
    fout.close();
    return 0;
}
