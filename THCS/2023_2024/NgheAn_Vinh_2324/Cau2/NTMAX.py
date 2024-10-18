import math

# Hàm kiểm tra số nguyên tố
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

# Đọc dữ liệu từ file NTMAX.INP
with open("NTMAX.INP", "r") as file:
    S = file.read().strip()

digit_count = 0
max_prime = 0
current_num = ""

# Duyệt qua từng ký tự trong chuỗi
for ch in S:
    if ch.isdigit():
        digit_count += 1
        current_num += ch  # Thêm vào chuỗi số hiện tại
    else:
        # Khi gặp ký tự không phải số, xử lý chuỗi số đã gom được
        if current_num:
            num = int(current_num)
            if is_prime(num):
                max_prime = max(max_prime, num)
            current_num = ""  # Reset chuỗi số hiện tại

# Kiểm tra lần cuối nếu chuỗi kết thúc bằng một số
if current_num:
    num = int(current_num)
    if is_prime(num):
        max_prime = max(max_prime, num)

# Ghi kết quả ra file NTMAX.OUT
with open("NTMAX.OUT", "w") as file:
    file.write(f"{digit_count}\n")
    file.write(f"{max_prime if max_prime > 0 else 0}\n")
