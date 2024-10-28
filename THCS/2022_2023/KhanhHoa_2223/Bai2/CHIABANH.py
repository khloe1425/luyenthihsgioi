# Đọc dữ liệu từ tệp CHIABANH.INP
with open("CHIABANH.INP", "r") as inputFile:
    # Đọc và chuyển các giá trị thành danh sách số nguyên
    mushrooms = list(map(int, inputFile.readline().strip().split()))

# Tính tổng lớn nhất của 4 phần tử liên tiếp
max_sum = 0
n = len(mushrooms)

# Duyệt qua các vị trí và lấy tổng 4 phần tử liên tiếp (tính tròn)
for i in range(n):
    # Tính chỉ số tròn cho 4 phần tử liên tiếp
    current_sum = mushrooms[i] + mushrooms[(i + 1) % n] + mushrooms[(i + 2) % n] + mushrooms[(i + 3) % n]
    max_sum = max(max_sum, current_sum)

# Ghi kết quả ra tệp CHIABANH.OUT
with open("CHIABANH.OUT", "w") as outputFile:
    outputFile.write(str(max_sum))
