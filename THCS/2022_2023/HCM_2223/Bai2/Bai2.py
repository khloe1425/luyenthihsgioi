from itertools import product

def find_all_strings(n, m, base_string, replacements):
    # Lấy tất cả tổ hợp các ký tự thay thế cho các dấu #
    combinations = product(*replacements)  # Tạo ra tất cả tổ hợp thay thế cho các dấu #

    result_list = []

    for combination in combinations:
        result = []
        hash_count = 0  # Đếm số lượng dấu #
        for i in range(n):
            if base_string[i] == '#':
                # Thay thế dấu # bằng ký tự trong tổ hợp hiện tại
                result.append(combination[hash_count])
                hash_count += 1
            else:
                # Giữ nguyên các ký tự không phải dấu #
                result.append(base_string[i])
        # Thêm chuỗi tạo ra vào danh sách kết quả
        result_list.append(''.join(result))

    # Sắp xếp tất cả các chuỗi theo thứ tự từ điển
    result_list.sort()
    return result_list

# Đọc dữ liệu đầu vào
n, m, k, x = map(int, input().split())
base_string = input().strip()

replacements = []
for _ in range(m):
    replacements.append(sorted(input().strip()))  # Lưu các ký tự thay thế sau khi sắp xếp theo thứ tự từ điển

# Tìm tất cả các chuỗi có thể thay thế
all_strings = find_all_strings(n, m, base_string, replacements)

# Xuất ra tất cả các chuỗi
for i, string in enumerate(all_strings, 1):
    print(f"{i}. {string}")
