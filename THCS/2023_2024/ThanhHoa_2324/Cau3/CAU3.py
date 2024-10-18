# Hàm kiểm tra số đối xứng
def is_palindrome(n):
    return str(n) == str(n)[::-1]

# Hàm sàng Eratosthenes để tìm các số nguyên tố
def sieve_eratosthenes(limit):
    primes = []
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, limit + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, limit + 1, i):
                is_prime[j] = False
    return primes, is_prime

# Hàm đếm số ước nguyên tố khác nhau
def count_prime_factors(n, primes):
    prime_factors = set()
    for prime in primes:
        if prime * prime > n:
            break
        if n % prime == 0:
            prime_factors.add(prime)
            while n % prime == 0:
                n //= prime
    if n > 1:
        prime_factors.add(n)
    return len(prime_factors)

# Đọc dữ liệu từ tệp CAU3.INP
with open('CAU3.INP', 'r') as file:
    a, b = map(int, file.read().split())

# Sử dụng sàng Eratosthenes để tìm tất cả các số nguyên tố đến b
primes, is_prime = sieve_eratosthenes(b)

# Tính tổng các số đặc biệt
special_sum = 0

for num in range(a, b + 1):
    if is_palindrome(num):
        if count_prime_factors(num, primes) >= 3:
            special_sum += num

# Ghi kết quả ra tệp CAU3.OUT
with open('CAU3.OUT', 'w') as file:
    file.write(str(special_sum) + '\n')
