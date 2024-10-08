input_path = './THCS/2024/Hue/Bai3/KT.INP'
output_path = './THCS/2024/Hue/Bai3/KT.OUT'

def find_min_difference(hop_khau_trang):
    total_sum = sum(hop_khau_trang)
    n = len(hop_khau_trang)

    # Tạo mảng để lưu trữ kết quả
    dp = [[False] * (total_sum // 2 + 1) for _ in range(n + 1)]

    # Khởi tạo giá trị đầu tiên
    for i in range(n + 1):
        dp[i][0] = True

    # Điền mảng dp
    for i in range(1, n + 1):
        for j in range(1, total_sum // 2 + 1):
            if hop_khau_trang[i - 1] <= j:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - hop_khau_trang[i - 1]]
            else:
                dp[i][j] = dp[i - 1][j]

    # Tìm tổng gần nhất
    for j in range(total_sum // 2, -1, -1):
        if dp[n][j]:
            sum1 = j
            break

    sum2 = total_sum - sum1
    difference = abs(sum1 - sum2)

    return difference, sum1, sum2

# Đọc dữ liệu từ file
with open(input_path, 'r') as file:
    num_boxes = int(file.readline().strip())
    masks_in_boxes = list(map(int, file.readline().strip().split()))

# Tìm chênh lệch
difference, sum1, sum2 = find_min_difference(masks_in_boxes)

# Tạo danh sách các hộp cho từng trường
school1 = []
school2 = []
remaining_masks = sum1

# Phân chia các hộp khẩu trang cho từng trường
for mask in masks_in_boxes:
    if remaining_masks - mask >= 0:
        school1.append(mask)
        remaining_masks -= mask
    else:
        school2.append(mask)

# Ghi kết quả vào file
with open(output_path, 'w') as file:
    file.write(f"{difference}\n")
    file.write(" ".join(map(str, school1)) + "\n")
    file.write(" ".join(map(str, school2)) + "\n")
    file.write(f"{sum1} {sum2}\n")
