# Đọc xâu ký tự từ file DKT.INP
with open("DKT.INP", "r") as input_file:
    s = input_file.readline().strip()  # Đọc dòng đầu tiên và loại bỏ ký tự newline

# Tạo một từ điển để đếm số lần xuất hiện của mỗi ký tự
char_count = {}

# Đếm số lần xuất hiện của từng ký tự
for char in s:
    if char in char_count:
        char_count[char] += 1
    else:
        char_count[char] = 1

# Đếm số ký tự xuất hiện ít nhất 2 lần
count = sum(1 for count in char_count.values() if count >= 2)

# Ghi kết quả ra file DKT.OUT
with open("DKT.OUT", "w") as output_file:
    output_file.write(str(count))  # Ghi số lượng ký tự xuất hiện ít nhất 2 lần vào file
