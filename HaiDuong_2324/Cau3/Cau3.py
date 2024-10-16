def is_prime(num):
    """Kiểm tra số nguyên tố."""
    if num < 2:
        return False  # Số nhỏ hơn 2 không phải số nguyên tố
    if num == 2:
        return True   # 2 là số nguyên tố
    if num % 2 == 0:
        return False  # Các số chẵn lớn hơn 2 không phải số nguyên tố

    for i in range(3, int(num**0.5) + 1, 2):  # Kiểm tra các số lẻ từ 3 đến sqrt(num)
        if num % i == 0:
            return False  # Nếu num chia hết cho i, num không phải số nguyên tố
    return True  # num là số nguyên tố

def find_smallest_prime(n):
    """Tìm số nguyên tố nhỏ nhất lớn hơn hoặc bằng n."""
    while not is_prime(n):
        n += 1  # Tăng n lên cho đến khi tìm được số nguyên tố
    return n

if __name__ == "__main__":
    n = int(input())  # Nhập số nguyên dương n
    result = find_smallest_prime(n)
    print(result)  # In ra kết quả