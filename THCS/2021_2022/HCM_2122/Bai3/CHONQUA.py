def calculate_prefix_sum(grid, D, R):
    # Khởi tạo mảng tổng cộng dồn
    prefix_sum = [[0] * (R + 1) for _ in range(D + 1)]
    
    # Tính mảng tổng cộng dồn
    for i in range(1, D + 1):
        for j in range(1, R + 1):
            prefix_sum[i][j] = (1 if grid[i-1][j-1] == '*' else 0) + \
                               prefix_sum[i-1][j] + \
                               prefix_sum[i][j-1] - \
                               prefix_sum[i-1][j-1]
    return prefix_sum

def get_sum(prefix_sum, x1, y1, x2, y2):
    # Tính tổng số '*' trong một khung từ (x1, y1) đến (x2, y2)
    return prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1]

def max_gifts(D, R, K, grid):
    prefix_sum = calculate_prefix_sum(grid, D, R)
    max_gifts = 0
    
    for i in range(1, D - K + 2):
        for j in range(1, R - K + 2):
            # Tính số '*' bên trong khung K-2 x K-2
            inner_gifts = get_sum(prefix_sum, i + 1, j + 1, i + K - 2, j + K - 2)
            max_gifts = max(max_gifts, inner_gifts)
    
    return max_gifts

# Đọc dữ liệu từ file
with open('CHONQUA.INP', 'r') as file:
    D, R, K = map(int, file.readline().split())
    grid = [file.readline().strip() for _ in range(D)]

# Tính kết quả và ghi ra file
result = max_gifts(D, R, K, grid)
with open('CHONQUA.OUT', 'w') as file:
    file.write(f"{result}\n")