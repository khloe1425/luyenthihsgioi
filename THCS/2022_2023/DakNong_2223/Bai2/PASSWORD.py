def is_prime(n):
    """Kiểm tra số nguyên tố."""
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def sum_of_digits(n):
    """Tính tổng các chữ số của một số."""
    return sum(int(digit) for digit in str(n))

def find_special_primes(l, r):
    """Tìm các số nguyên tố đặc biệt trong khoảng [l, r]."""
    special_primes = []
    for i in range(l, r + 1):
        if is_prime(i) and is_prime(sum_of_digits(i)):
            special_primes.append(i)
    return special_primes

# Đọc dữ liệu từ file PASSWORD.INP
with open("PASSWORD.INP", "r") as input_file:
    l, r = map(int, input_file.readline().strip().split())

# Tìm các số nguyên tố đặc biệt
special_primes = find_special_primes(l, r)

# Ghi kết quả ra file PASSWORD.OUT
with open("PASSWORD.OUT", "w") as output_file:
    output_file.write(" ".join(map(str, special_primes)) + "\n")
