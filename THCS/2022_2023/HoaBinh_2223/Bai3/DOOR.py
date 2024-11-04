import math

def min_rotations(n, pairs):
    results = []
    for a, b in pairs:
        k = 0
        # Kiểm tra GCD ban đầu
        while math.gcd(a, b + k) == 1:
            k += 1
        results.append(k)
    return results

# Nhập dữ liệu
n = int(input())
pairs = [tuple(map(int, input().split())) for _ in range(n)]

# Tính và xuất kết quả
results = min_rotations(n, pairs)
for result in results:
    print(result)
