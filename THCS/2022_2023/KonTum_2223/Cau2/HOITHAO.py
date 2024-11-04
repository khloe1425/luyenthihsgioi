from collections import Counter

# Hàm đọc dữ liệu từ file HOITHAO.INP
def read_hoithao_inp(file_path):
    with open(file_path, 'r') as file:
        # Đọc số nguyên n
        n = int(file.readline().strip())
        # Đọc danh sách các nội dung thi đấu
        a = list(map(int, file.readline().split()))
    return n, a

# Hàm ghi kết quả vào file HOITHAO.OUT
def write_hoithao_out(file_path, distinct_count, most_common_event):
    with open(file_path, 'w') as file:
        file.write(f"{distinct_count}\n")
        file.write(f"{most_common_event}\n")

# Đường dẫn file
file_path_inp = 'HOITHAO.INP'
file_path_out = 'HOITHAO.OUT'

# Đọc dữ liệu từ file HOITHAO.INP
n, a = read_hoithao_inp(file_path_inp)

# Bước 1: Tìm số lượng nội dung thi đấu khác nhau
distinct_count = len(set(a))

# Bước 2: Tìm nội dung thi đấu có nhiều học sinh đăng ký nhất
count = Counter(a)  # Tính tần suất xuất hiện của từng nội dung
most_common_event = min([k for k, v in count.items() if v == max(count.values())])

# Ghi kết quả vào file HOITHAO.OUT
write_hoithao_out(file_path_out, distinct_count, most_common_event)
