def is_prime(n):
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

def is_complete_prime(x):
    # Kiểm tra x có phải là số nguyên tố
    if not is_prime(x):
        return False

    # Kiểm tra loại bỏ các chữ số bên phải
    temp = x
    while temp > 0:
        if not is_prime(temp):
            return False
        temp //= 10  # Bỏ chữ số bên phải

    # Kiểm tra thêm các chữ số từ 0 đến 9 vào bên phải
    for d in range(10):
        if is_prime(x * 10 + d):
            return True  # Nếu có ít nhất 1 số nguyên tố, x là số nguyên tố toàn diện
    return False

def main():
    # Đọc dữ liệu từ tệp
    with open('SNTOTD.INP', 'r') as f:
        n = int(f.readline().strip())
        A = list(map(int, f.readline().strip().split()))
        m = int(f.readline().strip())
        queries = [tuple(map(int, f.readline().strip().split())) for _ in range(m)]

    # Tạo danh sách số nguyên tố toàn diện
    complete_primes = [0] * n
    for i in range(n):
        if is_complete_prime(A[i]):
            complete_primes[i] = 1

    # Tính prefix sum cho số nguyên tố toàn diện
    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + complete_primes[i - 1]

    # Xử lý các câu hỏi
    results = []
    for u, v in queries:
        count = prefix_sum[v] - prefix_sum[u - 1]
        results.append(count)

    # Ghi kết quả vào tệp
    with open('SNTOTD.OUT', 'w') as f:
        for result in results:
            f.write(str(result) + '\n')

if __name__ == "__main__":
    main()
