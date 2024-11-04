# Đọc dữ liệu từ tệp STRING.INP
with open('STRING.INP', 'r') as input_file:
    s = input_file.readline().strip()  # Đọc xâu và loại bỏ ký tự thừa

# Khởi tạo hai danh sách để lưu ký tự chữ và số
letters = []
digits = []

# Phân tách ký tự thành chữ cái và số
for ch in s:
    if ch.isalpha():
        letters.append(ch)  # Thêm chữ cái vào danh sách letters
    elif ch.isdigit():
        digits.append(ch)  # Thêm chữ số vào danh sách digits

# Đảo ngược danh sách letters và sắp xếp danh sách digits
letters.reverse()
digits.sort()

# Ghi kết quả vào tệp STRING.OUT
with open('STRING.OUT', 'w') as output_file:
    output_file.write(''.join(letters) + '\n')  # Ghi các chữ cái
    output_file.write(''.join(digits) + '\n')    # Ghi các chữ số
