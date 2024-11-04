def is_prime(num):
    """Kiểm tra xem số num có phải là số nguyên tố hay không."""
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def goldbach_conjecture(n, numbers):
    results = []
    for k in numbers:
        found = False
        best_pair = (0, 0)
        # Tìm cặp số nguyên tố có tổng bằng k
        for i in range(2, k // 2 + 1):
            j = k - i
            if is_prime(i) and is_prime(j):
                # Cập nhật cặp số nếu là cặp tốt hơn
                if abs(i - j) > abs(best_pair[0] - best_pair[1]):
                    best_pair = (i, j)
                found = True
        
        if found:
            results.append(f"{min(best_pair)} {max(best_pair)}")
        else:
            results.append("NO")
    return results

# Đọc dữ liệu từ file
with open("CAU2.INP", "r") as f:
    n = int(f.readline().strip())
    numbers = [int(f.readline().strip()) for _ in range(n)]

# Kiểm tra giả thuyết Goldbach
results = goldbach_conjecture(n, numbers)

# Ghi kết quả vào file
with open("CAU2.OUT", "w") as f:
    f.write("\n".join(results) + "\n")
