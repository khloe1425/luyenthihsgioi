def is_prime(n):
    """Kiểm tra xem số n có phải là số nguyên tố hay không."""
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def is_palindrome(n):
    """Kiểm tra xem số n có phải là số đối xứng hay không."""
    return str(n) == str(n)[::-1]

def count_palindromic_primes(x):
    """Đếm số lượng số nguyên tố đối xứng lớn hơn 10 và bé hơn x."""
    count = 0
    for num in range(11, x):
        if is_prime(num) and is_palindrome(num):
            count += 1
    return count

# Đọc số nguyên dương x từ file NTDX.INP
with open("NTDX.INP", "r") as input_file:
    x = int(input_file.readline().strip())  # Đọc dòng đầu tiên và loại bỏ ký tự newline

result = count_palindromic_primes(x)

# Ghi kết quả ra file NTDX.OUT
with open("NTDX.OUT", "w") as output_file:
    output_file.write(str(result))  # Ghi số nguyên m vào file
