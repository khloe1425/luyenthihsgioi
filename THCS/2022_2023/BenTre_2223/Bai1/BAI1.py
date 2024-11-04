def count_lucky_pairs(n, k, gifts):
    # Sử dụng từ điển để đếm số lượng mỗi giá trị
    count_map = {}
    for gift in gifts:
        if gift in count_map:
            count_map[gift] += 1
        else:
            count_map[gift] = 1

    lucky_pairs = 0

    # Tìm cặp thỏa mãn điều kiện |ai + aj| = K
    for ai in list(count_map.keys()):
        count_ai = count_map[ai]

        needed1 = k - ai  # ai + aj = K => aj = K - ai
        needed2 = -k - ai  # ai + aj = -K => aj = -K - ai

        # Nếu needed1 tồn tại trong map, tăng số lượng cặp
        if needed1 in count_map:
            if needed1 == ai:
                # Nếu ai == aj, thì chúng ta cần chọn 2 từ count_ai
                lucky_pairs += count_ai * (count_ai - 1) // 2
            else:
                lucky_pairs += count_ai * count_map[needed1]

        # Xử lý giá trị needed2 tương tự
        if needed2 in count_map:
            if needed2 == ai:
                lucky_pairs += count_ai * (count_ai - 1) // 2
            else:
                lucky_pairs += count_ai * count_map[needed2]

        # Đánh dấu ai để tránh đếm lại cặp đã xử lý
        del count_map[ai]

    return lucky_pairs

# Đọc dữ liệu từ file QUATANG.INP
with open("QUATANG.INP", "r") as infile:
    n, k = map(int, infile.readline().split())
    gifts = list(map(int, infile.readline().split()))

# Tính số lượng phần quà may mắn
result = count_lucky_pairs(n, k, gifts)

# Ghi kết quả ra file QUATANG.OUT
with open("QUATANG.OUT", "w") as outfile:
    outfile.write(f"{result}\n")
