def sum_of_squares_of_digits(n):
    """Tính tổng bình phương các chữ số của n."""
    total = 0
    while n > 0:
        digit = n % 10
        total += digit ** 2
        n //= 10
    return total

def leads_to_one(n):
    """Kiểm tra xem n có dẫn đến 1 không."""
    seen = set()  # Tập hợp để lưu các số đã thấy
    while n != 1 and n not in seen:
        seen.add(n)
        n = sum_of_squares_of_digits(n)
    return n == 1

def find_k(n):
    """Tìm số K nhỏ nhất lớn hơn N mà dẫn đến 1."""
    k = n + 1  # Bắt đầu từ N + 1
    while True:
        if leads_to_one(k):
            return k
        k += 1  # Kiểm tra số tiếp theo

if __name__ == "__main__":
    N = int(input("Nhập số nguyên dương N: "))  # Nhập N từ bàn phím
    K = find_k(N)
    print(K)
