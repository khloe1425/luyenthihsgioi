# Đọc dữ liệu từ file CHIAGIO.INP
with open("CHIAGIO.INP", "r") as file:
    n = int(file.readline().strip())
    hours = list(map(int, file.readline().split()))

# Tính tổng các giờ làm việc
total = sum(hours)

# Hàm kiểm tra có thể chia thành nhóm với tổng là target_sum
def can_divide_groups(target_sum):
    current_sum = 0
    groups = []
    temp_group = []
    
    for hour in hours:
        current_sum += hour
        temp_group.append(hour)
        
        if current_sum == target_sum:
            groups.append(temp_group[:])
            current_sum = 0
            temp_group = []
        elif current_sum > target_sum:
            return False, []  # Không thể chia nhóm
        
    return current_sum == 0, groups

# Tìm tổng S lớn nhất có thể chia thành nhiều nhóm nhất
max_k = 0
best_groups = []
best_sum = 0

for S in range(1, total + 1):
    if total % S == 0:
        is_possible, groups = can_divide_groups(S)
        if is_possible and len(groups) > max_k:
            max_k = len(groups)
            best_groups = groups
            best_sum = S

# Ghi kết quả ra file CHIAGIO.OUT
with open("CHIAGIO.OUT", "w") as file:
    file.write(f"{max_k} {best_sum}\n")
    for group in best_groups:
        file.write(" ".join(map(str, group)) + "\n")
