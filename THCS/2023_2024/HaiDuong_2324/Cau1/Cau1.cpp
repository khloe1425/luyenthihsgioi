#include <iostream>
#include <algorithm> // Thư viện cho hàm max

int main() {
    int a, b;
    
    // Nhập vào hai chiều dài a và b
    std::cin >> a >> b;

    // Tính chiều dài c
    int c = std::max(a, b);

    // In ra kết quả
    std::cout << c << std::endl;

    return 0;
}