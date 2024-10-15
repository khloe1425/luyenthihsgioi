input_path = "./THCS/2024/CanTho/Bai2/MUAHE.INP"
output_path = "./THCS/2024/CanTho/Bai2/MUAHE.OUT"

def max_watered_trees(input_file, output_file):
    with open(input_file, 'r') as infile:
        # Đọc n và k
        n, k = map(int, infile.readline().strip().split())
        
        # Đọc số lít nước cần tưới cho từng cây
        water_needed = list(map(int, infile.readline().strip().split()))

    max_count = 0
    current_sum = 0
    left = 0

    for right in range(n):
        current_sum += water_needed[right]  # Thêm nước cần tưới cho cây hiện tại
        
        # Nếu tổng nước cần tưới vượt quá k, di chuyển bên trái
        while current_sum > k:
            current_sum -= water_needed[left]
            left += 1
        
        # Cập nhật số lượng cây liên tục tưới được
        max_count = max(max_count, right - left + 1)

    # Ghi kết quả vào tệp
    with open(output_file, 'w') as outfile:
        outfile.write(f"{max_count}\n")

max_watered_trees(input_path, output_path)
