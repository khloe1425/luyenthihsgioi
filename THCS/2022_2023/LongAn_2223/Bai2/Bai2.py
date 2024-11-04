def max_insulation_coefficient(N, coefficients):
    """Tính tổng hệ số cách nhiệt lớn nhất."""
    # Bắt đầu với tổng hệ số cách nhiệt là tổng các hệ số của từng lớp
    total = sum(coefficients)

    # Duyệt qua các lớp cách nhiệt từ lớp thứ hai trở đi
    for i in range(1, N):
        if coefficients[i] > coefficients[i - 1]:
            total += (coefficients[i] - coefficients[i - 1])  # Chênh lệch

    return total

if __name__ == "__main__":
    # Đọc dữ liệu từ tệp
    with open("NHIET.INP", "r") as f:
        N = int(f.readline().strip())
        coefficients = list(map(int, f.readline().strip().split()))

    # Tính và in ra kết quả
    result = max_insulation_coefficient(N, coefficients)
    print(result)
