def sum_of_digits(x):
    """Hàm tính tổng các chữ số của x."""
    return sum(int(digit) for digit in str(x))

def count_solutions(n):
    """Hàm tìm số nghiệm nguyên dương của phương trình x + s(x) = n."""
    count = 0
    # Xét giá trị x từ n - 9 * số chữ số của n đến n
    for x in range(max(1, n - 9 * 10), n):
        if x + sum_of_digits(x) == n:
            count += 1
    return count

def main():
    # Nhập dữ liệu từ bàn phím
    n = int(input("Nhập số nguyên dương n: "))
    
    result = count_solutions(n)  # Tính số nghiệm
    print(result)                 # In ra kết quả

if __name__ == "__main__":
    main()