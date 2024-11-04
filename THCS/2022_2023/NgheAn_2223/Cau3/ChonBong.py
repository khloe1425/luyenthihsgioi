def max_points(n, k, colors):
    # Đếm số lượng quả bóng theo màu
    color_count = {}
    for color in colors:
        if color in color_count:
            color_count[color] += 1
        else:
            color_count[color] = 1

    # Nếu chỉ có một màu, không thể lấy được điểm
    if len(color_count) == 1:
        return 0

    counts = sorted(color_count.values(), reverse=True)  # Sắp xếp số lượng bóng theo màu giảm dần
    max_points = 0

    # Tính điểm tối đa
    while len(counts) > 1:
        # Lấy số lượng bóng của màu có số lượng tối đa và màu có số lượng tối thiểu
        min_count = counts[-1]
        max_count = counts[0]

        # Điểm tăng thêm là 2 (mỗi lần lấy ra 2 bóng)
        max_points += 2

        # Giảm số lượng bóng đã lấy ra
        counts[0] -= 1  # Giảm màu có số lượng tối đa
        counts[-1] -= 1  # Giảm màu có số lượng tối thiểu

        # Loại bỏ màu đã hết bóng
        if counts[0] == 0:
            counts.pop(0)  # Loại bỏ màu đầu tiên
        if counts[-1] == 0:
            counts.pop()  # Loại bỏ màu cuối cùng

        # Sắp xếp lại số lượng
        counts.sort(reverse=True)

    return max_points


# Đọc dữ liệu từ tệp ChonBong.INP
with open('ChonBong.INP', 'r') as f:
    n, k = map(int, f.readline().split())
    colors = list(map(int, f.readline().split()))

# Tính điểm tối đa
result = max_points(n, k, colors)

# Ghi kết quả vào tệp ChonBong.OUT
with open('ChonBong.OUT', 'w') as f:
    f.write(str(result) + '\n')
