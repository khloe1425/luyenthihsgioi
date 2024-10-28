# Đọc dữ liệu từ file DAY.INP
with open('DAY.INP', 'r') as file:
    n = int(file.readline().strip())  # Số công nhân
    days_worked = list(map(int, file.readline().strip().split()))  # Số ngày làm việc của mỗi công nhân

# Sắp xếp số ngày làm việc theo thứ tự giảm dần
days_worked.sort(reverse=True)

# Tính tổng số ngày làm việc
total_days = sum(days_worked)

# Tính số ngày làm việc trung bình
average_days = total_days / n

# Ghi kết quả vào file DAY.OUT
with open('DAY.OUT', 'w') as file:
    # Ghi số ngày làm việc đã sắp xếp
    file.write(' '.join(map(str, days_worked)) + '\n')
    # Ghi tổng số ngày làm việc và số ngày làm việc trung bình
    file.write(f'Tong: {total_days}; trung bình: {average_days:.2f}')
