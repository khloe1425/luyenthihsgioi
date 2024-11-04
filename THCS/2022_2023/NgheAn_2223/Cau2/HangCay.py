def main():
    # Đọc dữ liệu từ tệp HangCay.INP
    with open('HangCay.INP', 'r') as input_file:
        n, m = map(int, input_file.readline().strip().split())  # Đọc n và m
        trees_watered = [False] * (n + 1)  # Mảng đánh dấu các cây được tưới nước

        # Đọc thông tin vòi nước
        for _ in range(m):
            x_i, r_i = map(int, input_file.readline().strip().split())  # Đọc vị trí và bán kính vòi nước
            # Tưới nước cho các cây trong khoảng [x_i - r_i, x_i + r_i]
            left_bound = max(1, x_i - r_i)
            right_bound = min(n, x_i + r_i)
            for j in range(left_bound, right_bound + 1):
                trees_watered[j] = True  # Đánh dấu cây được tưới nước

    # Tính số lượng cây được tưới nước
    watered_count = sum(trees_watered)  # Đếm số cây được tưới nước

    # Xuất kết quả ra tệp HangCay.OUT
    with open('HangCay.OUT', 'w') as output_file:
        output_file.write(str(watered_count) + '\n')

if __name__ == '__main__':
    main()
