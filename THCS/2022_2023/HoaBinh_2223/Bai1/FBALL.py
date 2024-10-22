# Nhập dữ liệu
p, q, r, s, u, v = map(int, input().split())

# Khởi tạo điểm cho các đội
points_A = 0
points_B = 0
points_C = 0

# Tính điểm cho trận A gặp B
if p > q:
    points_A += 3  # A thắng
elif p < q:
    points_B += 3  # B thắng
else:
    points_A += 1  # Hòa
    points_B += 1  # Hòa

# Tính điểm cho trận A gặp C
if r > s:
    points_A += 3  # A thắng
else:
    points_C += 3  # C thắng

# Tính điểm cho trận B gặp C
if u > v:
    points_B += 3  # B thắng
else:
    points_C += 3  # C thắng

# Xuất điểm của ba đội
print(points_A, points_B, points_C)
