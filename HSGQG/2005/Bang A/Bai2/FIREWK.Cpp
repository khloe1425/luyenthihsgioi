#include <bits/stdc++.h>
using namespace std;

// Trả về các màu có thể kề ngay sau màu c (theo quy tắc “cầu vồng”)
vector<int> adjColors(int c, int m) {
    vector<int> res;
    if(c == 1) {
        // Màu 1 chỉ kề màu 2
        res.push_back(2);
    } else if(c == m) {
        // Màu m chỉ kề màu m-1
        res.push_back(m-1);
    } else {
        // Màu i (1 < i < m) kề i-1 hoặc i+1
        res.push_back(c-1);
        res.push_back(c+1);
    }
    return res;
}

// Hàm sinh “mã hoa”: lấy tất cả phép quay + phép đảo
// của dãy seq, trả về dãy (2n phần tử) nhỏ nhất theo thứ tự từ điển
vector<int> getMinRotationCode(const vector<int> &seq) {
    int len = (int)seq.size();
    // Nối đôi dãy để tiện xét mọi phép quay
    vector<int> doubled(2*len);
    for(int i=0; i<len; i++){
        doubled[i]      = seq[i];
        doubled[i+len]  = seq[i];
    }
    // So sánh để tìm cấu hình (quay/đảo) nhỏ nhất
    vector<int> best = seq; // khởi tạo tạm là seq gốc

    for(int start = 0; start < len; start++){
        // Lấy đoạn [start, start+len)
        vector<int> cand(doubled.begin() + start, doubled.begin() + start + len);
        // So sánh “thuận”
        if(cand < best) best = cand;
        // So sánh “đảo ngược”
        reverse(cand.begin(), cand.end());
        if(cand < best) best = cand;
        // Đảo lại để không ảnh hưởng lần lặp kế
        reverse(cand.begin(), cand.end());
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file đọc & ghi
    ifstream fin("FIREWK.INP");
    ofstream fout("FIREWK.OUT");

    // Đọc n, m, k, C
    int n, m, k, C;
    fin >> n >> m >> k >> C;

    // Đọc dãy 2n mô tả màu các cánh hoa
    int length = 2*n;
    vector<int> firework(length);
    for(int i = 0; i < length; i++) {
        fin >> firework[i];
    }

    // Lấy “mã hoa” (code) của bông pháo hoa vừa đọc
    vector<int> inputCode = getMinRotationCode(firework);

    // Ta duyệt/brute‐force tất cả dãy chiều dài 2n thoả mãn kề nhau
    // (theo quy tắc cầu vồng) để tìm tất cả “mã hoa” hợp lệ
    // có đúng k cánh màu C.
    // (Với n = 3 nhỏ, hoàn toàn duyệt được.)
    set<vector<int>> validCodes;
    vector<int> cur;
    cur.reserve(length);

    // Hàm đệ quy backtracking
    function<void(int)> backtrack = [&](int pos){
        // Nếu đã có đủ 2n màu
        if(pos == length){
            // Kiểm tra cặp cuối – đầu
            int last = cur[length - 1];
            int first = cur[0];
            bool ok = false;
            for(int nxt : adjColors(last, m)){
                if(nxt == first){ 
                    ok = true; 
                    break; 
                }
            }
            if(!ok) return;

            // Đếm số cánh màu C
            int countC = 0;
            for(int x : cur){
                if(x == C) countC++;
            }
            if(countC == k){
                // Tính “mã hoa” (đại diện vòng)
                vector<int> code = getMinRotationCode(cur);
                validCodes.insert(code);
            }
            return;
        }

        // Nếu là cánh đầu tiên, ta có thể thử mọi màu 1..m
        if(pos == 0) {
            for(int color = 1; color <= m; color++){
                cur.push_back(color);
                backtrack(pos+1);
                cur.pop_back();
            }
        } else {
            // Chỉ thử những màu kề với màu trước
            int prev = cur[pos-1];
            for(int nxt : adjColors(prev, m)){
                cur.push_back(nxt);
                backtrack(pos+1);
                cur.pop_back();
            }
        }
    };

    // Gọi backtracking
    backtrack(0);

    // Tập hợp tất cả mã hoa hợp lệ là validCodes
    // p = số lượng phần tử trong validCodes
    int p = (int)validCodes.size();

    // Tìm thứ hạng (1-based) của inputCode trong validCodes
    // (giả sử inputCode chắc chắn nằm trong validCodes)
    auto it = validCodes.find(inputCode);
    int rank = 1 + distance(validCodes.begin(), it); // rank bắt đầu từ 1

    // Ghi kết quả ra file
    fout << p << "\n" << rank << "\n";

    return 0;
}
