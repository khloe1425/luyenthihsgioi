def main():
    # Đọc dữ liệu từ tệp CUASO.INP
    with open('CUASO.INP', 'r') as infile:
        n = int(infile.readline().strip())  # Đọc số lượng que
        lengths = list(map(int, infile.readline().strip().split()))  # Đọc chiều dài các que

    length_count = {}  # Đếm số lượng que theo chiều dài

    # Đếm chiều dài các que
    for length in lengths:
        if length in length_count:
            length_count[length] += 1
        else:
            length_count[length] = 1

    max_perimeter = 0
    sides = []

    # Tìm chiều dài có đủ số lượng để tạo thành cửa sổ
    for length, count in length_count.items():
        if count >= 4:
            # Có đủ 4 que để tạo hình vuông
            max_perimeter = max(max_perimeter, 4 * length)
        if count >= 2:
            # Có đủ 2 que để tạo cạnh
            sides.append(length)

    # Nếu có ít nhất 2 chiều dài, tính chu vi của hình chữ nhật lớn nhất
    if len(sides) >= 2:
        sides.sort(reverse=True)  # Sắp xếp giảm dần
        max_perimeter = max(max_perimeter, 2 * (sides[0] + sides[1]))

    # Ghi kết quả vào tệp CUASO.OUT
    with open('CUASO.OUT', 'w') as outfile:
        if max_perimeter > 0:
            outfile.write(f"{max_perimeter}\n")  # Nếu có thể ghép cửa sổ
        else:
            outfile.write("-1\n")  # Không thể ghép cửa sổ nào

if __name__ == "__main__":
    main()