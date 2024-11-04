#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1005], n, k;

// Hàm kiểm tra xem có thể phủ sóng tất cả trạm thu sóng với phạm vi R hay không
bool check(ll x) {
    ll t = a[1] + x, d = 1;  // d là số trạm phát sóng đã sử dụng
    for(int i = 2; i <= n; i++) {
        if(a[i] > t + x) {  // Nếu trạm thu sóng thứ i không được bao phủ
            d++;
            t = a[i] + x;  // Đặt trạm phát sóng tại vị trí a[i]
        }
    }
    t = a[2] + x;  // Khởi tạo lại t cho lần kiểm tra thứ hai
    ll d1 = 1;  // Số trạm phát sóng thứ hai
    for(int i = 3; i <= n + 1; i++) {
        if(a[i] > t + x) {  // Tương tự như trên
            d1++;
            t = a[i] + x;  // Đặt trạm phát sóng tại vị trí a[i]
        }
    }
    return min(d, d1) <= k;  // Trả về true nếu số trạm phát sóng không vượt quá K
}

// Hàm tìm kiếm nhị phân để tìm phạm vi phát sóng ngắn nhất
ll bs(ll l, ll r) {
    ll res = 0;  // Biến để lưu kết quả
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(check(mid)) {
            res = mid;  // Cập nhật kết quả
            r = mid - 1;  // Tìm kiếm phạm vi nhỏ hơn
        } else {
            l = mid + 1;  // Tìm kiếm phạm vi lớn hơn
        }
    }
    return res;  // Trả về phạm vi phát sóng ngắn nhất
}

int main() {
    // Đọc dữ liệu từ tệp
    freopen("TPS.INP", "r", stdin);
    freopen("TPS.OUT", "w", stdout);
    
    cin >> n;  // Số trạm thu sóng
    for(int i = 1; i <= n; i++) {
        cin >> a[i];  // Đọc vị trí trạm thu sóng
    }
    cin >> k;  // Số trạm phát sóng
    
    sort(a + 1, a + n + 1);  // Sắp xếp vị trí các trạm thu sóng
    a[n + 1] = 1000000 + a[1];  // Thêm trạm thu sóng đầu tiên vào cuối để xử lý vòng tròn
    
    cout << bs(1, 1000000) << endl;  // Tìm và in ra phạm vi phát sóng ngắn nhất
    return 0;  // Kết thúc chương trình
}
