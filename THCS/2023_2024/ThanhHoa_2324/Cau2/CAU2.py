# Đọc dữ liệu từ tệp CAU2.INP
with open('CAU2.INP', 'r') as file:
    n = int(file.read().strip())

# Biến đếm số cách mua gà và chó
count = 0

# Duyệt giá tiền gà từ 1 đến n//2
for x in range(1, n // 2 + 1):
    max_y = n - x  # Giá trị lớn nhất có thể của chó
    if x < max_y:
        count += (max_y - x)

# Ghi kết quả ra tệp CAU2.OUT
with open('CAU2.OUT', 'w') as file:
    file.write(str(count) + '\n')
