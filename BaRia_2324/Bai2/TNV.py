input_path = './THCS/2024/BaRia/Bai2/TNV.INP'
output_path = './THCS/2024/BaRia/Bai2/TNV.OUT'

def main():
    with open(input_path, 'r') as file:
        n = int(file.readline().strip())  # Đọc số lượng học sinh
        heights = list(map(int, file.readline().strip().split()))  # Đọc chiều cao

    # Mảng để đếm số lượng học sinh theo chiều cao (1 đến 250)
    height_count = [0] * 251

    # Cập nhật số lượng học sinh theo chiều cao
    for height in heights:
        height_count[height] += 1

    max_count = 0
    max_height = 0

    # Tìm chiều cao có số lượng nhiều nhất
    for h in range(1, 251):
        if height_count[h] > max_count or (height_count[h] == max_count and h > max_height):
            max_count = height_count[h]
            max_height = h

    with open(output_path, 'w') as file:
        file.write(f"{max_height} {max_count}\n")

if __name__ == "__main__":
    main()
