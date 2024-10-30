def is_abundant_number(n):
    if n <= 1:
        return False
    total_sum = 1  # Bắt đầu với 1 vì 1 là ước của mọi số lớn hơn 1
    # Tìm ước số từ 2 đến căn bậc hai của n
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            total_sum += i
            if i != n // i:  # Nếu không phải là số chính phương
                total_sum += n // i
    return total_sum > n  # Tổng các ước số phải lớn hơn n

def count_abundant_numbers(a, b):
    abundant_count = 0
    for number in range(a, b + 1):
        if is_abundant_number(number):
            abundant_count += 1
    return abundant_count

# Đọc dữ liệu từ tệp
with open('SOPP.INP', 'r') as infile:
    a, b = map(int, infile.readline().split())

# Tính số lượng số phong phú
result = count_abundant_numbers(a, b)

# Ghi kết quả vào tệp
with open('SOPP.OUT', 'w') as outfile:
    outfile.write(str(result) + '\n')
