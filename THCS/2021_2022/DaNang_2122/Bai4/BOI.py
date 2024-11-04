# Đọc dữ liệu từ file
with open('BOI.INP', 'r') as file:
    P, N = map(int, file.readline().split())

# Biến đếm số lượng X thỏa mãn
count = 0
num = 9  # Số chứa toàn chữ số 9 (khởi đầu là 9)

# Kiểm tra các số có dạng toàn chữ số 9 từ 1 đến N chữ số
for i in range(1, N + 1):
    if num % P == 0:
        count += 1
    # Tạo số tiếp theo có toàn chữ số 9
    num = num * 10 + 9  # Thêm một chữ số 9 vào cuối

# Ghi kết quả ra file
with open('BOI.OUT', 'w') as file:
    file.write(f'{count}\n')
