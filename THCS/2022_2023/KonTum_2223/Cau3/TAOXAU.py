def generate_substrings(s, m, n, start, current, result_set):
    # Nếu độ dài của current đạt m, thêm vào tập hợp
    if len(current) >= m:
        result_set.add(current)
    
    # Nếu đã đạt đến n, dừng
    if start == n:
        return
    
    # Duyệt các ký tự trong xâu
    for i in range(start, n):
        generate_substrings(s, m, n, i + 1, current + s[i], result_set)

# Hàm đọc dữ liệu từ file TAOXAU.INP
def read_taoxau_inp(file_path):
    with open(file_path, 'r') as file:
        n, m = map(int, file.readline().strip().split())
        s = file.readline().strip()
    return n, m, s

# Hàm ghi kết quả vào file TAOXAU.OUT
def write_taoxau_out(file_path, count):
    with open(file_path, 'w') as file:
        file.write(str(count) + '\n')

def main():
    # Đường dẫn file
    file_path_inp = "TAOXAU.INP"
    file_path_out = "TAOXAU.OUT"

    # Đọc dữ liệu từ file
    n, m, s = read_taoxau_inp(file_path_inp)

    # Tạo tập hợp để lưu các xâu con khác nhau
    result_set = set()
    
    # Tạo xâu con
    generate_substrings(s, m, n, 0, "", result_set)

    # Ghi kết quả vào file
    write_taoxau_out(file_path_out, len(result_set))

if __name__ == "__main__":
    main()
