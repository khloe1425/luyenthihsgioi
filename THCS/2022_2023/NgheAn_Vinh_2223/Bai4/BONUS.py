def calculate_reward(A, n):
    total_reward = 0

    # Duyệt qua tất cả các dãy con liên tiếp
    for i in range(n):
        min_element = A[i]
        max_element = A[i]
        for j in range(i, n):
            # Cập nhật phần tử nhỏ nhất và lớn nhất cho dãy con từ i đến j
            min_element = min(min_element, A[j])
            max_element = max(max_element, A[j])

            # Cộng trọng số của dãy con này vào tổng
            total_reward += (max_element - min_element)

    return total_reward


# Đọc dữ liệu từ file input
with open('BONUS.INP', 'r') as infile:
    n = int(infile.readline().strip())  # Số phần tử của dãy A
    A = list(map(int, infile.readline().strip().split()))  # Dãy A

# Tính tổng phần thưởng
result = calculate_reward(A, n)

# Ghi kết quả ra file output
with open('BONUS.OUT', 'w') as outfile:
    outfile.write(f"{result}\n")
