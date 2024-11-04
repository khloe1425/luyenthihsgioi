# Đọc dữ liệu từ file
with open("VUONCAY.INP", "r") as f:
    M, N = map(int, f.readline().split())
    garden = [list(map(int, f.readline().split())) for _ in range(M)]

# Tính chu vi ngoài của mảnh vườn
total_length = 2 * (M + N)

# Kiểm tra các cạnh ngang
for i in range(M):
    for j in range(N - 1):
        if garden[i][j] != garden[i][j + 1]:
            total_length += 1

# Kiểm tra các cạnh dọc
for i in range(M - 1):
    for j in range(N):
        if garden[i][j] != garden[i + 1][j]:
            total_length += 1

# Ghi kết quả ra file
with open("VUONCAY.OUT", "w") as f:
    f.write(str(total_length) + "\n")
