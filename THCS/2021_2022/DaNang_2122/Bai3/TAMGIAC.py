# Đọc dữ liệu từ file
with open('TAMGIAC.INP', 'r') as file:
    a, b = map(int, file.readline().split())

# Tính khoảng giá trị của c
min_c = abs(a - b) + 1  # c phải lớn hơn |a - b|
max_c = a + b - 1       # c phải nhỏ hơn a + b

# Số lượng các giá trị c thỏa mãn
count_c = 0
if min_c <= max_c:
    count_c = max_c - min_c + 1

# Ghi kết quả ra file
with open('TAMGIAC.OUT', 'w') as file:
    file.write(str(count_c) + '\n')
