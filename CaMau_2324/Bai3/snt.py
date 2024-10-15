input_path = './THCS/2024/CaMau/Bai3/snt.inp'
output_path = './THCS/2024/CaMau/Bai3/snt.out'

def sieve_of_eratosthenes(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False  # 0 và 1 không phải là số nguyên tố
    
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, limit + 1, i):
                is_prime[j] = False
    
    return is_prime

def count_primes_in_ranges(input_file, output_file):
    with open(input_file, 'r') as f:
        N = int(f.readline().strip())
        ranges = [tuple(map(int, f.readline().strip().split())) for _ in range(N)]
    
    # Giới hạn để tính số nguyên tố
    max_limit = 10**7
    
    # Tìm các số nguyên tố
    is_prime = sieve_of_eratosthenes(max_limit)
    
    # Tạo mảng tích lũy để đếm số lượng số nguyên tố
    prime_count = [0] * (max_limit + 1)
    for i in range(1, max_limit + 1):
        prime_count[i] = prime_count[i - 1] + (1 if is_prime[i] else 0)
    
    # Ghi kết quả vào tệp tin
    with open(output_file, 'w') as f:
        for Li, Ri in ranges:
            count = prime_count[Ri] - prime_count[Li - 1]
            f.write(f"{count}\n")

count_primes_in_ranges(input_path, output_path)
