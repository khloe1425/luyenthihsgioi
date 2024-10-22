def is_prime(n):
    """Kiểm tra số nguyên n có phải là số nguyên tố hay không."""
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

def is_beautiful_prime(n):
    """Kiểm tra số nguyên n có phải là số nguyên tố "đẹp" hay không."""
    if not is_prime(n):
        return False
    # Kiểm tra xem n có chứa chữ số 3, 5, hoặc 7 không
    str_n = str(n)
    return '3' not in str_n and '5' not in str_n and '7' not in str_n

def count_beautiful_primes(N):
    """Đếm số lượng số nguyên tố "đẹp" từ 1 đến N."""
    count = 0
    for i in range(1, N + 1):
        if is_beautiful_prime(i):
            count += 1
    return count

# Đọc số nguyên dương N từ bàn phím
N = int(input("Nhập số nguyên dương N: "))
result = count_beautiful_primes(N)

# Xuất kết quả
print(result)
