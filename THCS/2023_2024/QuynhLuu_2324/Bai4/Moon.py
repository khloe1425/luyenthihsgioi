# Đọc dữ liệu từ file
with open('Moon.INP', 'r') as f:
    # Đọc dòng đầu tiên
    line = f.readline().strip()
    # Chia tách các giá trị
    values = list(map(int, line.split()))
    n = values[0]  # Số học sinh
    m = values[1]  # Số bánh An có
    x = values[2]  # Vị trí của An (tính từ 1)

# Số bánh An có thể nhận tối đa
max_cakes = m

# Tính toán số bánh tối đa mà An có thể nhận
if x == 1:  # An là người đầu tiên
    max_cakes = m
elif x == n:  # An là người cuối cùng
    max_cakes = m
else:  # An ở giữa
    # Số học sinh bên trái và bên phải
    left_neighbors = 1
    right_neighbors = 1

    # Số bánh tối đa An có thể nhận
    # Bánh của An phải lớn hơn hoặc bằng số bánh của các học sinh bên cạnh
    max_cakes = min(m, (m - left_neighbors) // 2 + 1) if m > 2 else 1

# Ghi kết quả ra file
with open('Moon.OUT', 'w') as f:
    f.write(str(max_cakes) + '\n')
