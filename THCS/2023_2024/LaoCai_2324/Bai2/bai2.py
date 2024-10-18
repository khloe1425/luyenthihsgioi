def sieve_of_eratosthenes(limit):
    """Hàm sử dụng Sàng Eratosthenes để tìm tất cả các số nguyên tố <= limit."""
    is_prime = [True] * (limit + 1)
    primes = []
    is_prime[0], is_prime[1] = False, False  # 0 và 1 không phải là số nguyên tố

    for i in range(2, limit + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(2 * i, limit + 1, i):
                is_prime[j] = False

    return primes


def calculate_s(n, primes):
    """Hàm tính tích các thừa số nguyên tố khác nhau của n."""
    s = 1
    for prime in primes:
        if prime > n:
            break
        if n % prime == 0:
            s *= prime
            # Loại bỏ tất cả các lần xuất hiện của prime trong n
            while n % prime == 0:
                n //= prime
    return s


def main():
    # Đọc giá trị M từ tệp bai2.inp
    with open("bai2.inp", "r") as infile:
        M = int(infile.readline().strip())

    # Tìm tất cả các số nguyên tố <= M
    primes = sieve_of_eratosthenes(M)

    # Tìm số N ≤ M có S lớn nhất
    result_n = 0
    max_s = 0

    for i in range(2, M + 1):
        s = calculate_s(i, primes)
        # Cập nhật nếu tìm thấy giá trị S lớn hơn
        if s > max_s:
            max_s = s
            result_n = i
        elif s == max_s and i > result_n:
            result_n = i  # Lưu số lớn nhất nếu S bằng nhau

    # Ghi kết quả vào tệp bai2.out
    with open("bai2.out", "w") as outfile:
        outfile.write(f"{result_n}\n")


if __name__ == "__main__":
    main()
