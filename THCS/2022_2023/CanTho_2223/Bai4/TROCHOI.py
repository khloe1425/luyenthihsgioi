# Đọc dữ liệu từ file TROCHOI.INP
with open('TROCHOI.INP', 'r') as file:
    m, n = map(int, file.readline().split())

# Tính số que cần thiết
result = 2 * (m * n) + m + n

# Ghi kết quả ra file TROCHOI.OUT
with open('TROCHOI.OUT', 'w') as file:
    file.write(str(result))
