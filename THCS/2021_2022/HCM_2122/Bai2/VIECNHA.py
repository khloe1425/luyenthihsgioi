# Đọc dữ liệu từ file VIECNHA.INP
with open("VIECNHA.INP", "r") as file_in:
    T = int(file_in.readline().strip())  # Thời gian giới hạn
    C = int(file_in.readline().strip())  # Số lượng việc nhà

    # Danh sách thời gian cho các công việc
    tasks = [int(file_in.readline().strip()) for _ in range(C)]

# Sắp xếp thời gian các công việc theo thứ tự tăng dần
tasks.sort()

# Khởi tạo biến đếm và tổng thời gian
total_time = 0
count = 0

# Thực hiện các công việc cho đến khi hết thời gian
for task in tasks:
    if total_time + task <= T:
        total_time += task
        count += 1
    else:
        break

# Ghi kết quả ra file VIECNHA.OUT
with open("VIECNHA.OUT", "w") as file_out:
    file_out.write(str(count) + "\n")
