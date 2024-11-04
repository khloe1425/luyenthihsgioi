def max_rectangle_area(N, lengths):
    count = {}  # Đếm số lượng que củi theo độ dài

    # Đếm số lượng các độ dài củi
    for length in lengths:
        if length in count:
            count[length] += 1
        else:
            count[length] = 1

    sides = []  # Lưu các độ dài có thể tạo thành cạnh

    # Lọc ra các độ dài có ít nhất 2 que
    for length, cnt in count.items():
        if cnt >= 4:
            sides.append(length)  # Nếu có >= 4 que, có thể tạo 2 cặp
        if cnt >= 2:
            sides.append(length)  # Nếu có >= 2 que, có thể tạo 1 cặp

    # Sắp xếp các độ dài
    sides.sort(reverse=True)  # Sắp xếp giảm dần

    # Tính diện tích lớn nhất
    max_area = 0
    i = 0
    while i + 1 < len(sides):
        # Tính diện tích từ 2 cạnh liền kề
        area = sides[i] * sides[i + 1]
        max_area = max(max_area, area)

        # Nếu gặp 2 cạnh bằng nhau (có thể tạo thành 2 cặp), thì bỏ qua cạnh tiếp theo
        if sides[i] == sides[i + 1]:
            i += 1  # Bỏ qua cạnh đã sử dụng
        i += 1  # Di chuyển đến cạnh tiếp theo

    return max_area

N = int(input("Nhập số nguyên N: "))
lengths = list(map(int, input("Nhập độ dài các que củi: ").split()))

result = max_rectangle_area(N, lengths)

print("Diện tích lớn nhất hình chữ nhật có thể tạo:", result)
