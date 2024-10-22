def digit_sum(n):
    """Tính tổng các chữ số của số nguyên n."""
    return sum(int(digit) for digit in str(n))

def count_beautiful_pairs(numbers):
    """Đếm số lượng cặp số đẹp trong danh sách numbers."""
    sum_count = {}
    beautiful_pairs = 0

    for number in numbers:
        s = digit_sum(number)  # Tính tổng chữ số
        if s in sum_count:
            beautiful_pairs += sum_count[s]  # Cộng dồn số cặp đẹp
            sum_count[s] += 1  # Tăng số lần xuất hiện của tổng chữ số
        else:
            sum_count[s] = 1  # Khởi tạo số lần xuất hiện của tổng chữ số

    return beautiful_pairs

# Nhập dữ liệu
n = int(input())
numbers = list(map(int, input().split()))

# Tính và xuất kết quả
result = count_beautiful_pairs(numbers)
print(result)
