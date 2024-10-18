def calculate_min_b(matrix, m, n):
    row_sums = [sum(row) for row in matrix]  # Tính tổng mỗi dòng
    col_sums = [sum(matrix[i][j] for i in range(m)) for j in range(n)]  # Tính tổng mỗi cột

    min_value = float('inf')  # Khởi tạo giá trị nhỏ nhất là vô hạn

    # Tính giá trị của ma trận b và tìm giá trị nhỏ nhất
    for i in range(m):
        for j in range(n):
            b_ij = (row_sums[i] + col_sums[j]) - matrix[i][j]
            min_value = min(min_value, b_ij)  # Cập nhật giá trị nhỏ nhất nếu cần

    return min_value

def main():
    # Đọc dữ liệu từ tệp
    with open('SUM.INP', 'r') as input_file:
        # Đọc kích thước ma trận
        m, n = map(int, input_file.readline().strip().split())
        matrix = []

        # Đọc ma trận a
        for _ in range(m):
            row = list(map(int, input_file.readline().strip().split()))
            matrix.append(row)

    min_value = calculate_min_b(matrix, m, n)  # Tính giá trị nhỏ nhất trong ma trận b

    # Ghi kết quả vào tệp
    with open('SUM.OUT', 'w') as output_file:
        output_file.write(f"{min_value}\n")

if __name__ == "__main__":
    main()
