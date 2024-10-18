# Đọc giá trị x từ tệp B1.INP
with open("B1.INP", "r") as file:
    x = int(file.readline().strip())

# Tìm giá trị y nhỏ nhất thỏa mãn
y = -1
k = 1
while k * k <= x * 1000000:
    square = k * k
    if square % x == 0:
        y = square // x
        break
    k += 1

# Ghi kết quả vào tệp B1.OUT
with open("B1.OUT", "w") as file:
    file.write(str(y) + "\n")
