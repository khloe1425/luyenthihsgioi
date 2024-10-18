def sieve_of_eratosthenes(max_num):
    is_prime = [True] * (max_num + 1)
    p = 2
    is_prime[0] = is_prime[1] = False  # 0 và 1 không phải là số nguyên tố
    
    while (p * p <= max_num):
        if is_prime[p]:
            for i in range(p * p, max_num + 1, p):
                is_prime[i] = False
        p += 1

    return is_prime

def count_primes_in_range(A, B):
    # Tạo danh sách số nguyên tố từ 1 đến B
    is_prime = sieve_of_eratosthenes(B)
    
    # Đếm số lượng số nguyên tố trong đoạn [A, B]
    count = sum(1 for i in range(A, B + 1) if is_prime[i])
    
    return count

# Đọc dữ liệu vào từ file
with open("CAU02.INP", "r") as infile:
    A, B = map(int, infile.readline().strip().split())

# Đếm số lượng số nguyên tố
result = count_primes_in_range(A, B)

# Ghi kết quả ra file
with open("CAU02.OUT", "w") as outfile:
    outfile.write(str(result) + '\n')
