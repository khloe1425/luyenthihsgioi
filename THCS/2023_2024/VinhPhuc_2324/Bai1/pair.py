def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False  # 0 và 1 không phải là số nguyên tố
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return is_prime

def count_prime_pairs(n, k):
    is_prime = sieve_of_eratosthenes(n)
    count = 0
    for x in range(2, n - k + 1):  # x phải lớn hơn 1 và y = x + k <= n
        y = x + k
        if is_prime[x] and y <= n and is_prime[y]:
            count += 1
    return count

# Đọc dữ liệu từ file input
with open('pair.inp', 'r') as f:
    n, k = map(int, f.readline().strip().split())

# Tính toán và ghi kết quả vào file output
result = count_prime_pairs(n, k)
with open('pair.out', 'w') as f:
    f.write(str(result) + '\n')
