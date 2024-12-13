#include <iostream>
#include <windows.h> // Thư viện dùng cho hàm gotoxy
#include <string>
using namespace std;

// Hàm đặt con trỏ tại vị trí (x, y) trên console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm thực hiện hiệu ứng di chuyển từ trái sang phải
void moveLeftToRight(string text) {
    for (int x = 0; x <= 70; x++) { // Di chuyển từ cột 0 đến cột 70
        system("cls"); // Xóa màn hình
        gotoxy(x, 20); // Tại dòng 20
        cout << text;
        Sleep(100); // Dừng 100ms
    }
}

// Hàm thực hiện hiệu ứng di chuyển từ trên xuống dưới
void moveTopToBottom(string text) {
    for (int y = 0; y <= 20; y++) { // Di chuyển từ dòng 0 đến dòng 20
        system("cls"); // Xóa màn hình
        gotoxy(45, y); // Tại cột 45
        cout << text;
        Sleep(100); // Dừng 100ms
    }
}

// Hàm thực hiện hiệu ứng di chuyển chéo từ góc trái dưới lên góc phải trên
void moveBottomLeftToTopRight(string text) {
    for (int i = 0; i <= 20; i++) { // Từ góc trái dưới lên góc phải trên
        system("cls"); // Xóa màn hình
        gotoxy(i, 20 - i); // Giảm dòng và tăng cột
        cout << text;
        Sleep(100); // Dừng 100ms
    }
}

int main() {
    string text;
    cout << "Nhap mot xau ky tu bat ky (toi da 155 ky tu): ";
    getline(cin, text); // Nhập chuỗi từ người dùng

    // Gọi các hiệu ứng di chuyển
    moveLeftToRight(text);
    moveTopToBottom(text);
    moveBottomLeftToTopRight(text);

    return 0;
}
