# Đọc dữ liệu từ file MUAHANG.INP
with open("MUAHANG.INP", "r") as infile:
    # Đọc số lượng hàng hóa và trọng lượng tối đa của xe đẩy
    N, M = map(int, infile.readline().split())
    
    # Lưu trữ trọng lượng và giá trị của mỗi hàng hóa
    weights = []
    values = []
    
    for _ in range(N):
        w, v = map(int, infile.readline().split())
        weights.append(w)
        values.append(v)

# Khởi tạo bảng dp
dp = [[0] * (M + 1) for _ in range(N + 1)]

# Lặp qua từng hàng hóa
for i in range(1, N + 1):
    for w in range(1, M + 1):
        if weights[i - 1] <= w:
            dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
        else:
            dp[i][w] = dp[i - 1][w]

# Kết quả tối đa có thể đạt được
max_value = dp[N][M]

# Tìm danh sách các hàng hóa được chọn
chosen_items = []
w = M
for i in range(N, 0, -1):
    if dp[i][w] != dp[i - 1][w]:  # Nếu dp[i][w] khác dp[i-1][w] thì có nghĩa là đã chọn hàng hóa i
        chosen_items.append(i)
        w -= weights[i - 1]

chosen_items.sort()  # Sắp xếp lại thứ tự chỉ số từ nhỏ đến lớn
total_weight = sum(weights[i - 1] for i in chosen_items)  # Tính tổng trọng lượng

# Ghi kết quả ra file MUAHANG.OUT
with open("MUAHANG.OUT", "w") as outfile:
    outfile.write(f"{max_value}\n")
    outfile.write(" ".join(map(str, chosen_items)) + "\n")
    outfile.write(f"{total_weight}\n")
