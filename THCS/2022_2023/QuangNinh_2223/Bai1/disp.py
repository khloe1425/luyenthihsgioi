import math

# Đọc dữ liệu từ file
with open('disp.inp', 'r') as f:
    n = int(f.read().strip())

# Biến lưu cặp (a, b) thỏa mãn với hiệu b - a nhỏ nhất
best_a, best_b = 1, n

# Duyệt từ 1 đến sqrt(n) để tìm các ước số của n
for a in range(1, int(math.sqrt(n)) + 1):
    if n % a == 0:
        b = n // a
        # Kiểm tra điều kiện a <= b và cập nhật nếu b - a nhỏ hơn
        if a <= b and b - a < best_b - best_a:
            best_a, best_b = a, b

# Ghi kết quả ra file
with open('disp.out', 'w') as f:
    f.write(f'{best_a} {best_b}\n')
