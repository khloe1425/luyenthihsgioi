def solve_robot_problem(N, M, Q, K, A, queries):
    # Tạo một mảng để lưu số lượng ô thỏa mãn điều kiện Ai,j % K = X cho mỗi X
    dp = [[{i: 0 for i in range(K)} for _ in range(M)] for _ in range(N)]
    
    # Khởi tạo cho ô (1, 1)
    dp[0][0][A[0][0] % K] = 1
    
    # Tính toán cho toàn bộ bảng A
    for i in range(N):
        for j in range(M):
            if i == 0 and j == 0:
                continue  # Bỏ qua ô khởi đầu đã tính trước
            
            current_mod = A[i][j] % K
            
            # Lấy giá trị lớn nhất từ các ô (i-1, j), (i, j-1), (i-1, j-1)
            for mod in range(K):
                max_prev = 0
                if i > 0:
                    max_prev = max(max_prev, dp[i-1][j][mod])
                if j > 0:
                    max_prev = max(max_prev, dp[i][j-1][mod])
                if i > 0 and j > 0:
                    max_prev = max(max_prev, dp[i-1][j-1][mod])
                
                dp[i][j][mod] = max_prev
            
            # Cộng thêm 1 cho giá trị mod hiện tại tại ô (i,j)
            dp[i][j][current_mod] += 1
    
    # Trả lời các truy vấn
    result = []
    for X in queries:
        result.append(dp[N-1][M-1][X])
    
    return result


# Đọc dữ liệu từ tệp
def read_input(filename):
    with open(filename, 'r') as f:
        N, M, Q, K = map(int, f.readline().split())
        A = [list(map(int, f.readline().split())) for _ in range(N)]
        queries = [int(f.readline().strip()) for _ in range(Q)]
    return N, M, Q, K, A, queries

# Ghi kết quả ra tệp
def write_output(filename, result):
    with open(filename, 'w') as f:
        for r in result:
            f.write(str(r) + '\n')

# Chương trình chính
if __name__ == "__main__":
    N, M, Q, K, A, queries = read_input('ROBOT.INP')
    result = solve_robot_problem(N, M, Q, K, A, queries)
    write_output('ROBOT.OUT', result)
