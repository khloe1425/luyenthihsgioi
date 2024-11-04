def max_happiness(n, m, flowers):
    # Sắp xếp các loại hoa theo b_i giảm dần
    flowers.sort(key=lambda x: (x[1], x[0]), reverse=True)
    
    max_happiness = 0
    remaining_flowers = m  # Số bông hoa còn lại cần mua

    for a, b in flowers:
        if remaining_flowers <= 0:
            break
        
        # Mua 1 bông hoa loại này
        max_happiness += a
        remaining_flowers -= 1  # Giảm số bông hoa cần mua

        if remaining_flowers > 0:
            # Thêm độ vui vẻ cho những bông hoa còn lại
            max_happiness += remaining_flowers * b
            break  # Ngừng lại sau khi tính bông hoa đầu tiên

    return max_happiness

if __name__ == "__main__":
    # Đọc dữ liệu từ tệp
    with open("flow.inp", "r") as file:
        n, m = map(int, file.readline().strip().split())
        flowers = [tuple(map(int, file.readline().strip().split())) for _ in range(n)]
    
    # Tính độ vui vẻ tối đa
    result = max_happiness(n, m, flowers)

    # Ghi kết quả ra tệp
    with open("flow.out", "w") as file:
        file.write(f"{result}\n")
