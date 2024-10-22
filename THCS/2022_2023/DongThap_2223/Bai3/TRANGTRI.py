def main():
    # Đọc dữ liệu từ tệp TRANGTRI.INP
    with open("TRANGTRI.INP", "r") as input_file:
        n, k = map(int, input_file.readline().split())
        heights = list(map(int, input_file.readline().split()))

    # Sắp xếp chiều cao của các cây
    heights.sort()

    max_count = 1  # Số cây tối đa có thể lắp đèn
    current_count = 1

    for i in range(1, n):
        # Kiểm tra xem chiều cao chênh lệch có nằm trong khoảng cho phép không
        if heights[i] - heights[i - 1] <= k:
            current_count += 1  # Tăng số cây liên tiếp
        else:
            max_count = max(max_count, current_count)  # Cập nhật số cây tối đa
            current_count = 1  # Reset lại số cây liên tiếp

    # Cập nhật max_count cho lần cuối
    max_count = max(max_count, current_count)

    # Ghi kết quả vào tệp TRANGTRI.OUT
    with open("TRANGTRI.OUT", "w") as output_file:
        output_file.write(f"{max_count}\n")

if __name__ == "__main__":
    main()
