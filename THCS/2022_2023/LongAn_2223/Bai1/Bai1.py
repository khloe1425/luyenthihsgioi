def sum_of_divisors(n):
    """Hàm tính tổng các ước số của n."""
    total = 0
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            total += i
            if i != n // i:
                total += n // i
    return total

def find_friendly_number(N):
    """Tìm số M lớn hơn N cùng tỉ ước."""
    sum_N = sum_of_divisors(N)
    ratio_N = sum_N / N

    for M in range(N + 1, 100001):
        sum_M = sum_of_divisors(M)
        ratio_M = sum_M / M

        if ratio_N == ratio_M:
            return M  # Trả về số M tìm được

    return -1  # Nếu không tìm thấy số nào thỏa mãn

if __name__ == "__main__":
    N = int(input("Nhập vào số N: "))
    M = find_friendly_number(N)
    print(M)
