#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inputFile("TG.INP");
    ofstream outputFile("TG.OUT");

    int N; // Số lượng thí sinh
    inputFile >> N;

    // Thời gian bắt đầu là 8 giờ 00 phút
    int startHour = 8;
    int startMinute = 0;

    for (int i = 0; i < N; ++i) {
        int Ti; // Thời gian hoàn thành bài sát hạch của thí sinh i
        inputFile >> Ti;

        // Tính thời gian kết thúc
        int endMinute = startMinute + Ti; // Tính phút kết thúc
        int endHour = startHour + endMinute / 60; // Tính giờ kết thúc
        endMinute = endMinute % 60; // Tính phút còn lại sau khi chia cho 60

        // Ghi kết quả ra tệp
        outputFile << setfill('0') << setw(2) << endHour << ":" << setfill('0') << setw(2) << endMinute << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
