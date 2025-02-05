#include <bits/stdc++.h>
using namespace std;

// Tính diện tích dưới đường thẳng s*x + i (trên đoạn [L,R])
//   ∫(s*x + i) dx từ L đến R = (s/2)*(R^2 - L^2) + i*(R - L)
double areaUnderLine(double s, double i, double L, double R) {
    return 0.5*s*(R*R - L*L) + i*(R - L);
}

// Tích phân của hàm max(0, s*x + i) trên [L,R]
double integrateMax0Linear(double s, double i, double L, double R){
    // Nếu s x + i không phụ thuộc x (s=0)
    if(fabs(s) < 1e-15) {
        // Nếu i>0 thì toàn bộ dải đều dương, ngược lại thì 0
        return (i>0.0 ? i*(R-L) : 0.0);
    }
    // Nghiệm x0 của s*x + i = 0 là x0 = -i/s
    double x0 = - i / s;
    // Ta chia [L,R] thành tối đa 2 đoạn: [L, min(R,x0)] và [max(L,x0), R]
    double ans = 0.0;

    // Đoạn 1: [L, min(R,x0)]
    double left1 = L, right1 = min(R, x0);
    if(right1 > left1) {
        // Nếu s>0 thì hàm (s*x+i) < 0 trên khoảng [L,x0], nên diện tích =0
        // Nếu s<0 thì hàm (s*x+i) > 0 trên [L,x0], ta cộng diện tích
        if(s < 0) {
            ans += areaUnderLine(s, i, left1, right1);
        }
    }

    // Đoạn 2: [max(L,x0), R]
    double left2 = max(L, x0), right2 = R;
    if(right2 > left2) {
        // Nếu s>0 thì hàm (s*x+i) > 0 trên [x0,R], ta cộng diện tích
        // Nếu s<0 thì hàm (s*x+i) < 0, diện tích =0
        if(s > 0) {
            ans += areaUnderLine(s, i, left2, right2);
        }
    }

    // ans có thể âm rất nhỏ do số học dấu (nếu đường cắt 1 phần),
    // ta chặn về >=0:
    return max(ans, 0.0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file đầu vào/ra
    ifstream fin("LAND.INP");
    ofstream fout("LAND.OUT");

    // Đọc số N
    int N; 
    fin >> N;

    // Đọc N điểm (x_i, y_i)
    vector<double> X(N), Y(N);
    for(int i=0; i<N; i++){
        fin >> X[i] >> Y[i];
    }

    // Đường thẳng g(x) nối (X[0],Y[0]) -> (X[N-1], Y[N-1]):
    double x1 = X[0], y1 = Y[0];
    double xN = X[N-1], yN = Y[N-1];
    // Hệ số g(x) = slopeG * x + interceptG
    double dx = xN - x1;
    // (giả sử dx>0 do đề nêu x_i <= x_{i+1}, x1 < xN)
    double slopeG = (yN - y1)/dx;
    double interceptG = y1 - slopeG*x1;

    // Ta cần tính 2 diện tích: SA, SB
    double SA=0.0, SB=0.0;

    // Duyệt các đoạn [X[i], X[i+1]]
    for(int i=0; i<N-1; i++){
        double xi = X[i], yi = Y[i];
        double xj = X[i+1], yj = Y[i+1];
        double len = xj - xi;
        if(len < 1e-15) continue; // đoạn suy biến

        // slopeF, interceptF cho f_i(x)
        double slopeF = (yj - yi)/len;
        double interceptF = yi - slopeF*xi;

        // Hiệu D(x) = f(x) - g(x) = (slopeF - slopeG)*x + (interceptF - interceptG)
        double sD = slopeF - slopeG;
        double iD = interceptF - interceptG;

        // SB += ∫ max(0, D(x)) dx
        SB += integrateMax0Linear(sD, iD, xi, xj);

        // SA += ∫ max(0, -D(x)) dx = ∫ max(0, -(slopeF-g)(x)) dx
        //                        = ∫ max(0, slopeG - slopeF, interceptG - interceptF)
        // ta gọi hàm integrateMax0Linear với ( -sD, -iD )
        SA += integrateMax0Linear(-sD, -iD, xi, xj);
    }

    // In kết quả (4 chữ số thập phân)
    fout << fixed << setprecision(4) << SA << "\n"
         << fixed << setprecision(4) << SB << "\n";

    return 0;
}
