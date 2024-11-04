MOD = 10**9 + 7

def mod_pow(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def mod_inverse(a, mod):
    return mod_pow(a, mod - 2, mod)

def nCr(n, k, mod):
    if k > n:
        return 0
    numerator = 1
    denominator = 1
    for i in range(k):
        numerator = (numerator * (n - i)) % mod
        denominator = (denominator * (i + 1)) % mod
    return (numerator * mod_inverse(denominator, mod)) % mod

def main():
    n, K = map(int, input().split())
    A = list(map(int, input().split()))
    
    # Sắp xếp mảng A theo thứ tự giảm dần
    A.sort(reverse=True)
    
    # Tính tổng K phần tử lớn nhất
    total_sum = sum(A[i] for i in range(K)) % MOD
    
    # Tính số cách chọn K phần tử không liên tiếp từ n phần tử
    ways = nCr(n - K + 1, K, MOD)  # Số cách chọn K phần tử không liên tiếp

    # Tổng số cách
    total_ways = (total_sum * ways) % MOD
    
    print(total_ways)

if __name__ == "__main__":
    main()
