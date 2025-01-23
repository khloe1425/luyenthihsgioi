#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int cost;
    int worker;
    int delivery;
};

bool compare(Task a, Task b) {
    return a.cost < b.cost; // Sắp xếp tăng dần theo chi phí
}

int main() {
    ifstream inputFile("GH.INP");
    ofstream outputFile("GH.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N, T;
    inputFile >> N >> T;

    vector<int> a1(N), a2(N), b1(T), b2(T);
    for (int i = 0; i < N; i++) {
        inputFile >> a1[i];
    }
    for (int i = 0; i < N; i++) {
        inputFile >> a2[i];
    }
    for (int i = 0; i < T; i++) {
        inputFile >> b1[i];
    }
    for (int i = 0; i < T; i++) {
        inputFile >> b2[i];
    }

    vector<Task> tasks;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            int cost1 = a1[i] + b1[j];
            int cost2 = a2[i] + b2[j];
            tasks.push_back({min(cost1, cost2), i, j});
        }
    }

    // Sắp xếp các cặp theo chi phí tăng dần
    sort(tasks.begin(), tasks.end(), compare);

    vector<bool> assignedWorker(N, false); // Nhân viên đã được gán
    vector<bool> assignedDelivery(T, false); // Yêu cầu đã được xử lý
    int totalCost = 0;

    // Gán Greedy
    for (auto& task : tasks) {
        if (!assignedWorker[task.worker] && !assignedDelivery[task.delivery]) {
            assignedWorker[task.worker] = true;
            assignedDelivery[task.delivery] = true;
            totalCost += task.cost;

            // Nếu đã gán đủ T yêu cầu, thoát vòng lặp
            if (count(assignedDelivery.begin(), assignedDelivery.end(), true) == T) {
                break;
            }
        }
    }

    outputFile << totalCost << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
